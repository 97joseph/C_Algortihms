#ifndef boolMatrix_H
#define boolMatrix_H

class boolMatrix {
	
	public:
		static const int NUM_ROWS = 20;
		static const int NUM_COLS = 20;
		boolMatrix();
		bool get(int row, int column) const;
		void set(int row, int column, bool element_value);
		int rowCount(int row) const;
		int colCount(int column) const;
		int totalCount() const;
		void print() const;
		
	private:
		bool gridMatrix[NUM_ROWS][NUM_COLS];
	
};

#endif
