#include<iostream>
using namespace std;

int PeakEle(int arr[],int n)
{
    if(n==1)return arr[0];
    if(arr[n-1]>arr[n-2])
    return arr[n-1];
    if(arr[0]>arr[1])
    return arr[0];
    int l=1;
    int h = n-2;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return arr[mid];
        else if(arr[mid]<arr[mid+1])l=mid+1;
        else h = mid-1;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<PeakEle(arr,n);
}