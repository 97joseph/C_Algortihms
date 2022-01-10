#include "InventorySystem.h"
#include "Product.cpp"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
InventorySystem::InventorySystem(){
	store_name_ = "";
	store_ID_ =0;
	item_count_= 0;
	for(int i=0;i<g_kSize;i++){
		item_list_[i] = NULL;
	}
	srand (time(NULL));
}






InventorySystem::InventorySystem(string store_name, int store_ID) {
	store_name_ = store_name;
	store_ID_ = store_ID;
	item_count_= 0;
	for(int i=0;i<g_kSize;i++){
		item_list_[i] = NULL;
	}
	srand (time(NULL));
}




InventorySystem::~InventorySystem() {
	for(int i=0;i<g_kSize;i++){
		delete static_cast<Product*>(item_list_[i]);
	}
}

void InventorySystem::BuildInventory(string filename){

	ifstream product_file;
	string buffer;
	string name;
	int quantity;
	double price;
	char condition_letter;
	
	product_file.open(filename.c_str());
		
		if (!product_file) {
			cout << "couldn't open file." << endl;
			exit(-1);
		}
		
		else {
		    while (getline(product_file,buffer,';')){
		    	name= buffer;
		    	
			    getline(product_file,buffer,';');
			    quantity = atol(buffer.c_str());

				getline(product_file,buffer,';');
			    price = atof(buffer.c_str());	
				
				getline(product_file,buffer,'\n');
			    condition_letter=buffer[0];//Because this string is a single letter so the index position has been used
				
				
				switch (condition_letter){
					case 'N':
						item_list_[item_count_] = new Product(name,quantity,price,pcNew);
						break;
					case 'R':
						item_list_[item_count_] = new Product(name,quantity,price,pcRefurbished);
						break;
				
					case 'U':
						item_list_[item_count_] = new Product(name,quantity,price,pcUsed);
						break;
						
					case 'D':
						item_list_[item_count_] = new Product(name,quantity,price,pcDefective);
						break;
				}     

		        item_count_++;
    		}	
		}
	product_file.close();
}

void InventorySystem::ShowInventory()const{
	for(int i=0; i<g_kSize;i++){
		if (item_list_[i] != NULL) {
			Product * product = static_cast<Product*>(item_list_[i]);
			product->Display();
			
		}
	}
}

void InventorySystem::ShowDefectInventory() const{
	cout << "\n\n-----Defective products-----\n\n";
	for(int i=0; i<item_count_;i++){
		if (item_list_[i] != NULL) {
			Product * product = static_cast<Product*>(item_list_[i]);			
			if(product->get_condition()==pcDefective){
				product->Display();
			}
		}
	}
	
}

void InventorySystem::Terminate() const {
	ofstream product_file_terminate("product_list2.txt");
	char delim = ';';
	string condition;

	
	if(!product_file_terminate){
		cout << "couldn't open file." << endl;
			exit(-2);
	}
	
	else{
		
		for(int i=0; i<g_kSize;i++){
			if (item_list_[i] != NULL) {
				Product * product = static_cast<Product*>(item_list_[i]);
				
				switch (product->get_condition()){
					case pcNew:
						condition = "N";
						break;
					case pcUsed:
						condition = "";
						break;
					case pcRefurbished: 
						condition = "R";
						break;
					case pcDefective:
						condition = "D";
						break;
			
				}     
				product_file_terminate << product->get_name() << delim << product->get_quantity()
				<< delim << fixed << setprecision(2) <<product->get_price() << delim << condition << "\n";
		}
	}
		
	}
	product_file_terminate.close();

}


//accessors and mutators
string InventorySystem::get_store_name() const{
	return store_name_;
}
int InventorySystem::get_store_ID() const{
	return store_ID_;
}
int InventorySystem::get_item_count() const{
	return item_count_;
}
void InventorySystem::set_store_name(string store_name){
	store_name_=store_name;
}
void InventorySystem::set_store_ID(int store_ID){
	store_ID_ = store_ID;
}
void InventorySystem::set_item_count(int item_count){
	item_count_ = item_count;
}

//Extra credit
InventoryItem * InventorySystem::SearchItem(int product_ID) const{
	for(int i=0; i<g_kSize;i++){
		if (item_list_[i]!=NULL){
		
			Product * product = static_cast<Product*>(item_list_[i]);
			if (product->get_product_ID()==product_ID){
				return item_list_[i];
			}
		}
	}
	return NULL;
}

void InventorySystem::write_to_temporary_file(InventoryItem * found_product){
	ofstream temp_file("temporary.txt");
	
		char delim = ';';
		string condition;
	
		
		if(!temp_file){
			cout << "couldn't open file." << endl;
				exit(-2);
		}
		
		else{
			for(int i=0; i<g_kSize;i++){
				if (item_list_[i] != NULL and item_list_[i] !=found_product) {
					Product * product = static_cast<Product*>(item_list_[i]);
					
					switch (product->get_condition()){
						case pcNew:
							condition = "N";
							break;
						case pcUsed:
							condition = "U";
							break;
						case pcRefurbished: 
							condition = "R";
							break;
						case pcDefective:
							condition = "D";
							break;
				
					}     
					temp_file << product->get_name() << delim << product->get_quantity()
					<< delim << fixed << setprecision(2) <<product->get_price() << delim << condition << "\n";
			}
		}
			
		}
		temp_file.close();
}

void InventorySystem::Discontinue(){
	int product_ID;
	int delete_position;
	InventoryItem * TempInventoryItemList[g_kSize] = {NULL};

	
	cout << "Which product should be discontinued? Enter the product ID: ";
	cin >> product_ID;
	
	InventoryItem * found_product = SearchItem(product_ID);
	
	if(found_product==NULL){
		cout << "\nError: Product not found.\n" << endl;
	}
	
	else{
		
		//Temp file method used as a work around to my program crashing when deallocating memory
		//or assigning pointers within the item_list_ array
		
		write_to_temporary_file(found_product);
		cout << "\n\n\nDeallocating memory and rebuilding array...\n\n\n\n\n";
		for (int i=0;i<g_kSize;i++){
			delete static_cast<Product*>(item_list_[i]);
			item_list_[i]=NULL;
		}
		BuildInventory("temporary.txt");
		remove("temporary.txt");
		
		
	}
}


