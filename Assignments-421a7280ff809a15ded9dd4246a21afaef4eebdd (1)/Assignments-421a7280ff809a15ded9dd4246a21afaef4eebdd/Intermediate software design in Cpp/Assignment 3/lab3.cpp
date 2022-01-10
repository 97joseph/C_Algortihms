#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;
/*
Purpose: This program reports customer credit card purchases by the month. The program makes use 
		 of multiple classes, inheritance, polymorphism and operator overloading. There are 3 separate
		 reports implemented in this program, a transaction listing, a reward summary and a duplicate
		 transaction report.
		 
History: 
	    7/20/16: Created all header files and declared classes, member data and functions
	    7/21/16: Created and defined all functions in implementation files
	    7/23/16: Merged all files into a single file, due to compiling errors.
	    7/25/16: Implemented extra credit "ReportDuplicateTransactions" member function in Customer class. Debugged the
	    		 source code.
	    
*/

class Transaction{
	
	protected:
		string transaction_date_;
		int transaction_id_;
		double transaction_amount_;
	public:
		Transaction();
		Transaction(string transaction_date,int transaction_id, double transaction_amount );
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







DepartmentStoreTransaction::DepartmentStoreTransaction():
						   Transaction(), department_name_(""), return_policy_(0) {}
						   
						   
						   
						

DepartmentStoreTransaction::DepartmentStoreTransaction(string transaction_date,int transaction_id,
							double transaction_amount, string department_name, int return_policy):
						   Transaction(transaction_date, transaction_id, transaction_amount),
						   department_name_(department_name), return_policy_(return_policy) {}
						   
						   
						   
						   

						   
DepartmentStoreTransaction::~DepartmentStoreTransaction() {
	cout << "\nTransaction \"Department store transaction\" destroyed" << endl;
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
		 << department_name_ << ", Return in " << return_policy_ 
		 <<" days\t\t$" << fixed << setprecision(2) << transaction_amount_ << endl;
}





double DepartmentStoreTransaction::EarnPoints() const{
	return (transaction_amount_ * 1.5);
}








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







BankingTransaction::BankingTransaction(): fee_charge_(0), transaction_type_(""){}






BankingTransaction::BankingTransaction(string transaction_date,int transaction_id,double transaction_amount,
						   			    double fee_charge, string transaction_type):
						   			    	
										Transaction(transaction_date,transaction_id,transaction_amount),
										fee_charge_(fee_charge), transaction_type_(transaction_type){}
						
						
						
						
						
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
	
	cout << transaction_date_ << "\t" << "Banking\t\t\t" << fixed << setprecision(2)
		 << transaction_type_ << " withdraw, fee charge: $"<< fee_charge_ << "\t$" << transaction_amount_ << endl;
}
	
double BankingTransaction::EarnPoints() const{
	return 0;
}





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
	cout << transaction_date_ << "\t" << "Grocery\t\t\t"
		 << store_name_ << "\t\t\t\t\t$" << setprecision(2) << transaction_amount_ << endl;
}





double GroceryTransaction::EarnPoints() const{
	return (transaction_amount_ * 2.5);
}






class Customer{
	public:
		static const int g_kSize=16;
		Customer();
		Customer(string customer_name, string credit_card_number, double transaction_balance);
		~Customer();
		void ReadTransactions();
		void ReportAllTransactions();
		void ReportRewardSummary();
		void ReportDuplicateTransactions();
		
	private:
		string customer_name_;
		string credit_card_number_;
		double transaction_balance_;
		int reward_points_total_;
		Transaction * transaction_list[g_kSize];
		
	
	
};







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
			
				
				
				switch (transaction_type){
					case 'D':						
						getline(transaction_file,buffer,'~');
			    		transaction_specific_data_location_name= buffer;
			    		
						getline(transaction_file,buffer,'\n');
						transaction_specific_data_return_policy= atol(buffer.c_str());
						
						transaction_list[count] = new DepartmentStoreTransaction(date,id,amount,
																				 transaction_specific_data_location_name,
																				 transaction_specific_data_return_policy);
						break;
						
						
					case 'B':
						getline(transaction_file,buffer,'~');
			    		transaction_specific_data_BankingTransaction_type= buffer;
			    		
			    		getline(transaction_file,buffer,'\n');
			    		transaction_specific_data_fee_charge = atof(buffer.c_str());
			    		
			    		
						transaction_list[count] = new BankingTransaction(date,id,amount,
																		 transaction_specific_data_fee_charge,
																		 transaction_specific_data_BankingTransaction_type);
						break;
				
					case 'G':
						getline(transaction_file,buffer,'\n');
			    		transaction_specific_data_location_name= buffer;
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
	
	DepartmentStoreTransaction * department_store_transaction = NULL;
	BankingTransaction * banking_transaction=NULL;
	GroceryTransaction * grocery_transaction=NULL;
	double total_transaction_amount = 0;
	double total_fee_charge = 0;
	int banking_count = 0;
	int department_store_count = 0;
	int gorcery_count = 0;
	double department_store_total=0;
	double banking_total = 0;
	double grocery_total = 0;
	
	cout <<"\t\tTransaction listings\n" << endl;
	
	for(int i=0;i<g_kSize; i++){
		if(transaction_list[i]!=NULL){
			transaction_list[i]->Display();
			total_transaction_amount += transaction_list[i]->get_transaction_amount();
			
			if((banking_transaction = dynamic_cast<BankingTransaction *>(transaction_list[i]))!=NULL){
				total_fee_charge +=banking_transaction->get_fee_charge();
				banking_total +=banking_transaction->get_transaction_amount();
				banking_count++;
			}
			
			else if((department_store_transaction = dynamic_cast<DepartmentStoreTransaction *>(transaction_list[i]))!=NULL){
				department_store_total +=department_store_transaction->get_transaction_amount();
				department_store_count++;
			}
			
			else if((grocery_transaction = dynamic_cast<GroceryTransaction *>(transaction_list[i]))!=NULL){
				grocery_total+=grocery_transaction->get_transaction_amount();
				gorcery_count++;
			}
		}
	}
	transaction_balance_ += total_fee_charge + total_transaction_amount;
	cout << "..............................................................................................\n\n\n" << endl;
	
	cout << "Total fee charge:\t$" << right << setprecision(2) << total_fee_charge
 		 << "\nTotal balance:\t\t$" << transaction_balance_ << endl;
 		 
 	cout << "\n\n\t\t\t\t\tTransaction summary\n" << endl;
 	cout << "\tTransaction type\t\tTransaction count\t\tTotal purchase\n" << endl;
 	
 	cout << "\tDepartment Store\t\t\t" << department_store_count 
	 	 << setprecision(2) << "\t\t\t   $" << right << department_store_total << "\n" << endl;
 	cout << "\tBanking\t\t\t\t\t"  <<  banking_count
	 	 << setprecision(2) << "\t\t\t   $" << right << banking_total << "\n" << endl;
 	cout << "\tGrocery\t\t\t\t\t" << gorcery_count
	 	 << setprecision(2) << "\t\t\t   $" << right << grocery_total << "\n" << endl;
	
	cout << "..............................................................................................\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t   $" << total_transaction_amount << "\n\n" << endl;
	
}




void Customer::ReportRewardSummary(){
	int department_store_points = 0;
	int  grocery_points= 0;
	DepartmentStoreTransaction * department_store_transaction = NULL;
	GroceryTransaction * grocery_transaction = NULL;
	
	cout << "Reward points for " << customer_name_ << " Last 4 digits of credit card number \"" 
	<< credit_card_number_[12] << credit_card_number_[13] << credit_card_number_[14] << credit_card_number_[15]
	<< "\"\n" << endl;
	//Since credit card numbers only have 16 digits.
	
	cout << "\tPrevious points balance\t\t" << reward_points_total_ << endl;
	
	for(int i=0; i<g_kSize; i++){
			
		 	if((department_store_transaction = dynamic_cast<DepartmentStoreTransaction *>(transaction_list[i]))!=NULL){
				department_store_points +=department_store_transaction->EarnPoints();
			}
			
			else if((grocery_transaction = dynamic_cast<GroceryTransaction *>(transaction_list[i]))!=NULL){
				grocery_points+=grocery_transaction->EarnPoints();
			}
	}
	cout << "\t+ Department store balance:\t" << department_store_points << endl;
	cout << "\t+ Grocery Purchases:\t\t" << grocery_points << endl;
	cout << "\t-----------------------------------------------------------------\n" << endl;
	
	reward_points_total_ += department_store_points + grocery_points;
	cout << "\t= Total points available for redemption: " << reward_points_total_ << endl << endl;
	
}


void Customer::ReportDuplicateTransactions(){
	
	DepartmentStoreTransaction * department_store_transaction = NULL;
	BankingTransaction * banking_transaction=NULL;
	GroceryTransaction * grocery_transaction=NULL;
	DepartmentStoreTransaction * department_store_transaction_2 = NULL;
	BankingTransaction * banking_transaction_2 = NULL;
	GroceryTransaction * grocery_transaction_2 = NULL;
	bool duplicates_exist = false;
	
	cout << "..............................................................................................\n" << endl;
	cout << "\t\t\t\tDUPLICATE TRANSACTION REPORT\n" << endl;
	cout << "\tTransaction type\t\t  Date\t\t\tAmount\t\tTransaction ID\n" << endl;
	
	for(int i=0; i<g_kSize; i++){
		for(int j=0; j<g_kSize; j++){
			
			
			
			if(j!=i){
				

				
				if(((banking_transaction = dynamic_cast<BankingTransaction *>(transaction_list[i]))!=NULL)
					and ((banking_transaction_2 = dynamic_cast<BankingTransaction *>(transaction_list[j]))!=NULL)
					and *banking_transaction == *banking_transaction_2){
						
					cout << "\t   Banking\t\t\t" << banking_transaction_2->get_transaction_date() << "\t\t$"
						 << banking_transaction_2->get_transaction_amount() << "\t\t    " 
						 << banking_transaction_2->get_transaction_id() <<endl;
					duplicates_exist = true;
					
				}
				
				else if(((department_store_transaction = dynamic_cast<DepartmentStoreTransaction *>(transaction_list[i]))!=NULL)
						and ((department_store_transaction_2 = dynamic_cast<DepartmentStoreTransaction *>(transaction_list[j]))!=NULL)
						and *department_store_transaction == *department_store_transaction_2){
							
					cout << "\t   Dept store\t\t\t" << department_store_transaction->get_transaction_date()
						 << "\t\t$" << department_store_transaction->get_transaction_amount()
						 << "\t\t    " << department_store_transaction->get_transaction_id() << endl;
					duplicates_exist = true;
				}
				
				else if(((grocery_transaction = dynamic_cast<GroceryTransaction *>(transaction_list[i]))!=NULL)
						and ((grocery_transaction_2 = dynamic_cast<GroceryTransaction *>(transaction_list[j]))!=NULL)
						and *grocery_transaction == *grocery_transaction_2){
							
					cout << "\t   Grocery store\t\t" << grocery_transaction->get_transaction_date() << "\t\t$"
						 << grocery_transaction->get_transaction_amount() << "\t\t    "
						 << grocery_transaction->get_transaction_id() << endl;
					
					duplicates_exist = true;
					
				}

			}
			
		}
	}
	if(!duplicates_exist){
		cout << "\n\t\t\t\t\tNo duplicate transactions found.\n\n" << endl;
	}
}






int main(){
	Customer customer("Dillon Pinto", "1234567891011121", 0);
	customer.ReadTransactions();
	customer.ReportAllTransactions();
	customer.ReportRewardSummary();
	customer.ReportDuplicateTransactions();
	//Automatically frees memory since dynamic memory allocation isn't used.
}
