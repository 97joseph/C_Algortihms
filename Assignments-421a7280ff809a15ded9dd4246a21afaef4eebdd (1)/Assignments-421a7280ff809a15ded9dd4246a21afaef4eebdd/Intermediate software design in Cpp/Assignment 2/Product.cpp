#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Product.h"



using namespace std;


Product::Product () : InventoryItem(), price_(0.0), product_ID_(generateProductID()), condition_(pcNew) {}

Product::Product(string name, int quantity, double price, T_ProductCondition condition):
				 InventoryItem(name, quantity), product_ID_(generateProductID()), price_(price), condition_(condition){}

Product::~Product(){
	cout << fixed << setprecision(2) << "Product " << product_ID_ << " priced $" << price_ << " destroyed..." << endl;
}

int Product::generateProductID() const{
	
	int id;
    id = rand() % 10000; 
    return id;
}


//Get/accessors 
int Product::get_product_ID() const{
	return product_ID_;
}
double Product::get_price() const{
	return price_;
}
T_ProductCondition Product::get_condition() const{
	return condition_;
}




//Set/mutators
void Product::set_product_ID(int product_ID){
	product_ID_ = product_ID;
}
void Product::set_price(double price){
	price_ = price;
}
void Product::set_condition(T_ProductCondition condition){
	condition_ = condition;
}





void Product::Display() const {
	InventoryItem::Display();
	string condition;
	
	switch(condition_){
		case pcNew:
			condition = "New";
			break;
		case pcUsed:
			condition = "Used";
			break;
		case pcRefurbished: 
			condition = "Refurbished";
			break;
		case pcDefective:
			condition = "Defective";
			break;
			
	}

	cout << "\nProduct ID: "<< right << product_ID_  << fixed << setprecision(2)
		 <<"\nPrice:      $" << right << price_  <<"\nCondition:  " << condition << endl << endl;
}
