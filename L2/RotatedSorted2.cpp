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

        if(arr[mid]==arr[l] && arr[mid]==arr[h])
        {
            l++,h--;
            continue;
        }
        if(arr[l]<=arr[mid])       // Left part sorted
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
    int arr[] = {3,1,2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int t;
    cout<<"Enter Target :- ";
    cin>>t;
    cout<<TargetIdx(arr,n,t);
}