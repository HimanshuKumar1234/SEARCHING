#include<iostream>
using namespace std;
long long calculateT(int speed,int piles[], int n)
{
    long long count =0;
    for(int i=0;i<n;i++)
    {
        count+=ceil((piles[i]*1.0)/speed);
    }
    return count;
}

// Brute Force
// int KokoEat(int piles[], int hours, int n)
// {
//     int mx = INT_MIN;
//     int ans = INT_MAX;
//     for(int i=0;i<n;i++) mx = max(piles[i],mx);
//     for(int i=1;i<=mx;i++)
//     {
//         int reqT = calculateT(i,piles,n);
//         if(reqT<=hours) ans = min(ans,reqT);
//     }
//     return ans;
// }


int KokoEat(int piles[], int hours, int n)
{
    int h = INT_MIN;
    for(int i=0;i<n;i++) h = max(piles[i],h); 
    int l = 1;
    int speed =0;
    while(l<=h)                                            // TC => O(N)*log(max(piles))
    {
        int mid = (l+h)/2;
        if(calculateT(mid,piles,n)<=hours)
        {
            speed = mid;
            h=mid-1;
        }
        else 
        l=mid+1;
    }
    return speed;
}

int main()
{
    int piles[] = {3,6,7,11};
    int n = sizeof(piles)/sizeof(piles[0]);
    int h;
    cout<<"ENter time :- ";
    cin>>h;
    // Return the minimum integer k(speed) such that koko can eat all bananas 

    cout<<KokoEat(piles,h,n);
}