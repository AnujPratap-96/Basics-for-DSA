#include<bits/stdc++.h>

using namespace std;

//? Brute Force Prime Check: O(n)
string primeBruteForce(int n) {
    if (n <= 1) return "False";
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return "False";
    }
    return "True";
}

//? Better Approach for Prime Check: O(sqrt(n))
string primeBetter(int n) {
    if (n <= 1) return "False";
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return "False";
    }
    return "True";
}

//? Optimal Prime Check using Sieve of Eratosthenes: O(n log log n)
vector<int> sieveOfEratosthenes(int n) {
    vector<int> primes(n + 1, 1);  // Initially mark all numbers as prime
    primes[0] = primes[1] = 0;     // 0 and 1 are not prime
    
    for (int i = 2; i * i <= n; i++) {
        if (primes[i] == 1) {  // If i is prime
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;  // Mark multiples of i as non-prime
            }
        }
    }
    return primes;  // Return the sieve array (1 = prime, 0 = non-prime)
}

//? Brute Force SPF: O(n)
int SPFBruteForce(int n) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) return i;  // Return the smallest factor
    }
    return n;  // If no factor found, n is prime
}

//? Better Approach for SPF: O(sqrt(n))
int SPFBeter(int n) {
    if (n <= 1) return n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return i;  // Return the smallest factor
    }
    return n;  // If no factor found, n is prime
}

//? Optimal SPF using Sieve of Eratosthenes: O(n log log n)
vector<int> smallestPrimeFactor(int n) {
    vector<int> spf(n + 1);  // spf[i] will store the smallest prime factor of i
    for (int i = 0; i <= n; i++) spf[i] = i;  // Initially, spf[i] = i
    
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {  // i is prime
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;  // Mark the smallest prime factor
            }
        }
    }
    return spf;
}

int main() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    // Use brute force, better, or optimal methods as needed
    
    // Brute force prime check
    cout << "Brute Force Prime Check: " << primeBruteForce(n) << endl;
    
    // Better prime check
    cout << "Better Prime Check: " << primeBetter(n) << endl;

    // Optimal prime check (sieve for primes up to n)
    vector<int> primes = sieveOfEratosthenes(n);
    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) cout << i << " ";
    }
    cout << endl;

    // Brute force SPF
    cout << "Brute Force SPF of " << n << ": " << SPFBruteForce(n) << endl;

    // Better SPF
    cout << "Better SPF of " << n << ": " << SPFBeter(n) << endl;

    // Optimal SPF (sieve for SPF up to n)
    vector<int> spf = smallestPrimeFactor(n);
    cout << "Smallest Prime Factors up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        cout << spf[i] << " ";
    }
    cout << endl;

    return 0;
}
