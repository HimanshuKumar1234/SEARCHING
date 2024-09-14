#include<iostream>
using namespace std;

int Power(int n,int a, int b)
{
    if(pow(a,b)>n)
    return n+1;
    else return pow(a,b);
}
int NthRoot(int n, int Nth)             
{
    int l = 1;
    int h = n;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(Power(n,mid,Nth)==n)                       // log(n)*log(Nth)
        {
            return mid;
        }
        else if(Power(n,mid,Nth)>n)
        {
            h=mid-1;
        }
        else
        l=mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enetr No :- ";
    cin>>n;
    int Nth;
    cout<<"Enter Nth no :- ";
    cin>>Nth;
    cout<<NthRoot(n,Nth);
}