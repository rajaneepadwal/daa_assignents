#include<iostream>
using namespace std;
int main()
{
    int n,k,index=0;
    cout<<"Enter n & k: ";
    {
        cin>>n>>k;
    }
    int arr[n];
    int flag=n,count=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
        cout<<arr[i]<<endl;
    }
    cout<<"The eliminated numbers are: ";
    while(flag>1)
    {
        if(arr[index]!=0)
            count++;
    if(count==k)
    {
        cout<<arr[index]<<endl;
        arr[index]=0;
        count=0;
        flag--;
    }
    index=(index+1)%n;
    }
    cout<<"\nThe last remaining element is: ";
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            cout<<arr[i]<<endl;
        }
    }
}