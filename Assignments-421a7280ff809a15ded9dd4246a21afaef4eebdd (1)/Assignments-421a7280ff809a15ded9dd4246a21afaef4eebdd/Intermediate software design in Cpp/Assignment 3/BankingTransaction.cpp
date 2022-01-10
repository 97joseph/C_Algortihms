#include "BankingTransaction.h"
#include <iostream>
#include <cstdlib>

using namespace std;

BankingTransaction::BankingTransaction(): fee_charge_(0), transaction_type_(""){}

BankingTransaction::BankingTransaction(string transaction_date,int transaction_id,double transaction_amount,
						   			    double fee_charge, string transaction_type):
										Transaction(transaction_date,transaction_id,transaction_amount),
										fee_charge_(fee_charge), transaction_type_(""){}
										
BankingTransaction::~BankingTransaction(){
	cout << "\nTransaction \"Banking transaction\" destroyed" <<endl;
}

void BankingTransaction::set_fee_charge(double fee_charge){
	fee_charge_=fee_charge;
}
void BankingTransaction::set_transaction_type(string transaction_type){
	transaction_type_=transaction_type;
}

double BankingTransaction::get_fee_charge(){
	return fee_charge_;
}

string BankingTransaction::get_transaction_type(){
	return transaction_type_;
}

void BankingTransaction::Display() const{

	cout << transaction_date_ << "\t" << "Banking\t"
		 << transaction_type_ << " withdraw $"<< fee_charge_ << "\t" << transaction_amount_ << endl;
}
	
double BankingTransaction::EarnPoints() const{
	return 0;
}
