#include<bits/stdc++.h>
          
using namespace std;

string prime(int n)
{
    int arr[n+1];
    arr[0]=0;
    arr[1]=0;
    for(int i =2; i<=n;i++){
        arr[i]=1;
    }
    for(int i=2; i*i<=n;i++)
    {
        if(arr[i]==1){
            for(int j =i*i; j<-n;j+=i){
                arr[j]=0;
            }
        }
    }
    if(arr[n]==1)
    {
        return "True";
    }
    else return "False";

    //! To print all the prime within the range just change type to void and :
    // for(int i =2; i<=n;i++)
    // {
    //     if(arr[i]==1)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    // }
}

int SPF(int n)
{
    int spf[n+1];
    for(int i =0; i<=n;i++)
    {
        spf[i]=i;
    }
    for(int i = 2; i*i<=n ;i++)
    {
        if(spf[i]==i)
        {
            for(int j = i*i; j<=n; j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
}
        
int main(){
    int n;
    cout<<"Enter a Number"<<endl;
    cin>>n;
    
    cout<<"The Number "<<n<<" is prime : "<<prime(n)<<endl;

    return 0;
}