#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "MovieTicketMaster.cpp"
using namespace std;

int main(){
	MovieTicketMaster * p_movie_ticket_master = NULL;
	p_movie_ticket_master = new MovieTicketMaster("Fremont theater","San Luis Obispo");
	p_movie_ticket_master->Init();
	p_movie_ticket_master->Run();
	delete p_movie_ticket_master;
}
