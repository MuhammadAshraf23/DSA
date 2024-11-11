#include <iostream>
using namespace std;

// Factorial function with input validation
int factorial(int num) {
    if (num < 0) {  // Factorial is undefined for negative numbers-7
        cout << "Factorial is undefined for negative numbers." << endl;
        return -1;  // Return -1 to indicate an error
    }
    if (num == 1||num==0)
        return 1;
    int result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}


// Function to calculate combination (nCr)
int combination(int n, int r) {
   if (r > n || n < 0 || r < 0) {  // Invalid case if r > n or negative numbers
        cout << "Invalid input! r cannot be greater than n, and n, r must be non-negative." << endl;
        return -1;  // Return -1 to indicate an error
    } 
    else {
        return factorial(n) / (factorial(r) * factorial(n - r)); 
    }
}

int main() {
   int n, r;
    cout << "Enter the total number of items (n): ";
    cin >> n;
    cout << "Enter the number of items to choose (r): ";
    cin >> r;

    int y = combination(n, r);
    cout << "The number of combinations (C(" << n << ", " << r << ")) is: " << y << endl;

    return 0;
}