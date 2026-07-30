// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>

using namespace std;

// Function prototypes
double calculateSum(const double arr[], int size);
double calculateAverage(const double arr[], int size);
double findMaximum(const double arr[], int size);
double findMinimum(const double arr[], int size);

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    // Input validation for N
    if (n <= 0) {
        cout << "Error: Number of elements must be a positive integer." << endl;
        return 1;
    }

    // Dynamic array allocation based on user input
    double* numbers = new double[n];

    // Read numbers from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers, n) << endl;
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << "Maximum: " << findMaximum(numbers, n) << endl;
    cout << "Minimum: " << findMinimum(numbers, n) << endl;

    // Free dynamically allocated memory
    delete[] numbers;

    return 0;
}

// Function to calculate the sum of array elements
double calculateSum(const double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate average using custom sum logic
double calculateAverage(const double arr[], int size) {
    return calculateSum(arr, size) / size;
}

// Function to find the maximum value in the array
double findMaximum(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum value in the array
double findMinimum(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}