#ifndef Product_H
#define Product_H
#include "InventoryItem.cpp"
using namespace std;

typedef  enum  {  pcNew, pcUsed,  pcRefurbished, pcDefective } T_ProductCondition;

class Product: public InventoryItem {
	private:
		int product_ID_;
		double price_;
		T_ProductCondition condition_;
		int generateProductID() const;
			
	public:
		Product();
		Product(string name, int quantity , double price, T_ProductCondition condition);
		~Product();
		int get_product_ID() const;
		double get_price() const;
		T_ProductCondition get_condition() const;
		void set_product_ID(int product_ID);
		void set_price(double price);
		void set_condition(T_ProductCondition condition);
		void Display() const;
	

};

#endif
