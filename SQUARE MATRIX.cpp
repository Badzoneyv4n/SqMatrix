#include <iostream>
#include <vector>

using namespace std;

bool isMagicSquare(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Calculate the sum of the first row (or column) to use it as a reference for comparison
    int sumReference = 0;
    for (int i = 0; i < n; i++) {
        sumReference += matrix[0][i];
    }

    // Check row sums
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sumReference) {
            return false;
        }
    }

    // Check column sums
    for (int i = 0; i < n; i++) {
        int colSum = 0;
        for (int j = 0; j < n; j++) {
            colSum += matrix[j][i];
        }
        if (colSum != sumReference) {
            return false;
        }
    }

    // Check main diagonal sum
    int mainDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonalSum += matrix[i][i];
    }
    if (mainDiagonalSum != sumReference) {
        return false;
    }

    // Check secondary diagonal sum
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }
    if (secondaryDiagonalSum != sumReference) {
        return false;
    }

    // If all checks passed, the matrix is a magic square
    return true;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    if (isMagicSquare(matrix)) {
        cout << "The matrix is a magic square." << endl;
    } else {
        cout << "The matrix is not a magic square." << endl;
    }

    return 0;
}
