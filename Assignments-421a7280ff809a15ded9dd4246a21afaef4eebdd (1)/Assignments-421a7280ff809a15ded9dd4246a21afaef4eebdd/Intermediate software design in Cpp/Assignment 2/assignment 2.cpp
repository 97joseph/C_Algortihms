#include <iostream>
#include <ctime>
#include <cstdlib>
#include "InventorySystem.cpp"
#include "InventorySystem.h"





using namespace std;



int main(){
	
	char option;
	InventorySystem * inventory_system = NULL;
	inventory_system = new InventorySystem;
	inventory_system->BuildInventory("product_list.txt");
	inventory_system->ShowInventory();
	inventory_system->ShowDefectInventory();
	
	
	//Asked for input outside the loop and inside the loop so the user can choose to not dicsontinue
	//any products.
	cout << "\n\nWould you like to discontinue a product?\nPress any key to discontinue a product or type 'Q' to quit: ";
	cin >> option;

	while(option != 'Q'){
		inventory_system->Discontinue();
		inventory_system->ShowInventory();//Since the list gets rebuilt on every discontinue, ShowInventory needs to be invoked
		cout << "\n\nWould you like to discontinue a product?\nPress any key to discontinue a product or type 'Q' to quit: ";
		cin >> option;
	}

	inventory_system->Terminate();
	delete inventory_system;

	return 0;
}
