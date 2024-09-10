#include<bits/stdc++.h>

using namespace std;

//? Brute Force: Print all divisors of a number.
void printDivisorsBruteForce(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }
}

//? Optimal Way: Print all divisors of a number using square root optimization.
void printDivisorsOptimal(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;         // Print the divisor
            if (i != n / i) {          // If the divisor is not the square root
                cout << n / i << endl;  // Print the corresponding divisor
            }
        }
    }
}

//* Function to check if a number is prime.
bool isPrime(int n) {
    if (n < 2) return false;  // Numbers less than 2 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;  // If divisible, it's not prime
        }
    }
    return true;  // Otherwise, it's prime
}

//? Brute Force: Find all prime divisors of a number.
void findPrimeDivisorsBruteForce(int x) {
    list<int> ans;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            if (isPrime(i)) {
                ans.push_back(i);
            }
        }
    }
    
    // Print the prime divisors
    for (auto a : ans) {
        cout << a << endl;
    }
}

//? Better Way: Find prime divisors using square root optimization.
void findPrimeDivisorsBetter(int x) {
    list<int> ans;
    
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            if (isPrime(i)) {
                ans.push_back(i);
            }
            // Check the corresponding divisor
            if (i != x / i && isPrime(x / i)) {
                ans.push_back(x / i);
            }
        }
    }
    
    // Print the prime divisors
    for (auto a : ans) {
        cout << a << endl;
    }
}

//! Optimal Way: Find prime divisors using trial division.
void findPrimeDivisorsOptimal(int x) {
    list<int> ans;
    
    // Check for prime factors from 2 to sqrt(x)
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            if (isPrime(i)) {
                ans.push_back(i);
                while (x % i == 0) {
                    x /= i;  // Remove all factors of i
                }
            }
        }
    }
    
    // If x is still greater than 1, it must be prime
    if (x > 1) {
        ans.push_back(x);
    }

    // Print the prime divisors
    for (auto a : ans) {
        cout << a << endl;
    }
}

int main() {
    int m;
    cout << "Enter a number: ";
    cin >> m;

    // Uncomment to use the brute force method to print all divisors
    // printDivisorsBruteForce(m);

    // Uncomment to use the optimal method to print all divisors
    // printDivisorsOptimal(m);

    // Brute Force: Find prime divisors
    // findPrimeDivisorsBruteForce(m);

    // Better: Find prime divisors
    // findPrimeDivisorsBetter(m);

    // Optimal: Find prime divisors
    findPrimeDivisorsOptimal(m);

    return 0;
}
