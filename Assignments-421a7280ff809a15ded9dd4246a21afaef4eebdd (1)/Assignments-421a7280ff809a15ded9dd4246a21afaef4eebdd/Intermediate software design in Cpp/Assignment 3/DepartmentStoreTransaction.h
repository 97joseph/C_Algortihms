#ifndef DepartmentStoreTransaction_H
#define DepartmentStoreTransaction_H
#include "Transaction.cpp"
#include <iostream>

using namespace std;

class DepartmentStoreTransaction: public Transaction{
	private:
		string department_name_;
		int return_policy_;
		
	public:
		DepartmentStoreTransaction();
		DepartmentStoreTransaction(string transaction_date,int transaction_id,double transaction_amount,
								   string department_name, int return_policy);
		virtual ~DepartmentStoreTransaction();
		void set_department_name(string department_name);
		void set_return_policy(int return_policy);
		string get_department_name();
		int get_return_policy();
		virtual void Display() const;
		virtual double EarnPoints() const;
		
};

#endif
