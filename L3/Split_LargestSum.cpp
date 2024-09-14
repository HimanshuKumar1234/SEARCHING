#include<iostream>
using namespace std;

int func(int arr[],int n,int mid)
{
    int count = 1;
    int sum=0;
    for(int i=0;i<n;i++)            //25 46 28 49 24
    {
        sum+=arr[i];
        if(sum>mid)
        {
            sum=arr[i];
            count++;
        }
    }
    return count;
}
int Min_Sub(int arr[],int n,int s)
{
    if(n<s)return -1;
    int l = 0;
    int h = 0;
    for(int i=0;i<n;i++)
    {
        l=max(l,arr[i]);
        h+=arr[i];
    }
    while(l<=h)
    {
        int mid = (l+h)/2;
        int countStu = func(arr,n,mid);
        if(countStu>s)
            l=mid+1;
        else
            h=mid-1;
    }
    return l;
}
int main()
{
    int arr[]={10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s;
    cout<<"Enter No Subarrays :- ";
    cin>>s;
    cout<<Min_Sub(arr,n,s);
}
