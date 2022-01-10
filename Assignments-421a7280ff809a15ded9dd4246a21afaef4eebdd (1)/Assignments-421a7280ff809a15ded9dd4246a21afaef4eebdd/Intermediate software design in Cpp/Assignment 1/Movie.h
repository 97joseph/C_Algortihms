#ifndef Movie_H
#define Movie_H
#include <iostream>
using namespace std;


class Movie {
	public:
		Movie();
		~Movie();
		Movie(string movie_name, int seats_available, int ticket_price);
		void set_movie_name(string movie_name);
		string get_movie_name() const;
		void set_seats(int num_of_seats);
		int get_seats() const;
		void set_price(double ticket_price);
		double get_price() const;
		double PurchaseTicket(int num_of_tickets);
		void Display() const;
	
	private:
		string movie_name_;
		int seats_available_;
		double ticket_price_;
};

#endif
