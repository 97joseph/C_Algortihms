#include <iostream>
#include <cstdlib>
#include "GroceryTransaction.h"

using namespace std;

GroceryTransaction::GroceryTransaction():store_name_(""){}

GroceryTransaction::GroceryTransaction(string transaction_date,int transaction_id,double transaction_amount,
									   string store_name):
									   Transaction(transaction_date, transaction_id, transaction_amount),
									   store_name_(store_name){}

GroceryTransaction::~GroceryTransaction(){
	cout << "\nTransaction \"Grocery transaction\" destroyed" << endl;
}


void GroceryTransaction::set_store_name(string store_name){
	store_name_=store_name;
}
string GroceryTransaction::get_store_name(){
	return store_name_;
}

void GroceryTransaction::Display() const{
	cout << transaction_date_ << "\t" << "Grocery\t"
		 << store_name_ << "\t" << transaction_amount_ << endl;
}

double GroceryTransaction::EarnPoints() const{
	return (transaction_amount_ * 2.5);
}
