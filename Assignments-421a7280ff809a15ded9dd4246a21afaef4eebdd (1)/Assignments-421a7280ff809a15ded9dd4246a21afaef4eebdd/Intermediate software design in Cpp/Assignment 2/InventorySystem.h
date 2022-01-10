#ifndef InventorySystem_H
#define InventorySystem_H
#include "InventoryItem.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


class InventorySystem{
	public:
		static const int g_kSize = 512;
		InventorySystem();
		InventorySystem(string store_name, int store_ID);
		~InventorySystem();
		void BuildInventory(string filename);
		void ShowInventory() const;
		void ShowDefectInventory() const;
		void Terminate()const;
		InventoryItem  * SearchItem(int product_ID) const;
		void Discontinue();
		string get_store_name() const;
		int get_store_ID() const;
		int get_item_count() const;
		void set_store_name(string store_name);
		void set_store_ID(int store_ID);
		void set_item_count(int item_count);
		void write_to_temporary_file(InventoryItem * found_product);
		
		
		
		
	private:
		string store_name_;
		int store_ID_;
		InventoryItem * item_list_[g_kSize];
		int item_count_;
				
};

#endif
