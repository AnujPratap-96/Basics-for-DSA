//? WAP to reverse a number.

#include<bits/stdc++.h>
          
using namespace std;

int reverse(int n){
    int revnum = 0;
    while(n>0){
        int r = n % 10;
        revnum = revnum*10 + r;
        n /=10;
    }
    return revnum;
}

//* ArmStrong Number

string Armstrong(int n){
    int m = n;
    int armnum = 0;
    while(n>0){
        int r = n % 10;
        armnum = armnum + r*r*r;
        n /=10;
    }
    if(armnum == m)
    {
        return "true";
    }
    else{
        return "false";
    }
}

//? Palindrome Number

string Palindrome(int n){
   int num = reverse(n);
   if(num == n)
   {
    return "True";
   }
   else{
    return "False";
   }

}
        
int main(){
    int m;
    cout<<"Enter a Number : ";
    cin>>m;
    // cout<<"The Reverse of the number "<<m<<" is "<<reverse(m);     
    // cout<<"The Given number "<<m<<" is Armstrong "<<Armstrong(m);     
    cout<<"The Given number "<<m<<" is Palindrome "<<Palindrome(m);     

    return 0;
}