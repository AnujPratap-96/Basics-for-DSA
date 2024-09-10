#include<bits/stdc++.h>
          
using namespace std;

//brute force

// int GCD(int x , int y){
//     int gcd = 1;
//     for(int i = 1; i<= min(x,y); i++){
//         if((x%i == 0) && ( y%i == 0)) gcd = i;
//     }
//     return gcd;
// }

//? better one

int GCD(int x , int y){
    int gcd = 1;
    for(int i= min(x,y); i>=1; i--){
        if((x%i == 0) && ( y%i == 0)) gcd = i; break;
    }
    return gcd;
}

//! Euelidean Algorithm

int gcd(int a , int b){
    while(a>0 && b>0){
        if(a>b) a = a%b;
        else    b %=a;
    }
    if(a == 0) return b;
    return a;
}

        
int main(){
    int m , n;
    cout<<"Enter two numbers";
    cin>>m>>n;
    // cout<<"The GCD of "<<m<<" and "<<n<<" is "<<GCD(m,n);     
    cout<<"The GCD of "<<m<<" and "<<n<<" is "<<gcd(m,n);     
    return 0;
}