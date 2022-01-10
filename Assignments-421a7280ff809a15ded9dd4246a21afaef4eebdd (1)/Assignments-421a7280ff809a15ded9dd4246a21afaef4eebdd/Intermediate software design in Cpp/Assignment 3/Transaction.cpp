#include "Transaction.h"

using namespace std;

//Constructors and destructor------------------------------------------
Transaction::Transaction(): transaction_date_("1/1/2000"), transaction_id_(0), transaction_amount_(0.0){}

Transaction::Transaction(string transaction_date,int transaction_id, double transaction_amount):
	transaction_date_(transaction_date), transaction_id_(transaction_id), transaction_amount_(transaction_amount){}
	
Transaction::~Transaction(){
	cout << "Transaction " << transaction_id_ << " destroyed..." << endl;
}


//Operator overload----------------------------------------------------
bool Transaction::operator== (const Transaction & transaction_2) const{

	return ((transaction_date_ == transaction_2.transaction_date_) and
			(transaction_amount_ == transaction_2.transaction_amount_));
}


//Accessors------------------------------------------------------------
string Transaction::get_transaction_date() const{
	return transaction_date_;
}
int Transaction::get_transaction_id() const{
	return transaction_id_;
}
double Transaction::get_transaction_amount() const{
	return transaction_amount_;
}


//Mutators----------------------------------------------------------------
void Transaction::set_transaction_date(string transaction_date){
	transaction_date_=transaction_date;
}
void Transaction::set_transaction_id(int transaction_id){
	transaction_id_=transaction_id;
}
void Transaction::set_transaction_amount(double transaction_amount){
	transaction_amount_=transaction_amount;
}
