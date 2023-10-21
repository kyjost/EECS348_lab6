/*
Ky Jost 
3070792
EECS 348 Lab 6 
19 October 2023
This program reads a file and returns matrixes based on the data enclosed. 
*/
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

int main() {
    //This part opens the file and loads the numbers to a matrix 
    char size[100]; 

    std::ifstream mat; 
    mat.open("matrix_input.txt"); 

    mat >> size; 
    int n = size[0] - '0'; 

    char matA[100][100]; 

    for(int i = 0; i < n*n; i++) {
        mat >> matA[i]; 
    }

    char matB[100][100]; 

    for(int i = 0; i < n*n; i++) {
        mat >> matB[i]; 
    }
    mat.close(); 

    //This part creates two matrices with the proper numbers 
    int matrixA[n][n]; 
    int matrixB[n][n]; 

    int num = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrixA[i][j] = atoi(matA[num]); 
            num++; 
        }
    }

    num = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrixB[i][j] = atoi(matB[num]); 
            num++; 
        }
    }

    //This part does the math 
    int matrixSum[n][n]; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j]; 
        }
    }

    int matrixProduct[n][n]; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp1 = matrixA[i][0] * matrixB[0][j]; 
            int temp2 = matrixA[i][1] * matrixB[1][j]; 
            int temp3 = matrixA[i][2] * matrixB[2][j]; 
            matrixProduct[i][j] = temp1 + temp2 + temp3; 
        }
    }

    int matrixDifference[n][n]; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrixDifference[i][j] = matrixA[i][j] - matrixB[i][j]; 
        }
    }

    //This part will give the actual output 
    cout << "Ky Jost" << endl; 
    cout << "Lab #6: Matrix manipulation" << endl; 
    cout << "\n"; 

    cout << "Matrix A: " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrixA[i][j]; 
            cout << " "; 
        }
        cout << "\n"; 
    }

    cout << "\n"; 

    cout << "Matrix B: " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrixB[i][j]; 
            cout << " "; 
        }
        cout << "\n"; 
    }

    cout << "\n"; 

    cout << "Matrix Sum (A + B): " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrixSum[i][j]; 
            cout << " "; 
        }
        cout << "\n"; 
    }

    cout << "\n"; 

    cout << "Matrix Product (A*B): " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrixProduct[i][j]; 
            cout << " "; 
        }
        cout << "\n"; 
    }

    cout << "\n"; 

    cout << "Matrix Difference (A-B): " << endl; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrixDifference[i][j]; 
            cout << " "; 
        }
        cout << "\n"; 
    }
}