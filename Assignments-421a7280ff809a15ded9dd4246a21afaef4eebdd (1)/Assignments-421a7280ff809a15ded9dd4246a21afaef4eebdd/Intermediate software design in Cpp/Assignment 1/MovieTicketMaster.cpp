#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "MovieTicketMaster.h"
#include "Movie.cpp"
using namespace std;



//Member function definitions
MovieTicketMaster::MovieTicketMaster():
	theater_name_("Unknown"), theater_location_("Uknown"){
		
	for (int i=0; i<g_kSize; i++) {
        Movie_list_[i] = NULL;
    }
}







MovieTicketMaster::MovieTicketMaster(string theater_name, string theater_location):
	theater_name_(theater_name), theater_location_(theater_location) {
	
	for (int i=0; i<g_kSize; i++) {
        Movie_list_[i] = NULL;
    }
}






MovieTicketMaster::~MovieTicketMaster(){
	for (int i=0; i < g_kSize; i++) {
        delete Movie_list_[i];
    }
	cout << "\nTheater \"" << theater_name_ << "\" has been closed at " << theater_location_ ;
}








void MovieTicketMaster::Init(){
	
	
	string * p_movie_names = NULL;
	int * p_seats_available = NULL;
	double * p_prices = NULL;
	
	
	string movie_names[g_kSize] = {  "Black Mass", "The Visit", "Mission: Impossible - Rogue Nation",
    	"Straight Outta Compton", "No Escape", "Maze Runner: Scorch Trials", "Everest",
    	"War Room"
	};
	int seats_available[g_kSize] = {30, 30, 30, 40 , 40 , 30, 30, 30};
	double prices[g_kSize] = { 10.0, 10.0, 15.0, 15.0, 10.0, 10.0, 10.0, 10.0};
	
	p_movie_names = movie_names;
	p_seats_available = seats_available;
	p_prices = prices;
	
	for (int i=0; i<g_kSize; i++){
		Movie_list_[i] = new Movie(*p_movie_names, *p_seats_available, *p_prices);
		
		p_movie_names++;
		p_seats_available++; 
		p_prices++;
	}
	
	//Selection sort
	int new_min_position;
    Movie * movie_to_switch= NULL;
    Movie * movie_for_smallest_movie_name= NULL;
    int smallest_movie_name_pos;
    string smallest_movie_name;
    string current_movie_name;
    bool found;
    
	for (int i=0; i < g_kSize-1;i++) {
		
		found=false;
        smallest_movie_name_pos = i;
        if (Movie_list_[i]  != NULL) {
        	smallest_movie_name = Movie_list_[i]->get_movie_name();
    	}
        
        for(int j=i; j<g_kSize;j++){
		
        	if (Movie_list_[j]  != NULL) {
                current_movie_name=Movie_list_[j]->get_movie_name();
			}
			
			
			
            if (current_movie_name < smallest_movie_name){
            	movie_for_smallest_movie_name=Movie_list_[j];
                new_min_position = j;
                movie_to_switch=Movie_list_[i];
                found=true;
            
        	}
    	}
    	
    	if(found){
        Movie_list_[smallest_movie_name_pos]=movie_for_smallest_movie_name;
        Movie_list_[new_min_position]=movie_to_switch;}
	}
	
}





void MovieTicketMaster::Menu() const{
	cout << "MOVIE TICKET MASTER\n\nTheater: " << theater_name_ << " at " << theater_location_ <<endl
		 << "The Movie Experience\n";
	cout << "\n1. View all movies\n" << "2. Search a movie\n"
		 << "3. Purchase a ticket\n" << "4. Quit" << endl;
	
}






void MovieTicketMaster::ViewMovies() const {
	Movie * p_movie = NULL;
	
	
	for (int i = 0; i < g_kSize; i++) {
		p_movie = Movie_list_[i];
    	p_movie->Display();
    	cout << endl;
        p_movie++;
    }   
}





//Binary search for the FindMovie member function
Movie * MovieTicketMaster::FindMovie(string movie_name) const{
    
    int min_position=0;
    int max_position= g_kSize - 1;
    int mid_position;
    
    while (min_position <= max_position){
    	mid_position = (min_position + max_position)/2;
    	
    	if (Movie_list_[mid_position]->get_movie_name()==movie_name){
    		return Movie_list_[mid_position];
		}
		
		else if (movie_name > Movie_list_[mid_position]->get_movie_name()){
            min_position = mid_position+1;
		}
		
        else{
            max_position = mid_position-1;
            
    	}
	}
    
    
    return NULL; // As shown in module 1C
}






void MovieTicketMaster::SearchMovie() {
	string movie_name_from_user;
	
	cout << "Enter a movie name to search for: ";
	if (cin.peek () == '\n') {
    	cin.ignore ();
    }
	getline(cin, movie_name_from_user);
	
	Movie * p_movie = FindMovie(movie_name_from_user);
	
	if (p_movie == NULL){
		cout << "\nMovie not found\n" << endl;
	}
	else {
		p_movie->Display();
		cout << endl;
	}
}






void MovieTicketMaster::PurchaseTicket() {
	string movie_name_for_ticket;
	int num_of_tickets;
	Movie * p_movie = NULL;
	
	cout << "Enter movie name: ";
	if (cin.peek () == '\n') {
    	cin.ignore ();
    }
	getline(cin, movie_name_for_ticket);
	
	cout << "Enter the number of tickets: ";
	cin >> num_of_tickets;
	p_movie = FindMovie(movie_name_for_ticket);
	
	if (p_movie == NULL){
		cout << "\nMovie not found\n" << endl;
	}
	else {
		int total_cost = p_movie->PurchaseTicket(num_of_tickets);
		if (total_cost== -1){
			cout << "\nThe show has been sold out or not enough tickets available per your request.\n"
				 << endl;
		}
		else{
			cout <<"\nThe total cost is: $" <<fixed << setprecision(1) << total_cost << endl <<endl;
		}
	}
}






void MovieTicketMaster::Run(){
	int user_choice;
	
	do{

		Menu();
		cout << "Choose an option (Enter the option number): ";
		cin >> user_choice;
		
	
		if (user_choice == 1){
			ViewMovies();
		}
			
		else if (user_choice == 2){
			SearchMovie();
		}
			
		else if (user_choice == 3){
			PurchaseTicket();
		}	
		
	} while (user_choice != 4);
}
