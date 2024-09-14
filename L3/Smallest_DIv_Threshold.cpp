#include<iostream>
using namespace std;

bool check(int nums[],int n, int th, int sn)
{
    int count =0;
    for(int i=0;i<n;i++)
    {
        count+=(ceil((nums[i]*1.0)/sn));
    }
    if(count<=th)return true;
    else return false;
}

int SmallestDiv(int nums[],int n, int th)
{
    int l = 1;
    int h = INT_MIN;
    for(int i=0;i<n;i++)h=max(h,nums[i]);
    int ans =-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(check(nums,n,th,mid)==true){
            ans=mid;
            h= mid-1;
        }
        else
        l=mid+1;
    }
    return ans;
}

int main()
{
    int nums[] = {44,22,33,11,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    int th ;
    cout<<"Enter ThreshHold :- ";
    cin>>th;
    cout<<SmallestDiv(nums,n,th);
}