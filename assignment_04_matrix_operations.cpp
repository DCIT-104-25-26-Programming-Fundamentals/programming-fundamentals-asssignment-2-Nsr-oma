// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

C++
#include <iostream>
#include <iomanip> // Needed for setw()

using namespace std;

// Maximum size constraint required by assignment
const int MAX_SIZE = 10;

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int output[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P);

int main() {
    int choice;

    cout << "========================================\n";
    cout << "       MATRIX OPERATIONS CALCULATOR     \n";
    cout << "========================================\n";
    cout << "1. Part A: Transpose a Matrix\n";
    cout << "2. Part B: Add Two Matrices\n";
    cout << "3. Part C: Multiply Two Matrices\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A: TRANSPOSE ---
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        cout << "\n--- Part A: Transpose Matrix ---\n";
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        inputMatrix(matrix, rows, cols);

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrix, rows, cols);

        transposeMatrix(matrix, transposed, rows, cols);

        cout << "\nTransposed Matrix:\n";
        displayMatrix(transposed, cols, rows); // Dimensions swap for transpose

    } else if (choice == 2) {
        // --- PART B: ADDITION ---
        int rows, cols;
        int matrixA[MAX_SIZE][MAX_SIZE];
        int matrixB[MAX_SIZE][MAX_SIZE];
        int sum[MAX_SIZE][MAX_SIZE];

        cout << "\n--- Part B: Add Matrices ---\n";
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nMatrix A:\n";
        inputMatrix(matrixA, rows, cols);

        cout << "\nMatrix B:\n";
        inputMatrix(matrixB, rows, cols);

        addMatrices(matrixA, matrixB, sum, rows, cols);

        cout << "\nSum Result (A + B):\n";
        displayMatrix(sum, rows, cols);

    } else if (choice == 3) {
        // --- PART C: MULTIPLICATION ---
        int M, N, N_B, P;
        int matrixA[MAX_SIZE][MAX_SIZE];
        int matrixB[MAX_SIZE][MAX_SIZE];
        int product[MAX_SIZE][MAX_SIZE];