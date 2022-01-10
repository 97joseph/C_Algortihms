
/*
Description: This program uses the subset-sum problem and creates
			 sublists of integers that add up to at most the value
			 of the target or the closest sum combination possible.

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;






//Class declarations and implementation
/*
	This class creates objects that act as sublists
	for use in the subset-sum problem program. It stores indices
	of numbers in the data set that will sum up to at most - the
	value of the target. There are 3 private members. Two vectors
	one that is a pointer to the data set vector of integers and another that
	holds the inidices. It also has a sum member variable that holds the total
	integer sum of all the numbers in the sublist.

	Sublist(vector<int> *orig = NULL) : sum(0), originalObjects (orig) { }
	pre-conditions: Integer vector "orig" should contains a set of integers.
	post-conditions: The member variable "sum" will be intialized to 0 and
					 originalObjects will point to the data set.
	
	Sublist addItem( int indexOfItemToAdd );
	pre-conditions: "indexOfItemToAdd" should be a number from 0
					 to the last index in the data set vector.
	post-conditions: A copy of the calling object is made with
					 a modified indices vector and sum.
	
	void showSublist() const;
	pre-conditions: Indices need to be stored in the indices vector
					to display their corresponding values.
	post-conditions: Displays values of the subset
	
	int getSum() const { return sum; }
	post-conditions: Returns the sum of values held in the sum
					 member variable
					 
					 


*/
                           
class Sublist {
	public:
	   Sublist(vector<int> *orig = NULL) : sum(0), originalObjects (orig) { }
	   Sublist addItem( int indexOfItemToAdd );
	   void showSublist() const;
	   int getSum() const { return sum; }
	
	private:
	   int sum;
	   vector<int> *originalObjects;
	   vector<int> indices;
};

//Makes a copy of the calling object and appends
//the new index to the indices vector.
//the sum of the calling object is added to the 
//value that corresponds to the index added this is assigned to
//the sum member variable of the copied object and the object is then returned.
Sublist Sublist::addItem(int indexOfItemToAdd){
	Sublist sub2 = *this;
	sub2.indices.push_back(indexOfItemToAdd);
	sub2.sum=sum + (originalObjects->at(indexOfItemToAdd));
	return sub2;
}


void Sublist::showSublist() const{
	vector<int>::const_iterator iter;
	int i=0;
	
	for(iter =indices.begin();iter != indices.end();iter++){
		
		cout << "array[" << i << "] = " << originalObjects->at(*iter) << "\n";
		i++;
	}
}

//-------------------------------------------------------------------------------------------






int main(){
	int TARGET = 180;
    vector<int> dataSet;//S
    vector<Sublist> choices;//Col
    vector<int>::iterator sIter;//iterator for the 'S' set of numbers/dataSet
    vector<Sublist>::iterator iter;//iterator arnd iterator to find best sublist
    int i, j, choices_size, maxSum, sum;
    bool foundPerfect;
    
    dataSet.push_back(20);
    dataSet.push_back(12);
    dataSet.push_back(22);
    dataSet.push_back(15);
    dataSet.push_back(25);
    dataSet.push_back(19);
    dataSet.push_back(29);
    dataSet.push_back(18);
    dataSet.push_back(11);
    dataSet.push_back(13);
    dataSet.push_back(17);
	
    choices.clear();
   cout << "Target time: " << TARGET
    	 << "\nSublist-----------------------------" << endl;
    
    
	Sublist sublist(&dataSet);
	choices.push_back(sublist);
	Sublist sublist2;
	Sublist maxSublist;
	foundPerfect = false;
	maxSum=0;
	
	
	//Took 2*10^-6 seconds
	for(i = 0; i < dataSet.size(); i++){
		choices_size = choices.size();
		for(j = 0; j < choices_size; j++){
			
			sublist2 = choices[j].addItem(i);
			sum=sublist2.getSum();
		
			
			if (sum < TARGET){
				choices.push_back(sublist2);
				if (sum > maxSum){
					maxSum=sum;
					maxSublist = sublist2;
				}
			}
			
			else if (sum == TARGET){
				foundPerfect = true;
				maxSublist = sublist2;
				break;
			}
			
		}
		
		if (foundPerfect){
			break;
		}
			
		
	}

	for(iter=choices.begin(); iter != choices.end(); iter++){
		cout << iter;
	}

	cout << "Sum: " << maxSublist.getSum() << endl;
	maxSublist.showSublist();

}







//TOOK .001425 SECONDS
foundPerfect=false;
	maxSum=0;
	start=clock();
	//Algorithm executes at an average of 2*10^-6 seconds
	for(i = 0; i < dataSet.size(); i++){
		choices_size = choices.size();
		for(j = 0; j < choices_size; j++){
			
			sublist2 = choices.at(j).addItem(i);
			sum=sublist2.getSum();
		
			
			if (sum <= TARGET){
				choices.push_back(sublist2);
			}
			
			else if (sum == TARGET){
				foundPerfect = true;
				break;
			}
			
		if (foundPerfect){
			break;
		}
			
		}
	}
	
	choices_size = choices.size();
	for(j = 0; j < choices_size; j++){
		sublist2 = choices.at(j);
		sum = sublist2.getSum();
		if (sum > maxSum){
			maxSum = sum;
			maxSublist = sublist2;
			if(maxSum==TARGET){
				break;
			}	
		}
	}
