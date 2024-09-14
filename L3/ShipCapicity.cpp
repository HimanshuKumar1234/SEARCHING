// Least capicity to ship packages withen D days 

#include<iostream>
using namespace std;

bool check(int weights[], int n, int mid , int days)
{
    int count=1;
    int sum=0;
    for(int i =0;i<n;i++)
    {    
        if(sum+weights[i]<=mid)
        {
            sum+=weights[i];
        }
        else
        {
            count++;
            sum=weights[i];
        }
    }
    if(count<=days)return true;
    else return false;
}
int Min_Capicity(int weights[],int n, int days)
{
    int l = INT_MIN;
    int h = 0;
    for(int i=0;i<n;i++)
    {
        l=max(l,weights[i]);
        h+=weights[i];
    }
    int ans;
    while (l<=h)
    {
        int mid = (l+h)/2;                              
        if(check(weights,n,mid,days)==true)                 // O(log(sum))*n
        {
            ans = mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main()
{
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(weights)/sizeof(weights[0]); 
    int days ;
    cout<<"Enter Days :- ";
    cin>>days;
    cout<<Min_Capicity(weights,n,days);
}