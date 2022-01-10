#ifndef Customer_H
#define Customer_H
#include "Transaction.cpp"
#include <iostream>

using namespace std;

class Customer{
	public:
		static const int g_kSize=16;
		Customer();
		Customer(string customer_name, string credid_card_number, double transaction_balance);
		~Customer();
		void ReadTransactions();
		void ReportAllTransactions();
		void ReportRewardSummary();
		
	private:
		string customer_name_;
		string credit_card_number_;
		double transaction_balance_;
		int reward_points_total_;
		Transaction * transaction_list[g_kSize];
		
	
	
};

#endif
