#include<iostream>
using namespace std;

int MinEle(int arr[],int n)
{

    int mini = INT_MAX;
    int l=0;
    int h = n-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[l]<=arr[mid] && arr[mid]<=arr[h])
        {
            return  min(arr[l],mini);
        }
        else if(arr[l]<=arr[mid])
        {
            if(arr[l]<mini)mini=arr[l];
            l=mid+1;
        }
        else
        {
            if(arr[mid]<mini)mini=arr[mid];
            h=mid-1;
        }
    }
    return mini;
}

int main()
{
    int arr[] = {4,5,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<MinEle(arr,n);
}