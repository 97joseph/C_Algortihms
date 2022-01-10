#include "Customer.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

Customer::Customer(): customer_name_(""), credit_card_number_(""), transaction_balance_(0),
					 reward_points_total_(1000)//Default to 1000 points
{
	for(int i=0; i<g_kSize; i++){
		transaction_list[i]=NULL;
	}	
}

Customer::Customer(string customer_name, string credit_card_number, double transaction_balance):
				   customer_name_(customer_name), credit_card_number_(credit_card_number),
				   transaction_balance_(transaction_balance), reward_points_total_(1000)//Default to 1000 points
{
	for(int i=0; i<g_kSize; i++){
		transaction_list[i]=NULL;
	}
}

Customer::~Customer(){
	for(int i=0; i<g_kSize; i++){
		delete transaction_list[i];
	}	
}

void Customer::ReadTransactions(){
	
	ifstream transaction_file;
	string buffer;
	char transaction_type;
	string date;
	int id;
	double amount;
	string transaction_specific_data_location_name;//This transaction specific data is used for 2 transaction types D and G
												   //since they both have a location name (department name, store name) 
	int transaction_specific_data_return_policy;
	string transaction_specific_data_BankingTransaction_type;
	double transaction_specific_data_fee_charge;
	int count;
	
	transaction_file.open("transaction_info.txt");
		
		if (!transaction_file) {
			cout << "couldn't open file." << endl;
			exit(-1);
		}
		
		else {
			count=0;
		    while (getline(transaction_file,buffer,'~')){
		    	transaction_type=buffer[0];//Because this string is a single letter so the index position has been used
		    	
			    getline(transaction_file,buffer,'~');
			    date= buffer;
			    
			    getline(transaction_file,buffer,'~');
			    id = atol(buffer.c_str());//this line for int

				getline(transaction_file,buffer,'~');
			    amount = atof(buffer.c_str());//this line for double
				
				getline(transaction_file,buffer,'~');
			    transaction_specific_data_location_name= buffer;
			   
				
				
				switch (transaction_type){
					case 'D':						
						getline(transaction_file,buffer,'\n');
						transaction_specific_data_return_policy= atol(buffer.c_str());
						
						transaction_list[count] = new DepartmentStoreTransaction(date,id,amount,
																				 transaction_specific_data_location_name,
																				 transaction_specific_data_return_policy);
						break;
					case 'B':
						transaction_list[count] = new BankingTransaction(date,id,amount,
																		 transaction_specific_data_fee_charge,
																		 transaction_specific_data_BankingTransaction_type);
						break;
				
					case 'G':
						transaction_list[count] = new GroceryTransaction(date,id,amount,
																		 transaction_specific_data_location_name);
						break;
						
				}     

		        count++;
    		}	
		}
	transaction_file.close();
}
void Customer::ReportAllTransactions(){
	for(int i=0;i<g_kSize; i++){
		if(transaction_list[i]!=NULL){
			transaction_list[i]->Display();
		}
		
	}
}
void Customer::ReportRewardSummary(){
	cout << "";
}
