#include "InventoryItem.h"
#include <iomanip>
#include <cstdlib>
using namespace std;

//Constructors and destructor
InventoryItem::InventoryItem(): name_(""), quantity_(0){}


InventoryItem::InventoryItem(string name, int quantity): name_(name), quantity_(quantity){}


InventoryItem::~InventoryItem(){
	cout << "Inventory item " << name_ << " with " << quantity_ << " items destroyed...\n" << endl;
}






//Get functions/accessors
string InventoryItem::get_name() const{
	return name_;
}

int InventoryItem::get_quantity() const{
	return quantity_;
}





//Set functions/mutators
void InventoryItem::set_name(string name){
	name_ = name;
}

void InventoryItem::set_quantity(int quantity){
	quantity_ = quantity;
}





//Display
void InventoryItem::Display() const{
	cout<< left  << "Item name:  " << name_ <<"\nQuantity:   " << right<< quantity_ ;
}

