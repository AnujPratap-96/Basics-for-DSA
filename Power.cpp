#include<bits/stdc++.h>
          
using namespace std;

double power(double x , int n)
{   int pow = abs(n);
    double ans = 1;
    while(pow>0)
    {
         if(pow%2 == 1)
         {
            ans *=x;
            pow--; 
         }
         else{
            pow=pow/2;
            x *=x;
         }
    }
    if(n<0) return 1.0/ans;
    return ans;
}
        
int main(){
    cout<<power(5,5);
    return 0;
}