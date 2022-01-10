#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Movie.h"
using namespace std;

Movie::Movie():movie_name_("Null"), seats_available_ (30), ticket_price_ (10.0){}

Movie::Movie(string movie_name, int seats_available, int ticket_price):
	movie_name_(movie_name), seats_available_ (seats_available), ticket_price_ (ticket_price) {}
	

Movie::~Movie(){
	cout << "Movie \"" << movie_name_ << "\" object no longer showing" << endl;
}

//Set functions/Mutators
void Movie::set_movie_name(string movie_name){
	movie_name_ = movie_name;
}
void Movie::set_seats(int num_of_seats){
	seats_available_ = num_of_seats;
}
void Movie::set_price(double ticket_price){
	ticket_price_ = ticket_price;
}

//Get functions/Accessors
string Movie::get_movie_name() const{
	return movie_name_;
}
int Movie::get_seats() const{
	return seats_available_;
}
double Movie::get_price() const{
	return ticket_price_;
}


double Movie::PurchaseTicket(int num_of_tickets){
	double total_cost;
	
	total_cost = ticket_price_ * num_of_tickets;
	if (seats_available_ < num_of_tickets){
		return -1;
	}
	seats_available_ -= num_of_tickets;
	return total_cost;
}

void Movie::Display() const{
	cout << "\nMovie: " << movie_name_ 
		 << "\nSeats available: " << seats_available_ 
		 << "\nTicket price: $" << setprecision(1) << fixed << ticket_price_ << "\n" << endl;
}
