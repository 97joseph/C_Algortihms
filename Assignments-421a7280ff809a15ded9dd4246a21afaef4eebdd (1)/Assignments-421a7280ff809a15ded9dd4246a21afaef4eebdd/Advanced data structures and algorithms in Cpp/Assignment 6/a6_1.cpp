#include <iostream>
#include <time.h>
#include <cstdlib>
#include "EBookEntry.cpp"




using namespace std;


/*
Name: Dillon Pinto
Assignment 6

This program is used to create a hash table of random books of 
the class "EBookEntry". Ebooks are put into a hashtable at random
with 25 ebooks at most, at a time. These Ebooks are then displayed
while they are added to the hashtable using the PrintBook functor.
The main goal of the program is to test the find function in the
hashtable as well as the rest of the FHhashQP and FHhashQPwFind classes.
*/

//Global constant
const int NUM_RANDOM_INDICES = 25;


// ----------- prototypes -------------
int getKey( const EBookEntry & item);
//string getKey( const EBookEntry & item);

int Hash( const EBookEntry & item);
int Hash( int key );
int Hash( const string & key );

#include "FHhashQPwFind.h"






//From 4B.3.1 to print out EBookEntry objects
class PrintBook
{
public:
   void operator()(EBookEntry book)
   {
      cout << book.getETextNum() << ": " << book.getCreator().substr(0,15)
         << ", " << book.getTitle().substr(0,20)
         << ", " << book.getSubject().substr(0,25) << endl;
   }
};

int main(){
	

	srand(time(NULL));
	int num_of_Ebooks;
	EBookEntry Ebook;
	PrintBook Print;
	int i;
	int randomIndices[NUM_RANDOM_INDICES];
	FHhashQPwFind<EBookEntry, int> hashTable; // for ID equality
	//FHhashQPwFind<EBookEntry, string> hashTable; // for any string equality
	
	

	EBookEntry::setSortType(EBookEntry::SORT_BY_ID);
	//EBookEntry::setSortType(EBookEntry::SORT_BY_CREATOR);
	
	
	
	EBookEntryReader book_input("catalog-short4.txt");

	if (book_input.readError())
	{
	  cout << "couldn't open " << book_input.getFileName() << " for input.\n";
	  exit(1);
	}
	num_of_Ebooks = book_input.getNumBooks();
	
	
		
	
	cout << book_input.getFileName() << endl;
	cout << book_input.getNumBooks() << endl << endl;
	
	
	
	// create a QP hash table of EBooks ...
	// generate some random indices into the EBookEntryReader vector ...
	// insert all books into the hash table (if SORT_BY_ID) or fewer (If SORT_BY_CREATOR) ...
	// display NUM_RANDOM_INDICES books from array ...
	
	
	
	for(i=0; i< NUM_RANDOM_INDICES; i++) {
		randomIndices[i] = rand() % num_of_Ebooks;
		Print(book_input[randomIndices[i]]);
	}
	
	//Create a QP hash table of Ebooks
	for(i=0; i < num_of_Ebooks; i++){
		hashTable.insert(book_input[i]);
	}

	// attempt to find on the selected key
	cout << "\n\nThe same random books from the hash table " << endl;
	for (int k = 0; k < NUM_RANDOM_INDICES; k++)
	{
	  try {
	  	

	    	Ebook = hashTable.find( book_input[ randomIndices[k] ].getETextNum() );
	    	//Ebook = hashTable.find( book_input[ randomIndices[k] ].getCreator() );
			Print(Ebook);
	  	}
		catch (...){
			cout << "Random-indices-book not found  ";
	    	cout << endl;
	  	}
	  	cout << endl;
	}
	
	// test known failures exceptions:
	try
	{
	  Ebook = hashTable.find( -3 );
	  //Ebook = hashTable.find( "Jack Kerouac" );
	
	
	}
	catch (...){
	  cout << "Book not found \n\n";
	}
	
	// more failures
	
	try{
		
		//More erroneous data
		Ebook = hashTable.find(20000000);
		//Ebook = hashTable.find( "erfe-_ %^&* " );
	}
	catch (...){
		
		cout << "Book not found \n\n";
	}
	
	try{
		Ebook = hashTable.find(-999999 );
		//Ebook = hashTable.find( "Andy Weir" );
		
	}
	
	catch (...) {
		
		cout << "Book not found \n\n";
	}


}



//string getKey( const EBookEntry & item);
// used for ID equality
int getKey( const EBookEntry & item) {
   return item.getETextNum() ;
}

// From 6A.2.5
// a hash routine for ints 
int Hash( int key )
{
    return key;
}




int Hash( const EBookEntry & item )
{
	//get the key from the object and return the hashed value
	return Hash(getKey(item));
}



/*


// used for author equality
string getKey( const EBookEntry & item )
{
   return item.getCreator() ;
}



int Hash( const string & key )
{
    unsigned int k, retVal = 0;

    for(k = 0; k < key.length( ); k++ )
        retVal = 37 * retVal + key[k];

    return retVal;
}*/






/*
Search by ID:
catalog-short4.txt
4863

26221: Montgomery, L. , The Golden Road, Prince Edward Island -- J
8056: Anonymous, The Bible, King Jame, (no data found)
29027: Rich, H. Thomps, Spawn of the Comet, Science fiction
28628: Wells, Hal K., , Devil Crystals of Ar, Science fiction
29963: Harris, Tom W., Goodbye, Dead Man!, Science fiction
25525: Poe, Edgar Alla, The Works of Edgar A, Short stories
27266: Bates, Joseph, , The Seventh Day Sabb, Seventh-Day Adventists --
25405: France, Anatole, Honey-Bee1911, PQ
23241: Jowett, John He, My Daily Meditation , Calendars
26954: (no data found), The Mirror of Taste,, Theater -- Periodicals
19997: Ober, Frederick, Amerigo Vespucci, (no data found)
25410: France, Anatole, The Miracle Of The G, PQ
24950: Bradford, Willi, Bradford's History o, Massachusetts -- History
29021: Perrault, Charl, The Fairy Tales of C, Fairy tales
29820: Mansfield, M. F, The Cathedrals of No, France -- Description and
28289: Eliot, George, , The Essays of &quot;, PR
25659: Unknown, A Week of Instructio, Children's stories
4654: Shelley, Percy , The Daemon of the Wo, Poetry
27597: Stephen, Leslie, The English Utilitar, Utilitarianism -- Great B
10237: (no data found), Siegel-Myers School , (no data found)
2661: Harte, Bret, 18, The Story of a Mine, American fiction -- 19th
2274: Bennett, Arnold, How to Live on 24 Ho, Conduct of life
1776: Shakespeare, Wi, King Richard II, Drama
26273: Montgomery, L. , The Story Girl, Cousins -- Fiction
29756: Henty, G. A. (G, The Cat of BubastesA, Egypt -- History -- To 33


The same random books from the hash table
26221: Montgomery, L. , The Golden Road, Prince Edward Island -- J

8056: Anonymous, The Bible, King Jame, (no data found)

29027: Rich, H. Thomps, Spawn of the Comet, Science fiction

28628: Wells, Hal K., , Devil Crystals of Ar, Science fiction

29963: Harris, Tom W., Goodbye, Dead Man!, Science fiction

25525: Poe, Edgar Alla, The Works of Edgar A, Short stories

27266: Bates, Joseph, , The Seventh Day Sabb, Seventh-Day Adventists --

25405: France, Anatole, Honey-Bee1911, PQ

23241: Jowett, John He, My Daily Meditation , Calendars

26954: (no data found), The Mirror of Taste,, Theater -- Periodicals

19997: Ober, Frederick, Amerigo Vespucci, (no data found)

25410: France, Anatole, The Miracle Of The G, PQ

24950: Bradford, Willi, Bradford's History o, Massachusetts -- History

29021: Perrault, Charl, The Fairy Tales of C, Fairy tales

29820: Mansfield, M. F, The Cathedrals of No, France -- Description and

28289: Eliot, George, , The Essays of &quot;, PR

25659: Unknown, A Week of Instructio, Children's stories

4654: Shelley, Percy , The Daemon of the Wo, Poetry

27597: Stephen, Leslie, The English Utilitar, Utilitarianism -- Great B

10237: (no data found), Siegel-Myers School , (no data found)

2661: Harte, Bret, 18, The Story of a Mine, American fiction -- 19th

2274: Bennett, Arnold, How to Live on 24 Ho, Conduct of life

1776: Shakespeare, Wi, King Richard II, Drama

26273: Montgomery, L. , The Story Girl, Cousins -- Fiction

29756: Henty, G. A. (G, The Cat of BubastesA, Egypt -- History -- To 33

Book not found

Book not found

Book not found











Search by creator:
catalog-short4.txt
4863

27226: Brooke, Henry, , An Essay on the Anti, Ireland -- History
25333: Ford, Paul Leic, The Great K. &amp; A, Train robberies -- Fictio
18823: Various, Modern Eloquence: Vo, (no data found)
26109: Garrett, Randal, Hail to the Chief, Science fiction
26060: Ivimey, John W., Complete Version of , Children's poetry
28476: Various, Notes and Queries, N, Questions and answers --
284: Wharton, Edith,, House of Mirth, New York (N.Y.) -- Fictio
26945: Various, Lippincott's Magazin, AP
25950: Germain, Walter, The Complete Bachelo, Etiquette
17929: Osler, Edward, , The Life of Admiral , (no data found)
26788: (no data found), Brown WilliamThe Pow, English poetry
29855: Heindel, Max, 1, The Rosicrucian Myst, Rosicrucians
5749: Holberg, Ludvig, Comedies by Holberg , (no data found)
28569: Tappan, Eva Mar, Makers of Many Thing, Manufactures
26345: Roy, Lillian El, Girl Scouts in the A, Canoes and canoeing -- Ju
25235: Anonymous, A Dialogue Between D, Ireland -- Politics and g
27231: Ellis, Edward S, The Riflemen of the , Indians of North America
27274: Aikman, Charles, Manures and the prin, Fertilizers
28041: Browning, Rober, Selections from the , PR
29031: Holden, Edward , Sir William Herschel, Herschel, William, Sir, 1
28769: Sherwood, Elmer, Ted Marsh on an Impo, Detective and mystery sto
26000: Smyth, W. H. (W, The Sailor's Word-Bo, Naval art and science --
24812: Kingston, Willi, The Three Midshipmen, Africa -- Fiction
24977: Castle, Arnold, The Perfectionists, Science fiction
9988: Maniates, Belle, Amarilly of Clothes-, (no data found)


The same random books from the hash table
27226: Brooke, Henry, , An Essay on the Anti, Ireland -- History

25333: Ford, Paul Leic, The Great K. &amp; A, Train robberies -- Fictio

28712: Various, The American Mission, Congregational churches -

30337: Garrett, Randal, Fifty Per Cent Proph, Science fiction

26060: Ivimey, John W., Complete Version of , Children's poetry

28712: Various, The American Mission, Congregational churches -

283: Wharton, Edith,, The Reef, Fiction

28712: Various, The American Mission, Congregational churches -

25950: Germain, Walter, The Complete Bachelo, Etiquette

17929: Osler, Edward, , The Life of Admiral , (no data found)

28351: (no data found), Dick and His Cat and, Animals -- Juvenile ficti

29855: Heindel, Max, 1, The Rosicrucian Myst, Rosicrucians

5749: Holberg, Ludvig, Comedies by Holberg , (no data found)

28569: Tappan, Eva Mar, Makers of Many Thing, Manufactures

26345: Roy, Lillian El, Girl Scouts in the A, Canoes and canoeing -- Ju

29382: Anonymous, The Ladies' Work-Tab, Crocheting

29667: Ellis, Edward S, Adrift on the Pacifi, Pacific Ocean -- Fiction

27274: Aikman, Charles, Manures and the prin, Fertilizers

28041: Browning, Rober, Selections from the , PR

29031: Holden, Edward , Sir William Herschel, Herschel, William, Sir, 1

28769: Sherwood, Elmer, Ted Marsh on an Impo, Detective and mystery sto

26000: Smyth, W. H. (W, The Sailor's Word-Bo, Naval art and science --

24812: Kingston, Willi, The Three Midshipmen, Africa -- Fiction

24977: Castle, Arnold, The Perfectionists, Science fiction

30075: Maniates, Belle, Our Next-Door Neighb, Fiction

Book not found

Book not found

Book not found


*/
