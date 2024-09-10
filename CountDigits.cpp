#include<bits/stdc++.h>

using namespace std;

//? Brute Force: Count the number of digits in a number.
int countDigitBruteForce(int n) {
    int count = 0;
    
    // If number is 0, it has 1 digit
    if (n == 0) return 1;

    // Loop through each digit of the number
    while (n > 0) {
        count++;       // Increment the digit count
        n = n / 10;    // Remove the last digit
    }
    return count;
}

//? Optimal Way: Count the number of digits in a number using logarithms.
int countDigitOptimal(int n) {
    if (n == 0) return 1;    // If number is 0, it has 1 digit

    // Use logarithmic function to calculate the number of digits
    int count = (int)(log10(n) + 1);
    return count;
}

//* Brute Force: Function to count the digits in a number that evenly divides the number.
int countDividingDigitsBruteForce(int n) {
    int m = n;   // Store the original number
    int count = 0;

    // Loop through each digit of the number
    while (n > 0) {
        int r = n % 10;   // Get the last digit

        // Check if the digit is not zero and divides the number evenly
        if (r != 0 && (m % r) == 0) {
            count++;   // Increment the count if it divides evenly
        }
        
        n /= 10;   // Remove the last digit
    }

    return count;
}

//? Optimal Way: Count digits that evenly divide the number using string manipulation.
int countDividingDigitsOptimal(int n) {
    int count = 0;
    string numStr = to_string(n);   // Convert the number to a string
    
    // Loop through each character in the string
    for (char digit : numStr) {
        int d = digit - '0';   // Convert the character back to an integer
        
        // Check if the digit is non-zero and divides the number evenly
        if (d != 0 && (n % d) == 0) {
            count++;   // Increment the count if it divides evenly
        }
    }
    
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Uncomment to use the brute force method for counting digits
    // cout << "The number of digits in " << n << " is " << countDigitBruteForce(n) << endl;

    // Uncomment to use the optimal method for counting digits
    // cout << "The number of digits in " << n << " is " << countDigitOptimal(n) << endl;

    // Brute Force: Count the digits that evenly divide the number
    cout << "The number of digits that divide " << n << " (Brute Force) is " << countDividingDigitsBruteForce(n) << endl;
    
    // Optimal Way: Count the digits that evenly divide the number
    cout << "The number of digits that divide " << n << " (Optimal) is " << countDividingDigitsOptimal(n) << endl;
    
    return 0;
}
