#include<bits/stdc++.h>

using namespace std;

//? Function to calculate x raised to the power n (x^n) using exponentiation by squaring
double power(double x, int n) {
    int pow = abs(n);  // Take the absolute value of n to handle negative exponents
    double ans = 1;    // Initialize result
    
    // Exponentiation by squaring
    while (pow > 0) {
        if (pow % 2 == 1) {      // If pow is odd, multiply the result by x
            ans *= x;
            pow--;               // Decrement pow
        } else {
            pow /= 2;            // Halve pow
            x *= x;              // Square x
        }
    }
    
    // If the exponent is negative, return the reciprocal
    if (n < 0) {
        return 1.0 / ans;
    }
    return ans;
}

int main() {
    // Example usage
    cout << power(5, 5) << endl;  // Should print 3125
    return 0;
}
