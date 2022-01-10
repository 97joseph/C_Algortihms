#include <iostream>

using namespace std;


int main() {

	int num_of_pounds, num_of_ounces;
	
	cout << "Enter pounds: ";
	cin >> num_of_pounds;
	
	num_of_ounces= num_of_pounds * 16;
	
	cout << num_of_pounds << " pounds is "
		 << num_of_ounces << " ounces." << endl;
	
	
	system("pause");
	return 0;
}


/*
Output:
Enter pounds: 5
5 pounds is 80 ounces.


*/
