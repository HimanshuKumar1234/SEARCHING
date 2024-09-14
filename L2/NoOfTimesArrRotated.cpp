#include<iostream>
using namespace std;

int TimesRotated(int arr[],int n)
{

    int mini = INT_MAX;
    int id =-1;
    int l=0;
    int h = n-1;
    if(arr[l]<=arr[h])
    {
        return l;
    }
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[l]<=arr[mid])
        {
            if(arr[l]<mini)
            {
                mini=arr[l];
                id=l;
            }
            l=mid+1;
        }
        else
        {
            if(arr[mid]<mini)
            {
                mini=arr[mid];
                id = mid;
            }   
            h=mid-1;
        }
    }
    return id;
}

int main()
{
    int arr[] = {4,5,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<TimesRotated(arr,n);
}