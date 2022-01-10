#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector> 
#include <map>
using namespace std;
/*
Purpose: This program is for the use of customer service staff at a call center of a phone carrier.
		 Staff can choose 1 of 4 options to list account details, errase a media message from an account,
		 disconnect an account or quit.
		 This is done by implementing classes using inheritance and class templates and also by using
		 STL.
History:
		8/1/2016: Created/Declared Item, Message, Text and Media classes
		8/2/2016: Defined all member functions in each class
		8/3/2016: Define non-member/global functions to be run in main
		8/4/2016: Debugged and completed development of program
		
*/


class Item {
	private:
		long time_;
		string from_;
		string to_;
		double charge_;
	public:
		Item();
		Item(long time, string from, string to, double charge);
		virtual ~Item();
		long get_time() const;
		string get_from() const;
		string get_to() const;
		double get_charge() const;
		void set_time(long time);
		void set_from(string from);
		void set_to(string to);
		void set_charge(double charge);
		virtual void Display() const;
		bool operator== (const Item & item) const;
		long current_time();
};

//--------------------------------------------------------------------------------------------------------------------

//Constructor/destructor
Item::Item(): time_(time(0)), from_(""), to_(""), charge_(0) {}

Item::Item(long time, string from, string to, double charge): time_(time), from_(from), to_(to), charge_(charge){}

Item::~Item(){
	//cout << "\nItem destroyed..." << endl;
}

//Accessors/mutators
long Item::get_time() const {
	return time_;
}
string Item::get_from() const{
	return from_;
}
string Item::get_to() const{
	return to_;
}
double Item::get_charge() const{
	return charge_;
}
void Item::set_time(long time){
	time_ = time;
}
void Item::set_from(string from){
	from_= from;
}
void Item::set_to(string to){
	to_ = to;
}
void Item::set_charge(double charge){
	charge_ = charge;
}


void Item::Display() const{
	cout << "Time:   "   << time_   << "\n"
		 << "from:   "   << from_   << "\n"
		 << "to:     "   << to_     << "\n"
		 << "charge: " << charge_ << endl;
}

//Operator overload
bool Item::operator== (const Item & item2) const{
	return ((time_ == item2.time_) and
			(from_ == item2.from_) and
			(to_   == item2.to_));
}



//-----------------------------------------------------------------------------------------------

template <class T>
class Message: public Item{
	private:
		T message_object_;
	
	public:
		Message();
		Message(long time, string from, string to, double charge, T message_object);
		virtual ~Message();
		T get_message_object();
		void set_message_object(T new_message_object);
		virtual void Display() const;
	
};

template <class T>
Message<T>::Message(){}

template <class T>
Message<T>::Message(long time, string from, string to, double charge, T message_object):
				Item(time, from, to, charge), message_object_(message_object) {}

template <class T>
Message<T>::~Message(){}


template <class T>
T Message<T>::get_message_object(){
	return message_object_;
}


template <class T>
void Message<T>::set_message_object(T new_message_object){
	message_object_ = new_message_object;
}


template <class T>
void Message<T>::Display() const{
	Item::Display();
	cout << message_object_ ;
}







//-----------------------------------------------------------------------------------------------



class Text {
	private:
		string content_;
	public:
		Text();
		Text(string content);
		~Text();
		string get_content() const;
		void set_content(string content);
		friend ostream & operator<< (ostream &,  const Text &);
		
	
};

Text::Text(): content_(""){}

Text::Text(string content): content_(content){}

Text::~Text(){
	//cout << "\nText object destroyed..." << endl;
}

string Text::get_content() const{
	return content_;
}

void Text::set_content(string content){
	content_ = content;
}


ostream & operator<< (ostream & os,  const Text & text){
	os  <<  text.content_  <<  endl;
    return os; 
}






//----------------------------------------------------------------------------------------------------





class Media{
	private:
		double size_;
		string media_format_;
	
	public:
		Media();
		Media(double size, string media_format);
		~Media();
		friend ostream & operator<< (ostream &,  const Media &);
		double get_size();
		string get_media_format();
		void set_size(double size);
		void set_media_format(string media_format);
	
};

Media::Media(): size_(0), media_format_(""){}

Media::Media(double size, string media_format): size_(size), media_format_(media_format){}

Media::~Media(){
	//cout << "\nMedia object destroyed..." << endl;
}
double Media::get_size(){
	return size_;
}
string Media::get_media_format(){
	return media_format_;
}
void Media::set_size(double size){
	size_= size;
}
void Media::set_media_format(string media_format){
	media_format_ = media_format;
}

ostream & operator<< (ostream & os,  const Media & media){
	os  <<  "Size:   " << media.size_  << "MB\n"
		<< "Format: " << media.media_format_ << endl;
    return os;
}



//--------------------------------------------------------------------------------------------------------




void  BuildAccounts (map<string, vector<Item*> >  & accounts_list, vector<Item*> & error_list ) {

	//Find out if I should read over blank line
	vector<Item> messages;
	ifstream account_file;
	string buffer;
	char message_type;
	long created_time ;
	string from;
	string to;
	double charge;
	string message_specific_data_text;
	string message_specific_data_media_format;
	double message_specific_data_size;
	Item * item = NULL;
	Item * invalid_item = NULL;
	
	account_file.open("account.txt");
		
	if (!account_file) {
		cout << "couldn't open file." << endl;
		exit(-1);
	}
	
	else {

	    while (getline(account_file,buffer,',')){
    		message_type=buffer[0];
    		
	    	
	    	if(message_type =='N'){			
				getline(account_file,buffer,'\n');
	    		from= buffer;
			    accounts_list[from];
			    continue;
			}
			
	    	getline(account_file,buffer,',');
		    created_time  = atol(buffer.c_str());

		    getline(account_file,buffer,',');
		    from= buffer;
		    
		    getline(account_file,buffer,',');
		    to= buffer;
		    
			getline(account_file,buffer,',');
		    charge = atof(buffer.c_str());
		
			
			
			switch (message_type) {
					
				case 'T':						
					getline(account_file,buffer,'\n');
		    		message_specific_data_text= buffer;
		    		
					item = new Message<Text> (created_time , from, to, charge, Text(message_specific_data_text));
					
				    accounts_list[from].push_back(item);
				    
					break;
					
					
				case 'M':
					getline(account_file,buffer,',');
		    		message_specific_data_media_format= buffer;
		    		
		    		try{
				    	getline(account_file,buffer,'\n');
			    		message_specific_data_size = atof(buffer.c_str());
			    		if (buffer.find(',') != string::npos){
			    			throw 1;
						}
		    		}
		    	
			    	catch(int x){
			    		invalid_item = new Message<Media> (created_time , from, to, charge, Media (message_specific_data_size,message_specific_data_media_format)); 
			    		error_list.push_back(invalid_item);
			    		continue;
					}
		    		
		    		
					item = new Message<Media> (created_time , from, to, charge, Media (message_specific_data_size,message_specific_data_media_format)); 
					
    				accounts_list[from].push_back (item);
					break;

					
			}     

		}	
	}
	account_file.close();
}








void Accounts_Summary(const map<string, vector<Item*> >  & accounts_list){
	//change  parameters and see if can be optimized
	
	vector<Item*>::const_iterator messages_iter;
	map<string, vector<Item*> >::const_iterator accounts_iter;
	string account;
	int message_count;
	Message<Media> * media_message = NULL;
	Message<Text> * text_message  = NULL;
	cout << "Phone number\tTotal messages\tText\tMedia\tTotal charges\n\n";
	int text_message_count = 0;
	int media_message_count = 0;
	double acount_charges = 0;
	
	
	for(accounts_iter = accounts_list.begin(); accounts_iter!= accounts_list.end(); accounts_iter++){
		cout << accounts_iter->first<< "\t\t" << accounts_iter->second.size();
		text_message_count=0;
		media_message_count=0;
		acount_charges = 0;
		
		for(messages_iter = accounts_iter->second.begin(); messages_iter != accounts_iter->second.end(); messages_iter++) {
			
			if((text_message = dynamic_cast<Message<Text>*>(*messages_iter))!=NULL){
				acount_charges += text_message->get_charge();
				text_message_count++;	
			}
			
			else if((media_message = dynamic_cast<Message<Media>*>(*messages_iter))!=NULL){
				acount_charges += media_message->get_charge();
				media_message_count++;
			}
		}
		
		cout << "\t  " << text_message_count << "\t  " << media_message_count 
			 << "\t   $" << fixed << setprecision(2) << acount_charges << endl;
	}
	
}








void EraseMediaMessage(map<string, vector<Item*> >  & accounts_list){
	
	map<string, vector<Item*> >::iterator accounts_list_iter;
	vector<Item*>::iterator messages_iter;
	string account;
	long created_time ;
	string to;
	string from;
	bool isDeleted=false;
	
	cout << "Choose an account (enter phone number): ";
	cin >>  account;
	
	
	/*---Alternative method
	try{
		accounts_list.at(account);
	}
	catch(exception &e){
		//Prevents the program from crashing.
		cout << "Account doesn't exist.";
	}*/
	
	

	accounts_list_iter = accounts_list.find (account); 
	
	if (accounts_list_iter == accounts_list.end ( ) ) {
	
	    cout << "\nAccount not found\n" << endl;
	
	 }
	
	else {
		
		cout << "Enter the time the message was sent: ";
		cin >> created_time ;
		
		cout << "Enter the receipient(\"to\"): ";
		cin >> to;
		
//		cout << "Enter the sender((\"from\"): ";  ------>Redundant since "Account" holds the sender/account holder's number so it's implied they are the same person
//		cin >> from;
		
		Message<Media> * media_message = NULL;
		
		for(messages_iter=accounts_list_iter->second.begin(); messages_iter!=accounts_list_iter->second.end();messages_iter++){
			if((account == (*messages_iter)->get_from()) and
				to ==(*messages_iter)->get_to() 	  and
				created_time  == (*messages_iter)->get_time()and 
				(media_message = dynamic_cast<Message<Media>* >(*messages_iter))!=NULL){
					delete *messages_iter;
					accounts_list_iter->second.erase(messages_iter);
					cout << "\nDeleted successfully"<<endl;
					isDeleted=true;
					break;
					
				}
			
			
		}
	}
	
	if(!isDeleted){
		cout << "\n\nNo match found or message was not Media message.\n" << endl;
	}

}








void DisconnectAccount(map<string, vector<Item*> >  & accounts_list){
	string account;
	cout << "Choose an account to delete (enter phone number): ";
	cin >>  account;
	vector<Item*>::iterator Messages_iter;
	
	
	for(Messages_iter= accounts_list[account].begin();Messages_iter!=accounts_list[account].end();Messages_iter++){
		delete *Messages_iter;
	}
	accounts_list.erase(account);
}





void PreQuitTasks(map<string, vector<Item*> >  & accounts_list, vector<Item*> & error_list){
	
	map<string, vector<Item*> >::iterator accounts_iter;
	vector<Item*>::iterator messages_iter;
	vector<Item*>::iterator invalid_messages_iter;
	cout << "\n\n\t\tINVALID ACCOUNT MESSAGES\n" << endl;

	for(invalid_messages_iter = error_list.begin(); invalid_messages_iter != error_list.end(); invalid_messages_iter++){
		(*invalid_messages_iter)->Display();
		cout << "\n\n";
		delete *invalid_messages_iter;
	}
	
	
	for(accounts_iter = accounts_list.begin(); accounts_iter!= accounts_list.end(); accounts_iter++){
		for(messages_iter = accounts_iter->second.begin(); messages_iter != accounts_iter->second.end(); messages_iter++) {
			delete *messages_iter;
		}
	}
	
	error_list.clear();
	accounts_list.clear();
}
 
 
 
 
 
 
 
 
void StartCustomerSerivce(map<string, vector<Item*> >  & accounts_list, vector<Item*> & error_list){
	
	
	int option;
	
	cout << "\t\t\tFOOTHILL WIRELESS\n"
		 << "\t\tMESSAGE UTILIZATION AND ACCOUNT ADMIN\n" <<endl;
	
	do {
		cout << "\n\n1: List summary of message usages/charges from all accounts\n"
			 << "2: Erase a Media message from an account\n"
			 << "3: Disconnect an account\n"
			 << "4: Quit\n" << endl;
		
		cout << "Enter the number that corresponds to your option choice(1-4): ";
		cin  >> option;
		
		switch(option){
			case 1:
				Accounts_Summary(accounts_list);
				break;
			
			case 2:
				EraseMediaMessage(accounts_list);
				break;
			
			case 3:
				DisconnectAccount(accounts_list);
				break;
			
			case 4:
				PreQuitTasks(accounts_list, error_list);
				break;
			
		}
	}while(option!=4);

 
}







int main(){
	
	map<string, vector<Item*> > accounts;
	vector<Item*> error_list;
	BuildAccounts(accounts, error_list);
	StartCustomerSerivce(accounts, error_list);
}
