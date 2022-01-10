#include "DepartmentStoreTransaction.h"
using namespace std;

DepartmentStoreTransaction::DepartmentStoreTransaction():
						   Transaction(), department_name_(""), return_policy_(0) {}

DepartmentStoreTransaction::DepartmentStoreTransaction(string transaction_date,int transaction_id,
							double transaction_amount, string department_name, int return_policy):
						   Transaction(transaction_date, transaction_id, transaction_amount),
						   department_name_(department_name), return_policy_(return_policy) {}
						   
DepartmentStoreTransaction::~DepartmentStoreTransaction() {
	cout << "\nTransaction \"Department store transaction\" destryoyer" << endl;
}

void DepartmentStoreTransaction::set_department_name(string department_name){
	department_name_=department_name;
}
void DepartmentStoreTransaction::set_return_policy(int return_policy){
	return_policy_=return_policy;
}
string DepartmentStoreTransaction::get_department_name(){
	return department_name_;
}
int DepartmentStoreTransaction::get_return_policy(){
	return return_policy_;
}


void DepartmentStoreTransaction::Display() const{
	cout << transaction_date_ << "\t" << "Department store\t"
		 << department_name_ << "\t" << return_policy_ << endl;
}
double DepartmentStoreTransaction::EarnPoints() const{
	return (transaction_amount_ * 1.5);
}
