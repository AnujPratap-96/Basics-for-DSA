#include<bits/stdc++.h>

using namespace std;

//? WAP to count the number of digits in a number.
int countDigit(int n){
    //* brute force -->
//     int count = 0;
//     if(n==0) return 1;
//     while(n>0){
//         count++;
//         n=n/10;
//     }
//   return count;
    //? optimal way
    if(n==0) return 1;
    int count = (int) (log10(n) + 1);
    return count;
}

//* WAP to count the digits in a number that evenly divides the number.

int countNum(int n){
    int m = n;
    int count = 0;
    while(n>0){
        int r = n%10;
        if(r!=0 && (m%r) == 0){
            count++;
        }
        n/=10;
    }
    return count;
}

int main(){
    int n;
    cout<<"enter a number ";
    cin>>n;
    // cout<<"The number of digits in "<<n<<" is "<<countDigit(n);
    cout<<"The number of digits that divides  "<<n<<" is "<<countNum(n);
    return 0;
}