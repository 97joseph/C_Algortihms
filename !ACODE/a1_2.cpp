/*

Name: Dillon Pinto

Class: CS 2C

Date: 10/3/2016

File name: a1_2.cpp (assignment 1, part 2)

Description: This program uses the subset-sum problem and creates
			 sublists of songs/playlist that have a total time in seconds
			 close to or equal to the target time in seconds, 
			 which in this case is 3600s. Sublists consist of iTunesEntry
			 objects with play times that sum to less than or equal to 
			 the target. The subsets grow until a subset that meets the target.

*/

#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "iTunes.cpp"
#include "time.h"

using namespace std;





//Class declarations and implementation

/*
	This class creates objects that act as sublists
	for use in the subset-sum problem program. It stores indices
	of iTunesEntry objects in the data set whose sum of play times will add up to
	at most, the value of the target. There are 3 private members. Two vectors
	one that is a pointer to the data set vector of iTunesEntry objects and another that
	holds the inidices of the objects in the data set. 
	It also has a sum member variable that holds the total sum of all play times of all 
	songs in the sublist.

	Sublist(vector<iTunesEntry> *orig = NULL) : sumOfTimes(0), originalObjects (orig) { }
	pre-conditions: Integer vector "orig" should contains a set of iTunesEntry objects.
	post-conditions: The member variable "sumOfTimes" will be intialized to 0 and
					 originalObjects will point to the data set.
	
	Sublist addItem( int indexOfItemToAdd );
	pre-conditions: "indexOfItemToAdd" should be a number from 0
					 to the last index in the data set vector.
	post-conditions: A copy of the calling object is made with
					 a modified indices vector and sumOfTimes value.
	
	void showSublist() const;
	pre-conditions: Indices need to be stored in the indices vector
					to display their corresponding values.
	post-conditions: Displays values of the subset. That display
					 title, artist and play time.
	
	int getSumOfTimes() const { return sumOfTimes; }
	post-conditions: Returns the sum of play times held in the sumOfTimes
					 member variable     
*/
					 
					                    
class Sublist {
	public:
	   Sublist(vector<iTunesEntry> *orig = NULL) : sumOfTimes(0), originalObjects (orig) {}
	   Sublist addItem( int indexOfItemToAdd );
	   void showSublist() const;
	   int getSumOfTimes() const { return sumOfTimes; }
	
	private:
	   int sumOfTimes;
	   vector<iTunesEntry> *originalObjects;
	   vector<int> indices;
};

Sublist Sublist::addItem(int indexOfItemToAdd){
	Sublist sub2 = *this;
	sub2.indices.push_back(indexOfItemToAdd);
	sub2.sumOfTimes = sumOfTimes + (originalObjects->at(indexOfItemToAdd)).getTime();
	return sub2;
}


void Sublist::showSublist() const{
	vector<int>::const_iterator iter;
	int i=0;
	iTunesEntry Entry;
	for(iter =indices.begin();iter != indices.end();iter++){
		Entry = originalObjects->at(*iter);
		cout << "array[" << i << "] = " << Entry.getTitle()
			 << " by " << Entry.getArtist() << "("
			 << Entry.getTime() << ")";

		cout << "\n\n";
		i++;
		}
		
	
}





int main()
{
   const int TARGET = 3600;
   vector<iTunesEntry> dataSet;
   vector<Sublist> choices;
   vector<Sublist>::iterator iter;
   int i, j, sumOfTimes, maxSumOfTimes, array_size, choices_size;
   float totalTime;
   bool foundPerfect;

   // read the data
   iTunesEntryReader tunes_input("itunes_file.txt");
   if (tunes_input.readError())
   {
      cout << "couldn't open " << tunes_input.getFileName() 
         << " for input.\n";
      exit(1);
   }

   // time the algorithm -------------------------
   clock_t startTime, stopTime; 
   startTime = clock();

   // create a vector of objects for our own use:
   array_size = tunes_input.getNumTunes();
   for (int k = 0; k < array_size; k++)
      dataSet.push_back(tunes_input[k]);

   cout << "Target time: " << TARGET << endl;
   
   
   
	Sublist sublist(&dataSet);
	choices.push_back(sublist);
	Sublist sublist2;
	Sublist maxSublist;
	foundPerfect = false;
	maxSumOfTimes=0;
	
	//Algorithm takes about .058  seconds to complete
	for(i = 0; i < dataSet.size(); i++){
		choices_size = choices.size();
		for(j = 0; j < choices_size; j++){
			
			sublist2 = choices[j].addItem(i);
			
			sumOfTimes=sublist2.getSumOfTimes();
		
			
			if (sumOfTimes < TARGET){
				choices.push_back(sublist2);
			
				if (sumOfTimes > maxSumOfTimes){
					maxSumOfTimes=sumOfTimes;
					maxSublist = sublist2;
				}
			}
			
			else if (sumOfTimes == TARGET){
				foundPerfect = true;
				maxSublist = sublist2;
				break;
			}
		
		}
		if (foundPerfect){
			break;
		}
		
		stopTime = clock();
		totalTime = ((double)(stopTime-startTime)/(double)(CLOCKS_PER_SEC));
			
		
	}
   
	cout << "Sum: " << maxSublist.getSumOfTimes() << endl;
	maxSublist.showSublist();
	cout << "Algorithm elapsed time: " << totalTime << " seconds";
   return 0; 
}


