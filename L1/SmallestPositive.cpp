#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of elements in array :- ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements :- ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }

    int l=0;
    int h=n-1;
    int ans;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid]==mid)l=mid+1;
        else
        {
            h=mid-1;
            ans = mid;
        }
    }
    cout<<ans;
}