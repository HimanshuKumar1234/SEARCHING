#include<iostream>
using namespace std;

bool CanWePlace(int arr[],int n,int dist,int cow)
{
    cow--;
    int lp=0;
    for(int i=1;i<n;i++)
    {
        if((arr[i]-lp)>=dist)
        {
            cow--;
            lp=arr[i];
            if(cow==0)return true;
        }
    }
    return false;
}

// int Aggresive_Cows(int arr[],int n, int cow)    // Brute and TC => O(MAX-MIN)*O(n)
// {
//     sort(arr,arr+n);
//     for(int i=1;i<(arr[n-1]-arr[0]);i++)
//     {
//         if(CanWePlace(arr,n,i,cow)==true)continue;
//         else return i-1;
//     }
//     return 0;
// }

int Aggresive_Cows(int arr[],int n, int cow)    // Optimised and TC => O(log(MAX-MIN))*O(n)
{
    sort(arr,arr+n);
    int l = 1;
    int h = arr[n-1]-arr[0];
    int ans;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(CanWePlace(arr,n,mid,cow)==true)
        {
            ans = mid;
            l=mid+1;
        }
        else h= mid-1;
    }
    return ans; 
}

int main()
{
    int arr[]={0,3,4,7,10,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cow;
    cout<<"Enter Cow :- ";
    cin>>cow;
    // You have to place cow in between array Minimum distance between any two cows aremax of distance between them
    cout<<Aggresive_Cows(arr,n,cow);
}