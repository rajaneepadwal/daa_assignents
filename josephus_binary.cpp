#include<iostream>
using namespace std;
int main()
{
    int n,pow=1;
    cout<<"Enter the value of n: ";
    cin>>n;//k=2
    while(pow*2<=n)
    {
        pow=pow*2;//MULTIPLY IFF POW WILL STILL BE LESS THAN OR SAME AS n
    }
    int L=n-pow;
    cout<<"The last left person is:"<<2*L+1;;
}