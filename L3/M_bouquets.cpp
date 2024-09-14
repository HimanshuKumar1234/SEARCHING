#include<iostream>
using namespace std;

bool check(int bloom[],int n, int m, int k, int mid)
{
    int count = 0;
    int z =0;
    for(int i=0;i<n;i++)
    {
        if(bloom[i]<=mid)count++;
        else
        {
            z+=(count/k);
            count=0;
        }
    }
    z+=count/k;
    if(z>=m)return true;
    else return false;
}
int Min_Days(int bloom[],int n, int m ,int k)
{
    long long z = static_cast<long long>(m) * static_cast<long long>(k);
    if(z> (long long)n)return -1;
    int l = INT_MAX;
    int h = INT_MIN;
    for(int i=0;i<n;i++)
    {
        l = min(bloom[i],l);
        h = max(bloom[i],h);
    }
    int ans ;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(check(bloom,n,m,k,mid)==true)
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
    int bloom[] = {7,7,7,7,13,11,12,7};
    int n = sizeof(bloom)/sizeof(bloom[0]);
    int m,k;
    cout<<"Enter No Of Boukests :- ";
    cin>>m;
    cout<<"Enter No Of Conjucative Bloom Day :- ";
    cin>>k;
    cout<<Min_Days(bloom,n,m,k);
}