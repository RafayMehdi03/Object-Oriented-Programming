#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int** arr, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100 + 1;
        }
    }
}
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void sumArray(int** arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
    }
    cout << "Total sum: " << sum << endl;
}
void rowColumnSums(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i+1 << ": " << rowSum << endl;
    }
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += arr[i][j];
        }
        cout << "Sum of column " << j+1 << ": " << colSum << endl;
    }
}
void highestRowColumnSum(int** arr, int rows, int cols) {
    int maxRowSum = -1, maxColSum = -1;
    int maxRow = -1, maxCol = -1;
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum += arr[i][j];
        }
        if (rowSum > maxRowSum) {
            maxRowSum = rowSum;
            maxRow = i;
        }
    }
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += arr[i][j];
        }
        if (colSum > maxColSum) {
            maxColSum = colSum;
            maxCol = j;
        }
    }
    
    cout << "Row with highest sum: " << maxRow+1 << " (Sum: " << maxRowSum << ")" << endl;
    cout << "Column with highest sum: " << maxCol+1 << " (Sum: " << maxColSum << ")" << endl;
}

int transposeArray(int** arr, int rows, int cols) {
    int** transposed = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
    }
    if (!transposed) {
        cerr << "Memory allocation failed for transposed array!" << endl;
        return 0 ;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = arr[i][j];
        }
    }
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < cols; ++i) {
        delete[] transposed[i];
    }
    delete[] transposed;
}

int main() {
    int rows, cols ;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    if (!arr) {
        cout << "Memory allocation failed for array!" << endl;
        return 0 ;
    }
    fillArray(arr, rows, cols);
    printArray(arr, rows, cols);
    sumArray(arr, rows, cols);
    rowColumnSums(arr, rows, cols);
    highestRowColumnSum(arr, rows, cols);
    transposeArray(arr, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
