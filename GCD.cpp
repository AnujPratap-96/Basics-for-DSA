#include<bits/stdc++.h>

using namespace std;

//? Brute Force: Find GCD using iteration from 1 to min(x, y)
int GCDBruteForce(int x, int y) {
    int gcd = 1;
    // Iterate from 1 to min(x, y) to find the greatest common divisor
    for (int i = 1; i <= min(x, y); i++) {
        if ((x % i == 0) && (y % i == 0)) {
            gcd = i;  // Update gcd if i is a common divisor
        }
    }
    return gcd;
}

//? Better Approach: Find GCD by iterating from min(x, y) down to 1
int GCDBetter(int x, int y) {
    int gcd = 1;
    // Iterate from min(x, y) down to 1 to find the greatest common divisor
    for (int i = min(x, y); i >= 1; i--) {
        if ((x % i == 0) && (y % i == 0)) {
            gcd = i;  // Update gcd if i is a common divisor
            break;    // Exit loop once the greatest common divisor is found
        }
    }
    return gcd;
}

//! Optimal Approach: Euclidean Algorithm for finding GCD
int GCDOptimal(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;  // Reduce a by the remainder of a divided by b
        } else {
            b = b % a;  // Reduce b by the remainder of b divided by a
        }
    }
    // Return the non-zero value which is the GCD
    return (a == 0) ? b : a;
}

int main() {
    int m, n;
    cout << "Enter two numbers: ";
    cin >> m >> n;

    // Uncomment to use the brute force method
    // cout << "The GCD of " << m << " and " << n << " is " << GCDBruteForce(m, n) << endl;

    // Uncomment to use the better approach
    // cout << "The GCD of " << m << " and " << n << " is " << GCDBetter(m, n) << endl;

    // Optimal approach using the Euclidean Algorithm
    cout << "The GCD of " << m << " and " << n << " is " << GCDOptimal(m, n) << endl;

    return 0;
}
