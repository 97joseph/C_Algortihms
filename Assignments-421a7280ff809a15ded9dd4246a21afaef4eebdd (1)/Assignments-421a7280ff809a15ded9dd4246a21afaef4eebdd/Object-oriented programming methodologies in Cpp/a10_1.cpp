/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/2016

File name: a10_1.cpp (assignment 10, part 1)

Description: This program reads a list of numbers and
			 finds distinct numbers within the list
			 and stores these numbers in an array. Up to 1000
			 distinct numbers can be stored in the array. Three separate
			 functions, not including the main function, are implemented to
			 create this program.
*/
#include <iostream>
using namespace std;





//Constant declaration
const int ARRAY_SIZE = 1000;

//Prototypes
bool isInArray(int number_input, int number_of_items, int List[]);
void readToList(int List[],int &number_of_items);
void print(int List[], int number_of_items);





/*
The main function declares an array named list and an int variable
that stores the number of items, the integer variable and array are
passed by reference into both the readToList and  print functions.
*/
int main() {
    
    int number_of_items;
    int list[ARRAY_SIZE];

    readToList( list, number_of_items);
    print(list, number_of_items);

	return 0;
}






/*
This funtion takes 3 arguments. The "number_input" variable that stores
the number inputted by the user, the "number_of_elements" which is stores how
many elements are in the array and "List" to which an array would be passed by
referrence. "The number_of_elements" variable tells the for loop how many times
to iterate/the number of elements to compare. If the element in the array matches
the number stored in the "number_input" variable then the function returns true,
if no matches are found, the function returns false.
*/
bool isInArray(int number_input, int number_of_elements, int List[]){
	int count;
	
	for (count = 0; count < number_of_elements; count++){
		if (List[count] == number_input) {
			return true;
		}
	}
	return false;
}






/*
This functions takes 2 arguments, an array "List" and an integer variabe "number_of_items"
in the function parameter both of which are passed by referrence. The user is asked to input
an non-negative integer (or a negative integer to quit) before the loop iterates since the
user has the option to not enter any numbers into the list at all. Once the while loop iterates
an if statement with a function call to "isInArray", as a condition, is used to check if the
number inputted by the user exists in the array and will return a boolean value accordingly.
The "number_of_items" variable is also incremented to be used in the "print" and "isInArray"
functions. At the end of the loop the user is asked again if they want to input a number/quit.
*/
void readToList(int List[],int &number_of_items){
	
	int count;
	int number_input;
		
	number_of_items = 0;

    cout << "Enter a non-negative integer (negative to quit): ";
    cin >> number_input;
    
    while (number_input >= 0){
    	
    	if ( !isInArray(number_input, number_of_items, List) ) {
    		List[number_of_items] = number_input;
    		number_of_items++;
		}

        cout << "Enter a non-negative integer (negative to quit): ";    
        cin >> number_input;
    }
}






/*
This function takes 2 arguments an array -"List" and an integer variable "number_of_items"
to display to the user the distinct number they have entered. The "number_of_items" variables
is used in the for loop as the upper bound to iterate to so all the elements in the list can
be displayed.
*/
void print(int List[], int number_of_items){
	int count;
	
	cout << "You entered:" << endl;
	
	for(count = 0; count < number_of_items; count++){
		cout << List[count] << " ";
	}
}


/*
Output:
Enter a number (negative number to quit): 1
Enter a number (negative number to quit): 2
Enter a number (negative number to quit): 3
Enter a number (negative number to quit): 2
Enter a number (negative number to quit): 1
Enter a number (negative number to quit): 6
Enter a number (negative number to quit): 3
Enter a number (negative number to quit): 4
Enter a number (negative number to quit): 5
Enter a number (negative number to quit): 2
Enter a number (negative number to quit): -4
You entered:
1 2 3 6 4 5
*/
