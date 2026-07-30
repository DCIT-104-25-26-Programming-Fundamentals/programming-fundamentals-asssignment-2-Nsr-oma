// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

C++
#include <iostream>

using namespace std;

// Function Prototypes
void printFibonacciTerms(int n);
bool isFibonacciNumber(long long target);

int main() {
    int choice;

    cout << "1. Print First N Terms\n";
    cout << "2. Check if a Number is Fibonacci\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many terms? ";
        cin >> n;

        if (n <= 0) {
            cout << "Error: Number must be positive." << endl;
        } else {
            printFibonacciTerms(n);
        }

    } else if (choice == 2) {
        long long num;
        cout << "Enter a number to check: ";
        cin >> num;

        if (num >= 0 && isFibonacciNumber(num)) {
            cout << num << " is a Fibonacci number." << endl;
        } else {
            cout << num << " is NOT a Fibonacci number." << endl;
        }

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

// PART A: Prints first N Fibonacci terms
void printFibonacciTerms(int n) {
    long long a = 0, b = 1;
    
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// PART B: Checks if target is in the sequence
bool isFibonacciNumber(long long target) {
    long long a = 0, b = 1;
    
    while (a < target) {
        long long next = a + b;
        a = b;
        b = next;
    }
    
    return (a == target);
}