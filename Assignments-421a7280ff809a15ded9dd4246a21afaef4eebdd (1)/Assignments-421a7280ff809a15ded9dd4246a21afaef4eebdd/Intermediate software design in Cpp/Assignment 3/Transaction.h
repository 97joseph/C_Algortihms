#ifndef Transaction_H
#define Transaction_H
#include "DepartmentStoreTransaction.cpp"
#include "BankingTransaction.cpp"
#include "GroceryTransaction.cpp"
#include <iostream>

using namespace std;

class Transaction{
	
	protected:
		string transaction_date_;
		int transaction_id_;
		double transaction_amount_;
	public:
		Transaction();
		Transaction(string transaction_date, int transaction_id, double transaction_amount );
		virtual ~Transaction();
		virtual void Display() const = 0;
		virtual double EarnPoints() const = 0;
		bool operator== (const Transaction & transaction_2) const;
		string get_transaction_date() const;
		int get_transaction_id() const;
		double get_transaction_amount() const;
		void set_transaction_date(string transaction_date);
		void set_transaction_id(int transaction_id);
		void set_transaction_amount(double transaction_amount);
		
};

#endif
