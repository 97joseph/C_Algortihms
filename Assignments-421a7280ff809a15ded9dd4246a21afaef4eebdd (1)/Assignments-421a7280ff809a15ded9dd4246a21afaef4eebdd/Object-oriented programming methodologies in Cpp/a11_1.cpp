#include <iostream>
#include "boolMatrix.cpp"
#include <fstream>

const int FINAL_ROW_AND_COL_LIVING_CELLS = 10;




bool onGrid(int row, int column) {
	
	return (((row < boolMatrix::NUM_ROWS) and (row >= 0 )) and
		 	((column < boolMatrix::NUM_COLS) and (column >= 0)));
}



int countNeighbors(const boolMatrix& life, int row, int col) {
    int count = 0;
    for (int rowCount = row-1; rowCount <= row+1; rowCount++){
        for (int colCount = col-1; colCount <= col+1; colCount++){
            if (onGrid(rowCount, colCount) && life.get(rowCount, colCount)){
                count++;
            }
        }
    }

    if (life.get(row, col)){	   //because we counted life[row][col] as a neighbor
        count--;
    }

    return count;
}




void loadFirstGenData(boolMatrix& life){
	string fileName;
	int row;
	int column;
	ifstream infile;
	
	cout << "Enter the name of a file: ";
	cin >> fileName;
	
	infile.open((fileName).c_str());
		
		if (!infile) {
			cout << "couldn't open file." << endl;
		}
		
		else {
		    
		    while (infile){                    
		        infile >> row >> column;
		        //cout << row << " " << column << endl;
		        life.set(row, column, true);
    		}	
		  }
	
		infile.close();
		
		
}

void deadCell_SetNextGen(const boolMatrix& life, boolMatrix& nextGen, int row, int column){
	
	if (countNeighbors(life, row,  column) == 3){
		nextGen.set(row, column, true);
	}
	else{
		nextGen.set(row, column, false);
	}
}






void livingCell_SetNextGen(const boolMatrix& life, boolMatrix& nextGen, int row, int column){
	
	if (countNeighbors(life, row,  column) == 0){
		nextGen.set(row, column, false);
	}
	
	else if (countNeighbors(life, row,  column) >= 4){
		nextGen.set(row, column, false);
	}
		
	else if (countNeighbors(life, row,  column) == 2
			or countNeighbors(life, row,  column) == 3 ){
		nextGen.set(row, column, true);
	}
}


void generateNextGenGrid(const boolMatrix& life, boolMatrix& nextGen) {
	int row;
	int column;
	
	for (int row = 0; row < boolMatrix::NUM_ROWS; row++){
        for (int column = 0; column < boolMatrix::NUM_COLS; column++){
        	
        	if(life.get(row,column)){
        		livingCell_SetNextGen(life, nextGen, row, column);
			}
			
			else{
				deadCell_SetNextGen(life, nextGen, row, column);
			}
        }
    }
}






void transferGrids(boolMatrix& life, boolMatrix& nextGen){
	int row;
	int column;
	
	generateNextGenGrid(life, nextGen);
	
	for(row = 0; row < boolMatrix::NUM_ROWS; row++) {
		for(column = 0; column < boolMatrix::NUM_COLS; column++) {
			life.set(row, column, nextGen.get(row,column));
			nextGen.set(row, column, false);
		}
	}

}






void playGameOfLife(int num_of_times, boolMatrix& life, boolMatrix& nextGen) {
	int count;
	
	for(count = 0; count < num_of_times; count++) {
		transferGrids(life, nextGen);
	}
	
}






int main() {
	boolMatrix life;
	boolMatrix nextGeneration;
	int num_of_times;
	
	loadFirstGenData(life);	
	cout << "Enter number of generations: ";
	cin >> num_of_times;
	cout << endl;
	
	playGameOfLife(num_of_times, life, nextGeneration);
	
	life.print();
	
	cout << "Total alive in row "
		 << FINAL_ROW_AND_COL_LIVING_CELLS
		 << " = " << life.rowCount(FINAL_ROW_AND_COL_LIVING_CELLS) << endl;
	cout << "Total alive in col "
		 << FINAL_ROW_AND_COL_LIVING_CELLS
		 << " = " << life.colCount(FINAL_ROW_AND_COL_LIVING_CELLS) << endl;
	
	cout << "Total alive = " << life.totalCount();
	
	
}

/*
Output 1:

Enter the name of a file: life.txt
Enter number of generations: 5

  01234567890123456789
 0
 1         *        *
 2       *   * ***  *
 3       *   **** *
 4      *  * *    **
 5    *  *   *****  *
 6 ** *     *    *** *
 7    * ***       *  *
 8               ****
 9 *         ******
10* *          *
11   *  *      **   *
12**    ****       ***
13  *         *** ** *
14      *  *   *   ***
15 **   ***      ** **
16      *         * **
17
18
19
Total alive in row 10 = 1
Total alive in row 10 = 3
Total alive = 95

Output 2:

Enter the name of a file: life.txt
Enter number of generations: 8

  0123456789012345678901
 0
 1         **     *
 2         * *   ** *
 3       **        *
 4    **** * *   **
 5    **  * ** ** *
 6   *      ***
 7    **  *  * *
 8     ***   * *
 9 **        *  *
10* **        *   * **
11* ** ** **  * * *
12*   *   *** *       *
13* *        ***  * *
14 *      ***  **   *
15        *     *      *
16     * *      *  ** *
17      *         *
18
19
20
Total alive in row 10 = 5
Total alive in row 10 = 7
Total alive = 94
*/
