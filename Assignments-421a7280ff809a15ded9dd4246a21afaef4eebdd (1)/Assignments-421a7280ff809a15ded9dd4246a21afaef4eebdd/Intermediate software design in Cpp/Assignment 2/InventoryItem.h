#ifndef InventoryItem_H
#define InventoryItem_H
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class InventoryItem{
	
	protected:
		string name_;
		int quantity_;
		
	public:
		InventoryItem();
		InventoryItem(string Item_name, int Item_quantity);
		~InventoryItem();
		void Display() const;
		string get_name() const;
		int get_quantity() const;
		void set_name(string name);
		void set_quantity(int quantity);
	
	
};

#endif

