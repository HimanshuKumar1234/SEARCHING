//kth missing no 

#include<iostream>
using namespace std;

int Kth_Missing(int num[],int n, int Kth)
{
    int l =0;
    int h = n-1;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if((num[mid]-(mid+1))<Kth)              // no of missing till ith index => 1 1 1 3 6
        l=mid+1;
        else
        h=mid-1;
    }
    if(h<0)
    {
        return Kth ;
    }
    return (num[h]+ Kth-(num[h]-h-1));                 // arr[h]+more => k-missing
}
int main()
{
    int num[]={2,3,4,7,11};
    int n = sizeof(num)/sizeof(num[0]);
    int Kth;
    cout<<"Enter Kth Missing No :- ";
    cin>>Kth;
    cout<<Kth_Missing(num,n,Kth);
}