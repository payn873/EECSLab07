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

	Matrix operator*(const Matrix& other) const{
		Matrix mp;
		int pM = 0;
		for(int i = 0; i < SIZE; i++){
			for(int j = 0; j < SIZE; j++){
				for(int k = 0; k < SIZE; k++){
					pM += this->data[i][k] * other.data[k][j];
				}
				mp.data[i][j] = pM;
				pM = 0;
			}
		}
		mp.display();
		return mp;
	}

        int sumOfDiagonals() const;
        void swapRows(int row1, int row2);
};

void Matrix::swapRows(int row1, int row2){
	if(row1 < SIZE && row2 < SIZE){
		int temp[SIZE];
		for(int i = 0; i < SIZE; i++){
			temp[i] = data[row1][i];
			data[row1][i]  = data[row2][i];
			data[row2][i] = temp[i];
		}
	}
	display();
}

int Matrix::sumOfDiagonals() const{
	int sum = 0;
	for(int i = 0; i < SIZE; i++){
		sum += data[i][i];
	}
	return sum;
}

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
    m1.display();
    cout << "Enter numbers for matrix 2: " << endl;
    m2.readFromStdin();
    m2.display();
    cout << "Sum of Matrix 1 and Matrix 2: " << endl;
    m1 + m2;
    cout << "Product of Matrix 1 and Matrix 2: " << endl;
    m1 * m2;
    cout << "Sum of Diagonals of Matrix 1: " << m1.sumOfDiagonals() << endl;
    cout << "Sum of Diagonals of Matrix 2: " << m2.sumOfDiagonals() << endl;
    cout << "Swaping Rows of Index 0 and 1 of Matrix 1: " << endl;
    m1.swapRows(0,1);
    cout << "Swaping Rows of Index 3 and 1 of Matrix 2: " << endl;
    m2.swapRows(3,1);
}
