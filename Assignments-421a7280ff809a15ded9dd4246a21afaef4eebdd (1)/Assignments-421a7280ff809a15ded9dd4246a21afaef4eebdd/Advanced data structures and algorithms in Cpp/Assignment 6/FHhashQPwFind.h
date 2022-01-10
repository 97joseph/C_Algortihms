#ifndef FHHASHQPWFIND_H
#define FHHASHQPWFIND_H
#include "FHhashQP.h"

using namespace std;


/*
This is a derived class from the FHhashQP base class.
It is used as a modified version of the base class
due to it's find member function.



class NotFoundException {}
An exception class thrown when an object is not found


const Object find(const KeyType & key)
pre-conditions: Takes in a key to be found
which will be supplied by the client's getKey
member function.
post-conditions: Will throw an exception if the
object is not found or will return the found object.

int myHashKey(const KeyType & key) const
pre-conditions: Takes a key of any type to be processed by the function.
post-conditions: This key is then hashed and returned as in int value.

int findPosKey( const KeyType & key ) const
pre-conditions: Takes a key of any type to be processed by the function.
post-conditions: Returns the index position of the key .


*/










template <class Object, typename KeyType>
class FHhashQPwFind: public FHhashQP<Object> {

	
	
	public:
		
		class NotFoundException {};
		
		//-------------------------------------------------------------
		const Object find(const KeyType & key);
		//returns the found object, or throws a NotFoundException  if it isn't there.
		//  You will have to add a NotFoundException to the class.
		//--------------------------------------------------------------
	
	
	protected:
		
		int myHashKey(const KeyType & key) const;
		// - a trivial modification to myHash() which uses the key rather than the object, to hash.
		int findPosKey( const KeyType & key ) const;
		// - a trivial modification to findPos() which uses the key rather than the object, to get a position.
};


template <class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::myHashKey(const KeyType & key) const{

	int hashVal;
	
	//Key rather than object(x)
    hashVal = Hash(key) % this->mTableSize;
    if(hashVal < 0){
    	hashVal += this->mTableSize;
	}
    	
   return hashVal;
}




template <class Object, typename KeyType>
int FHhashQPwFind<Object, KeyType>::findPosKey( const KeyType & key ) const{
	//a trivial modification to findPos() which uses the key rather than the object, to get a position.
	
	int kthOddNum = 1;
	int index = myHashKey(key);
	
	while ( this->mArray[index].state != FHhashQP<Object>::EMPTY
		&& getKey(this->mArray[index].data) != key ){
		index += kthOddNum; 
		kthOddNum += 2;   
		
		if ( index >= this->mTableSize ){
			index -= this->mTableSize;
		}
	}
	
	return index;
}



template <class Object, typename KeyType>
const Object FHhashQPwFind<Object, KeyType>::find(const KeyType & key){
	//calls findPosKey to return the index of the key in mArray
	typename FHhashQP<Object>::HashEntry searchResult= this->mArray[findPosKey(key)];
	
	//If state is active then return the data else throw the exception
	if (searchResult.state == FHhashQP<Object>::ACTIVE) {
    	return searchResult.data;
	}
   else {
    	throw NotFoundException();
	}
	
}


#endif
