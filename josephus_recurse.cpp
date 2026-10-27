#include<iostream>
using namespace std;
int josephus(int n,int k)
{
    if(n==1)
        return 1;
    return (josephus(n-1,k)+k)%n;
}
int main()
{
    int n,k;
    cout<<"Enter the value of n and k: ";
    cin>>n>>k;
    int lastPerson = josephus(n,k);
    cout<<"The last left person is:"<<lastPerson;
}