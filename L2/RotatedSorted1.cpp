#include<iostream>
using namespace std;

int TargetIdx(int arr[],int n,int t)
{
    int l=0;
    int h = n-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid]==t)return mid;
        else if(arr[l]<=arr[mid])       // Left part sorted
        {
            if(t<=arr[mid] && t>=arr[l])    // target in sorted part
                h=mid-1;
            else 
                l=mid+1;

        }
        else                                // Right part sorted
        {
            if(t<=arr[h] && t>=arr[mid])    // target in sorted part
                l=mid+1;
            else 
                h=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {7,8,9,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int t;
    cout<<"Enter Target :- ";
    cin>>t;
    cout<<TargetIdx(arr,n,t);
}