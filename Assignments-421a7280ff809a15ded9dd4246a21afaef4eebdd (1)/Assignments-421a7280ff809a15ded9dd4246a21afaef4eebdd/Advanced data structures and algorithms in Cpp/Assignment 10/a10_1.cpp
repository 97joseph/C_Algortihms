#include <iostream>
#include <string> 
#include <cstdlib>
#include "StarNearEarth.h"
#include "StarNearEarth.cpp"
#include "FHsparseMat.h"
#include <math.h>


using namespace std;

#define LY_CONST 3.262
#define PI 3.14159265358979

/*
Name: Dillon Pinto
Date: 12/3/2016
Description: Completed SNE_ANALYZER class
			 with client program to display
			 coordinates. The client program
			 uses "FHsparseMat" to store all
			 data points in a sparse matrix
			 which allows the program to
			 save space.
*/







//Global functions for use in client--------
string stringify(double f) {
    stringstream ss;
    ss << f;
    return ss.str();
}

//specifically for use of int's 1-9 in the client program
char charify(int i) {
    stringstream ss;
    ss << i;
    return ss.str()[0];
}

//---------------------------------

class SNE_Analyzer: public StarNearEarth {
	
	private:
	   double x, y, z;
	
	
	public:
	
		void calcCartCoords();
		double getX() { return x; }
		double getY() { return y; }
		double getZ() { return z; }
		string coordToString();
		SNE_Analyzer & operator=( const StarNearEarth &sne );
};

void SNE_Analyzer::calcCartCoords(){
   double RA_rad = (this->getRAsc()) * (PI/180.0);
   double DEC_rad= (this->getDec()) * (PI/180.0);
   double LY = LY_CONST / (this->getParallaxMean());
   
   
   x= LY * cos(DEC_rad) * cos(RA_rad);
   y=LY * cos(DEC_rad) * sin(RA_rad);
   z=LY * sin(DEC_rad);
   
}


string SNE_Analyzer::coordToString() {
	
	string coordinates = "\tX: "+ stringify(x) + "  Y: " + stringify(y)+"   Z: " +stringify(z)+"\n";
	return coordinates;
}







SNE_Analyzer & SNE_Analyzer::operator=( const StarNearEarth &sne ) {
	setRank(sne.getRank()); 
	setNameCns(sne.getNameCns());
	setNumComponents(sne.getNumComponents());
	setNameLhs(sne.getNameLhs());
	setRAsc(sne.getRAsc());
	setDec(sne.getDec());
	setPropMotionMag(sne.getPropMotionMag());
	setPropMotionDir(sne.getPropMotionDir());
	setParallaxMean(sne.getParallaxMean());
	setParallaxVariance(sne.getParallaxVariance());
	setWhiteDwarfFlag(sne.getWhiteDwarfFlag());
	setSpectralType(sne.getSpectralType());
	setMagApparent(sne.getMagApparent());
	setMagAbsolute(sne.getMagAbsolute());
	setMass(sne.getMass());
	setNotes(sne.getNotes());
	setNameCommon(sne.getNameCommon()); 
	calcCartCoords();
	
	return *this;
}






















// --------------- main ---------------
int main()
{
	string outString, longBlankString
	  = "                                         "
	    "                                         ";
	char star_char;
	int k, arraySize, row, col;
	double maxX, minX, maxY, minY, maxZ, minZ,
	  xRange, yRange, zRange, 
	  xConversion, yConversion, zConversion;
	StarNearEarthReader starInput("nearest_stars.txt");
	const int NUM_COLS = 70;
   const int NUM_ROWS = 35;

   if (starInput.readError())
   {
      cout << "couldn't open " << starInput.getFileName() << " for input.\n";
      exit(1);
   }

   cout << starInput.getFileName() << endl;
   cout << starInput.getNumStars() << endl;

   // create an array of objects for our own use:
   arraySize = starInput.getNumStars();
   SNE_Analyzer *starArray = new SNE_Analyzer[arraySize];
   
   for (k = 0; k < arraySize; k++)
      starArray[k] =  starInput[k];

   // display cartesian coords
   for (int k = 0; k < arraySize; k++)
      cout << starArray[k].getNameCommon() << " " 
         << starArray[k].coordToString() << endl;

   // get max and min coords for scaling
   maxX = minX = maxY = minY = maxZ = minZ = 0;
    for (int k = 0; k < arraySize; k++){
   	
   	
   	
   	
		double x = starArray[k].getX();
    	if (x > maxX) {
         maxX=x;
      	}
      	
	  	else if (x < minX) {
         minX =x;
      	}
	  
	  
	  
	  
		double y = starArray[k].getY();
	    if (y > maxY) {
	        maxY=y;
	    }
		else if (y < minY){
	         minY=y;
		}
	      
	      
	      
	      
	      
	      
		double z = starArray[k].getZ();
      	if (z > maxZ) {
        	maxZ= z;
		}
		else if (z < minZ){
    		minZ = z;
		}      	
   	}
   	
   	
   	
   	
   	
   	
	xRange = maxX - minX;
	yRange = maxY - minY;
	zRange = maxZ - minZ;

	xConversion =NUM_COLS/xRange;
	yConversion =NUM_ROWS/yRange;
	zConversion =NUM_ROWS/zRange;
	



   SparseMat<char> starMap(NUM_ROWS, NUM_COLS, ' ');


	
   for (k = 0; k <arraySize ; k++)
   {
      row = round(starArray[k].getY() - minY)*(yConversion);
      col = round(starArray[k].getX() - minX)*(xConversion);
      
      //with inclusion of z axis, commented out to avoid overwriting
	  //row = round(starArray[k].getZ() - minZ)*(zConversion);
      if ( k<9 )
         starMap.set(row, col, charify(k+1));//Charify converts ints to characters
         
      //Extra conditions added to make sure values aren't overwritten and exception isn't thrown for the .get() function
      else if( k>9 and row< NUM_ROWS and col < NUM_COLS and starMap.get(row, col) ==*" " )
      	 
         starMap.set(row, col, *"*");
   }

   row = NUM_ROWS / 2;
   col = NUM_COLS / 2;
   starMap.set( row, col, 'S');




   for (row = 0; row < NUM_ROWS; row++)
   {
      outString = longBlankString.substr(0, NUM_COLS);
      for (col = 0; col < NUM_COLS; col++){
      	star_char = starMap.get(row, col);
         if (star_char != *" "){
            outString[col] = star_char;
	}
	  }
      cout << outString << endl;
   }

   delete[] starArray;  
   
   return 0;
}



/*
Star map output:



                          *
                                               *
                             *      *
             *
                          *             *         *
             *                 *             *    *
          *  *      *      *      *               *      *
                           *
                                 **
                                        7    *
          *
                                    2 * *  *   ** *
                                  *   *
                                                      **    *
        *                                      *
*           *                                          *             *
                                 1              8                    *
                 *      *    *     S              *    *      *    *
                      3 4                             *
                 * *                            6           *
            *             *                            *
   *                *                                 *
            *
                    *   *        5           * 9  * *    *
                                        **
            *              *
                 *         *                    *   *

                                 *
            *              * *                  *

                    *             * *      *      *
                                        *
                                      *





Star data output:
nearest_stars.txt
100
Proxima Centauri        X: -1.54629  Y: -1.18348   Z: -3.76934

Barnard's Star  X: -0.056838  Y: -5.94339   Z: 0.487961

Wolf 359        X: -7.43033  Y: 2.11355   Z: 0.950536

Lalande 21185   X: -6.50637  Y: 1.64224   Z: 4.87005

Sirius  X: -1.60906  Y: 8.06202   Z: -2.46895

BL Ceti         X: 7.54093  Y: 3.47728   Z: -2.69018

Ross 154        X: 1.91024  Y: -8.64808   Z: -3.91287

Ross 248        X: 7.38061  Y: -0.583729   Z: 7.19346

epsilon Eridani         X: 6.21307  Y: 8.31501   Z: -1.72923

Lacaille 9352   X: 8.46565  Y: -2.03763   Z: -6.29226

Ross 128        X: -10.9032  Y: 0.583818   Z: -0.153313

EZ Aquarii A    X: 10.1892  Y: -3.7814   Z: -2.97361

Procyon         X: -4.76796  Y: 10.3068   Z: 1.03849

61 Cygni A      X: 6.47533  Y: -6.0968   Z: 7.13794

(no common name)        X: 1.08144  Y: -5.72632   Z: 9.94485

GX Andromedae   X: 8.33256  Y: 0.669751   Z: 8.07912

epsilon Indi A  X: 5.65677  Y: -3.15623   Z: -9.89375

DX Cancri       X: -6.42159  Y: 8.38202   Z: 5.32847

tau Ceti        X: 10.2728  Y: 5.01418   Z: -3.26436

Henry et al. 1997, Henry et al. 2006    X: 5.02666  Y: 6.91829   Z: -8.40731

YZ Ceti         X: 11.0276  Y: 3.61023   Z: -3.5473

Luyten's Star   X: -4.58412  Y: 11.431   Z: 1.12643

Henry et al. 2006       X: 8.72279  Y: 8.20666   Z: 3.63449

Henry et al. 2006       X: 1.07874  Y: -5.4123   Z: -11.2968

Kapteyn's Star  X: 1.89052  Y: 8.83291   Z: -9.03874

AX Microscopii  X: 7.59934  Y: -6.53329   Z: -8.07708

Kruger 60 A     X: 6.46881  Y: -2.74612   Z: 11.1147

Jao et al. 2005, Costa et al. 2005      X: -9.60648  Y: 3.10998   Z: -8.45318

Ross 614 A      X: -1.70526  Y: 13.2247   Z: -0.655389

Wolf 1061       X: -5.14419  Y: -12.4656   Z: -3.02977

van Maanen's Star       X: 13.6844  Y: 2.9815   Z: 1.3211

(no common name)        X: 11.3095  Y: 0.266851   Z: -8.63585

Wolf 424 A      X: -13.9874  Y: -2.04595   Z: 2.24423

TZ Arietis      X: 12.2352  Y: 7.07964   Z: 3.27708

(no common name)        X: -0.560574  Y: -5.43191   Z: 13.7496

(no common name)        X: -13.8117  Y: 4.4737   Z: -2.91082

(no common name)        X: -1.37941  Y: -10.026   Z: -10.8132

G 208-044 A     X: 5.04504  Y: -9.30115   Z: 10.3675

WD 1142-645     X: -6.39085  Y: 0.398859   Z: -13.6332

(no common name)        X: 15.1756  Y: 0.445762   Z: -2.0094

Ross 780        X: 14.2453  Y: -4.26849   Z: -3.78053

Henry et al. 2006       X: -7.11261  Y: 2.43681   Z: -13.6817

(no common name)        X: -11.1567  Y: 2.70545   Z: 10.9043

(no common name)        X: -9.16721  Y: 4.7028   Z: 12.0439

(no common name)        X: -13.5785  Y: 6.36013   Z: 5.41878

(no common name)        X: 8.47021  Y: -6.29244   Z: -12.1422

(no common name)        X: 7.58939  Y: 10.7973   Z: -9.38886

Costa et al. 2005       X: 7.97626  Y: 7.63972   Z: -11.85

(no common name)        X: -1.16803  Y: -11.6311   Z: -11.415

omicron 2 Eridani       X: 7.16813  Y: 14.5791   Z: -2.18291

EV Lacertae     X: 11.1863  Y: -3.69797   Z: 11.5109

70 Ophiuchi A   X: 0.395798  Y: -16.6257   Z: 0.726099

Altair  X: 7.68313  Y: -14.6368   Z: 2.57929

EI Cancri       X: -11.2661  Y: 11.4397   Z: 5.76843

Henry et al. 2006       X: -0.00434369  Y: 17.0657   Z: 0.80679

Henry et al. 2006       X: 4.31746  Y: 16.6814   Z: -2.09934

(no common name)        X: -3.4371  Y: 0.184793   Z: 17.2119

Wolf 498        X: -15.3243  Y: -7.61788   Z: 4.55075

(no common name)        X: 11.7114  Y: -12.4986   Z: -5.22833

Stein 2051      X: 3.51678  Y: 8.61724   Z: 15.4759

(no common name)        X: -3.59809  Y: 14.7553   Z: 9.96432

(no common name)        X: 2.40017  Y: -15.3133   Z: 10.0653

Wolf 1453       X: 2.30849  Y: 18.4396   Z: -1.19433

(no common name)        X: 8.13688  Y: 16.5576   Z: -3.1181

sigma Draconis  X: 2.56145  Y: -6.00814   Z: 17.6198

(no common name)        X: -0.806496  Y: 17.4633   Z: -7.0152

(no common name)        X: -0.60082  Y: -10.2413   Z: -15.9916

Wolf 1055       X: 6.25711  Y: -17.9373   Z: 1.71849

Ross 47         X: 1.45407  Y: 18.6368   Z: 4.14063

(no common name)        X: -12.7815  Y: -12.502   Z: -7.01238

Jao et al. 2005         X: 4.66587  Y: -12.6815   Z: -13.7781

(no common name)        X: 19.3195  Y: -0.910379   Z: 0.811

eta Cassiopei A         X: 10.083  Y: 2.19407   Z: 16.3959

(no common name)        X: -8.7523  Y: -11.6374   Z: -12.7814

(no common name)        X: 18.6028  Y: 1.25748   Z: -5.39363

Ross 882        X: -8.5697  Y: 17.4409   Z: 1.20642

36 Ophiuchi A   X: -3.3708  Y: -17.0825   Z: -8.72026

(no common name)        X: 8.6356  Y: -13.4   Z: -11.6253

82 Eridani      X: 9.28626  Y: 11.0597   Z: -13.4997

(no common name)        X: -0.336453  Y: -6.48031   Z: 18.7125

delta Pavonis   X: 4.28382  Y: -6.80742   Z: -18.2207

QY Aurigae A    X: -4.71164  Y: 14.9366   Z: 12.4713

HN Librae       X: -15.2876  Y: -12.1909   Z: -4.34181

(no common name)        X: -14.1713  Y: 10.1488   Z: 9.87189

(no common name)        X: -9.14765  Y: 8.06616   Z: 16.0018

(no common name)        X: 7.87021  Y: -11.903   Z: -14.3515

Wolf 562        X: -13.0814  Y: -15.5135   Z: -2.75169

EQ Pegasi       X: 19.2964  Y: -2.38041   Z: 7.05244

Henry et al. 2006       X: -13.6723  Y: 13.6255   Z: 7.73403

Henry et al. 2006       X: -16.0764  Y: -2.74932   Z: -12.9185

(no common name)        X: -3.02379  Y: -14.2661   Z: 14.926

(no common name)        X: -13.1994  Y: -12.8181   Z: -9.85069

(no common name)        X: -5.96815  Y: -14.644   Z: 13.6811

WD 0552-041     X: 0.443079  Y: 20.9847   Z: -1.53083

Wolf 630 A      X: -5.78606  Y: -20.007   Z: -3.05182

(no common name)        X: 11.2897  Y: -2.3337   Z: 17.8668

Jao et al. 2005         X: -6.34222  Y: 4.32745   Z: -19.8823

GL Virginis     X: -20.8614  Y: -1.7339   Z: 4.11654

(no common name)        X: -5.02956  Y: -11.4863   Z: 17.4528

Ross 104        X: -19.3406  Y: 5.17583   Z: 8.42975







*/
