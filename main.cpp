#include <iostream>
using namespace std;

const int SIZE = 4;

class Matrix{
    private:
        int data[SIZE][SIZE];
    
    public:
        void readFromStdin();
        void display() const;
        Matrix operator+(const Matrix& other) const{
		Matrix ms;
		int sum1;
		int sum2;
		int sumM;
		for(int i = 0; i < SIZE; i++){
			for(int j = 0; j < SIZE; j++){
				sum1 = this->data[i][j];
				sum2 = other.data[i][j];
				sumM = sum1 + sum2;
				ms.data[i][j] = sumM;
			}
		}
		ms.display();
		return ms;
	}

        //int sumOfDiagonals() const;
        //void swapRows(int row1, int row2);
};

void Matrix::readFromStdin(){
    cout << "Enter individual elements of array: " << endl;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            char element[10];
            cin >> element;
            data[i][j] = atoi(element);
        }
    }
}

void Matrix::display() const{
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
    Matrix m1;
    Matrix m2;
    cout << "Enter numbers for matrix 1: " << endl;
    m1.readFromStdin();
    cout << "Enter numbers for matrix 2: " << endl;
    m2.readFromStdin();
    m1 + m2;
}
