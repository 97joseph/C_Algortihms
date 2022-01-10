#ifndef MovieTicketMaster_H
#define MovieTicketMaster_H
#include "Movie.h"
#include <iostream>
using namespace std;

const int g_kSize = 8;


class MovieTicketMaster {
	public:
		MovieTicketMaster();
		~MovieTicketMaster();
		MovieTicketMaster(string theater_name, string theater_location);
		void Init();
		void Menu() const;
		void Run();
		void ViewMovies() const;
		void SearchMovie();
		Movie * FindMovie(string movie_name) const;
		void PurchaseTicket();
		void FindMovie();
		
	private:
		string theater_name_;
		string theater_location_;
		Movie * Movie_list_[g_kSize];
	
};

#endif
