#include <iostream>
using namespace std;

const int SIZE = 4;

class Matrix{
    private:
        int data[SIZE][SIZE];
    
    public:
        void readFromStdin();
        //void display() const;
        //Matrix operator+(const Matrix& other) const;
        //int sumOfDiagonals() const;
        //void swapRows(int row1, int row2);
};

void Matrix::readFromStdin(){
    //atoi(char arr)
    cout << "Enter individual elements of array: " << endl;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cin >> data[i][j];
        }
    }
}

int main(){
    Matrix m1;
    Matrix m2;
    cout << "Enter numbers for matrix 1: " << endl;
    m1.readFromStdin();
    cout << "Enter numbers for matrix 2: " << endl;
    m2.readFromStdin();
}
