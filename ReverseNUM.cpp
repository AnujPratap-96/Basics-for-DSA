#include<bits/stdc++.h>

using namespace std;

//? Brute Force to reverse a number
int reverseBruteForce(int n) {
    int revnum = 0;
    while (n > 0) {
        int r = n % 10;
        revnum = revnum * 10 + r;
        n /= 10;
    }
    return revnum;
}

//? Better Approach to reverse a number
int reverseBetter(int n) {
    int revnum = 0;
    while (n > 0) {
        int r = n % 10;
        revnum = revnum * 10 + r;
        n /= 10;
    }
    return revnum;
}

//* Brute Force to check if a number is Armstrong
string ArmstrongBruteForce(int n) {
    int m = n;
    int armnum = 0;
    while (n > 0) {
        int r = n % 10;
        armnum += r * r * r;
        n /= 10;
    }
    return (armnum == m) ? "true" : "false";
}

//* Better Approach to check if a number is Armstrong
string ArmstrongBetter(int n) {
    int m = n;
    int armnum = 0;
    while (n > 0) {
        int r = n % 10;
        armnum += r * r * r;
        n /= 10;
    }
    return (armnum == m) ? "true" : "false";
}

//? Brute Force to check if a number is a palindrome
string PalindromeBruteForce(int n) {
    int num = reverseBruteForce(n);
    return (num == n) ? "True" : "False";
}

//? Better Approach to check if a number is a palindrome
string PalindromeBetter(int n) {
    int num = reverseBetter(n);
    return (num == n) ? "True" : "False";
}

int main() {
    int m;
    cout << "Enter a Number: ";
    cin >> m;

    // Uncomment to use different functionalities

    // Reverse of the number
    cout << "The Reverse of the number " << m << " is " << reverseBetter(m) << endl;

    // Check if the number is Armstrong
    cout << "The Given number " << m << " is Armstrong: " << ArmstrongBetter(m) << endl;

    // Check if the number is Palindrome
    cout << "The Given number " << m << " is Palindrome: " << PalindromeBetter(m) << endl;

    return 0;
}
