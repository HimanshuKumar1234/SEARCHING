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

    int k;
    cout<<"Enter target element :- ";
    cin>>k;

    int l = 0;
    int h = n-1;
    bool flag = false;
    int ans = -1;
    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(arr[mid]==k)
        {
            flag = true;
            ans = mid;
            h=mid-1;
        }
        else if(arr[mid]<k)l=mid+1;
        else h=mid-1;
    }
    if(flag == false)cout<<-1;
    else cout<<ans;
}