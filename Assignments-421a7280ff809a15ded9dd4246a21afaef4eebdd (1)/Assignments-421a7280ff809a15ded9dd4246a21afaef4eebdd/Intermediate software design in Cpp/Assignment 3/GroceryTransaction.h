#ifndef GroceryTransaction_H
#define GroceryTransaction_H
#include "Transaction.cpp"
#include <iostream>
using namespace std;

class GroceryTransaction: public Transaction{
	private:
		string store_name_;
		
	public:
		GroceryTransaction();
		GroceryTransaction(string transaction_date,int transaction_id,double transaction_amount,
						   string store_name);
		virtual ~GroceryTransaction();
		void set_store_name(string store_name);
		string get_store_name();
		virtual void Display() const;
		virtual double EarnPoints() const;
		
};

#endif
