#include<iostream>
using namespace std;

int SingleEle(int arr[],int n)
{
    if(n==1)return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2])return arr[n-1];
    int l=1;
    int h = n-2;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        {
            return arr[mid];
        } 
        if(mid%2==0)
        {
            if(arr[mid]==arr[mid+1])l=mid+1;
            else if(arr[mid]==arr[mid-1])h=mid-1;
        }
        else
        {
            if(arr[mid]==arr[mid-1])l=mid+1;
            else if(arr[mid]==arr[mid+1])h=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,1,2,2,3,3,4,4,5,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<SingleEle(arr,n);
}