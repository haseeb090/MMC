#include <iostream>
#include <time.h>

//Haseeb Khizar BSCS-3B Reg #4624

using namespace std;

class matrix { //matrix class

public:
	int rows;
	int col;
	int** mat; //2D Dynamic array

	matrix(int r, int c) { //Array initialization
		this->rows = r;
		this->col = c;
		this->mat = new int*[r];
		for (int i = 0;i < r; i++) {
			this->mat[i] = new int[c];
		}
	}
	void inputmat() { // Matrix values generation
		srand(time(NULL)); //random number seed time to get different value everytime rand is called
		for (int i = 0; i < this->rows;i++) {
			for (int j = 0;j < this->col; j++) {
				this->mat[i][j] = rand()%1000; //random number generation limit 1000
			}
		}
	}
	matrix* iterativemul(matrix* b) { //iterative multiplication
		matrix* c = new matrix(b->col, this->rows); //new matrix to store product in and later return

		for (int i = 0; i < this->rows;i++) {
			for (int j = 0; j < b->col; j++) {
				int sum = 0;
				for (int k = 0; k < this->col;k++) {
					sum = sum + (this->mat[i][k] * b->mat[k][j]);
				}
				c->mat[i][j] = sum;
			}
		}
		return c;
	}
	matrix* strassenmul(matrix* b) {
		matrix* c = new matrix(b->col, this->rows);
	}
	void printmat() {
		for (int i = 0; i < this->rows;i++) {
			for (int j = 0; j < this->col;j++) {
				cout << this->mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};
