#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no :- ";
    cin>>n;
    int l = 0;
    int h = n;
    int ans;
    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(mid*mid == n)
        {
            ans=mid;
            break;
        }
        else if(mid*mid>n)
        {
            h = mid-1;
        }
        else{
            ans = mid;
            l=mid+1;
        }
    }
    cout<<ans;
}