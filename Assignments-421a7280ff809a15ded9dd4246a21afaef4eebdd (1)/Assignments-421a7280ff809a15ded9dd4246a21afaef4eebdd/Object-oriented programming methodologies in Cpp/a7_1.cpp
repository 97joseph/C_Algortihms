/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/19/2016

File name: a7_1.cpp (assignment 7, part 1)

Description: This program makes use of passing parameters by referrence
			 to display 3 sets of addition, subtraction and multiplication
			 problems. The user then sets the number of problems for each set
			 and the upper bound for the numbers that can be used in the problems
			 for each set. The program then displays each problem and receives the 
			 users answers. Finally, a report is then produced for the user displaying
			 the number and percentage correct for each set, and for all 3. This program
			 has been broken down into several functions that perform simple, specialized
			 tasks.

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//Constant declarations
const int NUM_OF_SETS = 3;
const int CENT = 100;

//Function prototypes
void getProbsPerSet( int &num_of_probs_per_set);
void printReport(int set1_number_correct, int set2_number_correct,
				 int set3_number_correct, int probsPerSet);
void doOneSet(char Operatr, int num_of_probs_per_set, int &number_correct_per_set);






/*
The main function calls on 3 functions, one of which calls on
a chain of functions that pass arguments by referrence.
The user is first asked to input the number of problems to be
displayed for each of 3 sets and the doOneSet function is called
passing in different operators each time and the variable (passed by referrence)
that holds the correct number of problems done for each set.
After the user completes all 3 sets, the printReport function is called and will display
the user's statistics for all 3 sets. It takes the variables that stored the number of
correct probllems (set1_number_correct, etc) and the number of problems per set (probsPerSet)
*/
int main() {
	
	int probsPerSet;
	int set1_number_correct = 0;//Initialized to 0 because if not they cause undefined
	int set2_number_correct = 0;//behavior.
	int set3_number_correct = 0;
	
	srand(static_cast<unsigned>(time(0))); 
	getProbsPerSet(probsPerSet);   
    doOneSet('+', probsPerSet,set1_number_correct);    
    doOneSet('-', probsPerSet,set2_number_correct);
    doOneSet('*', probsPerSet,set3_number_correct);
    printReport(set1_number_correct,set2_number_correct,set3_number_correct, probsPerSet);
}






/*
This function generates the operands(first and second numbers) for each
problem depending on the max number (maxNum) the user defined. Three variables
are passed by referrence first_num, second_num and user_ans. These variables
will store, as the variable names suggest, the first and second numbers and the
user's answer to the problem.
*/
void generateOperands(char Operatr, int &first_num,int &second_num, int &user_ans,
					  int maxNum) {
	
	first_num = rand() % (maxNum + 1);//Generates operands
	second_num = rand() % (maxNum + 1);
	
	cout << first_num << " " << Operatr << " " << second_num << " = ";
	cin >> user_ans;
}






/*
This function calculates the correct answer based on the operator,
first and second number. The switch statement determines the answer
depending on the operator and either adds, subtracts or multiplies the
2 numbers together ("first_num" and "second_num")
to get the actual answer. The "actual_ans" parameter is passed by reference so the
function can assign the correct answer to it for use in other variables.
*/
void calculateCorrectAnswer(char Operatr, int &actual_ans,int first_num,int second_num) {
	
	switch (Operatr) {
		
		case '+':
			actual_ans = first_num + second_num;
			break;
			
		case '-':
			actual_ans = first_num - second_num;
			break;
			
		case '*':
			actual_ans = first_num * second_num;
			break;
	}
}






/*
The checkAnswer function checks if the correct answer (actual_ans)
matches the user's answer (user_ans) and displays the message accordingly
while adding giving the user a point or making the score variable, that's
passed by reference, equal to 0.
*/
void checkAnswer(int actual_ans, int user_ans, int &score) {

	if (actual_ans == user_ans) {
		cout << "Correct" << endl;
		score = 1;
	}
	
	else {
		cout << "Incorrect" << endl;
		score = 0; //To ensure that this variable stores a
				   //number if the user doesn't get any answer right.
	}
}






/*
This functions asks the user to input
the largest number to be used for the problems in each set.
This numer will be stored in the maxNum variable that's passed
by reference into the parameter.
*/
void getMaxNum(int &maxNum) {
	cout << "What is the maximum number for this set? ";
	cin >>  maxNum;
}






/*
This function is called inside the doOneSet function for as many times
as the user wants for each of the 3 sets. Three other functions are called
inside for each problem that is displayed and the score for the problem
is added to the score for each set since the sumTotal_score variable is
passed by referrence. The operator character (Operatr), maxNum and "sumTotal_score"
variables are passed into the parameter, the latter is passed by reference so it can
the total score for the set can be summed up.
*/
void doOneProblem(char Operatr, int maxNum, int &sumTotal_score) {
	int num1;
	int num2;
	int user_answer;
	int actual_answer;
	int score_for_problem;
	
	generateOperands(Operatr, num1, num2, user_answer, maxNum);
	calculateCorrectAnswer( Operatr, actual_answer, num1, num2);
	checkAnswer(actual_answer, user_answer,  score_for_problem);
	sumTotal_score = score_for_problem;
}






/*
This function prints the header for each of three sets.
Since the first 3 functions are called in main in the order
'+', '-' and '*'. The switch statement takes the "Operatr" variable
passed in through the function parameter to decide which header
to print.
*/
void printHeader(char Operatr) {
	
	switch (Operatr) {
		
		case '+':
			cout << "Set #1\n----------\n";
			break;
			
		case '-':
			cout << "Set #2\n----------\n";
			break;
			
		case '*':
			cout << "Set # 3\n----------\n";
			break;			
	}
}







/*
This function takes 3 parameter, one passed by reference(number_correct_per_set)
so the variable could be used in the printReport function.
The "Operatr" variable is passed in to the printHeader and the doOneProblem functions.
The getMaxNum function asks the user for input every set, and passes the maxNum variable
to the doOneProblem function call, the number of problems done correctly will be counted.
*/
void doOneSet(char Operatr, int num_of_probs_per_set, int &number_correct_per_set) {
	
	int i;
	int maxNum;
	int score_for_set;
	
	printHeader(Operatr);
	getMaxNum(maxNum);
	for (i = 0; i < num_of_probs_per_set; i++) {
		doOneProblem(Operatr, maxNum, score_for_set);
		number_correct_per_set += score_for_set;
	}
	cout << "\n";
}






/*
The user is asked, in this function, to enter
the number of problems to be displayed in each set.
The vairable in the parameter(num_of_probs_per_set)
is passed by reference so the variable can be used in
other function calls in "main".
*/
void getProbsPerSet(int &num_of_probs_per_set) {
	
	cout << "Enter problems per set: ";
	cin >> num_of_probs_per_set;
	cout << "\n\n";
}






/*
This is the final function used in the program and is called
at the end of the program to display the user's "report".
Percentages for the number of correct problems solved in each
set are calculated in separate variables for each set, passed in
from the parameter, ( set1_number_correct, etc) and the "probsPerSet" variable.
The percentages and the total score are stored in separate variables.
These variables are then used to output the numbers and percentages
correct for each set.
*/
void printReport(int set1_number_correct, int set2_number_correct,
				 int set3_number_correct, int probsPerSet) {
	int total_score;//14 lines not including whitespace or declarations.
	int total_problems;
	double set1_percent_correct;
	double set2_percent_correct;
	double set3_percent_correct;
	double allSets_percent_correct;
	
	total_problems = probsPerSet * NUM_OF_SETS;
	total_score = set1_number_correct + set2_number_correct + set3_number_correct;
	set1_percent_correct = ((double)set1_number_correct / probsPerSet) * CENT;
	set2_percent_correct = ((double)set2_number_correct / probsPerSet) * CENT;
	set3_percent_correct = ((double)set3_number_correct / probsPerSet) * CENT;
	allSets_percent_correct = ((double)total_score / total_problems) * CENT;
	
	cout << "Set#1: You got " << set1_number_correct << " correct out of " << probsPerSet
		 << " for " << fixed << setprecision(1) << set1_percent_correct  << "%" << endl;
		 
	cout << "Set#2: You got " << set2_number_correct << " correct out of " << probsPerSet
		 << " for " << fixed << setprecision(1) << set2_percent_correct << "%" << endl;
	
	cout << "Set#3: You got " << set3_number_correct << " correct out of " << probsPerSet
		 << " for " << fixed << setprecision(1) << set3_percent_correct << "%" << endl;
		 
	cout << "Overall you got " << total_score << " correct out of " << total_problems
	 	 << " for "  << fixed << setprecision(1) << allSets_percent_correct << "%" << endl;
}


/*
Output:

Enter problems per set: 3


Set #1
----------
What is the maximum number for this set? 50
6 + 37 = 43
Correct
34 + 48 = 3
Incorrect
50 + 11 = 3
Incorrect

Set #2
----------
What is the maximum number for this set? 78
64 - 5 = 59
Correct
27 - 29 = -2
Correct
65 - 26 = 29
Incorrect

Set # 3
----------
What is the maximum number for this set? 5
1 * 0 = 0
Correct
2 * 3 = 6
Correct
2 * 0 = 0
Correct

Set#1: You got 1 correct out of 3 for 33.3%
Set#2: You got 2 correct out of 3 for 66.7%
Set#3: You got 3 correct out of 3 for 100.0%
Overall you got 6 correct out of 9 for 66.7%
*/
