#include<bits/stdc++.h>
          
using namespace std;

void print(int n)
{
    
    
    for(int i = 1; i*i<=n;i++)
    {
        if((n % i) == 0)
        {
            cout<<i<<endl;
        if((n%i) != i)
        {
            cout<<n/i<<endl;
        }
        }
    }

}

bool prime(int n){
    int count = 0;
    for(int i = 1; i*i<=n;i++)
    {
        if((n % i) == 0)
        {
            // cout<<i<<endl;
            count++;
        if((n%i) != i)
        {
            count++;
            // cout<<n/i<<endl;
        }
        }
    }
    if(count == 2) return true;
    return false;
}

int allDivisors(int x)
{
    list<int> ans;
    //* brute force
    // for(int i = 2; i<= x; i++)
    // {
    //     if(x % i ==0)
    //     {
    //         if(prime(i)){
    //             ans.push_back(i);
    //         }
    //     }
    // }
   
    //? better one
    // for(int i = 2; i*i<= x; i++)
    // {
    //     if(x % i ==0)
    //     {
    //         if(prime(i)){
    //             ans.push_back(i);
    //         }
    //         if((x / i) != i)
    //         {
    //             if(prime(x/i)) ans.push_back(x/i);
    //         }
    //     }
    // }

    //! optimal one
     for(int i = 2; i*i<= x; i++)
    {
        if(x % i ==0)
        {
            if(prime(i)){
                ans.push_back(i);
                while(x % i == 0)
                {
                       x/=i;
                }
            }
        }
    }

    if(x != 1) ans.push_back(x);
    
    for(auto a : ans)
    {
        cout<<a<<endl;
    }
}
        
int main(){
    int m;
    cout<<"Enter a number ";
    cin>>m;
    // print(m);
    // cout<<"The given number "<<m<<" is prime : "<<prime(m);
    allDivisors(m);
    return 0;
}