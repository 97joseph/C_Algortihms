#ifndef BankingTransaction_H
#define BankingTransaction_H
#include "Transaction.cpp"
#include <iostream>
using namespace std;


class BankingTransaction: public Transaction{
	
	private:
		double fee_charge_;
		string transaction_type_;
		
	public:
		BankingTransaction();
		BankingTransaction(string transaction_date,int transaction_id,double transaction_amount,
						   double fee_charge, string transaction_type);
		virtual ~BankingTransaction();
		void set_fee_charge(double fee_charge);
		void set_transaction_type(string transaction_type);
		double get_fee_charge();
		string get_transaction_type();
		virtual void Display() const;
		virtual double EarnPoints() const;
};
#endif
