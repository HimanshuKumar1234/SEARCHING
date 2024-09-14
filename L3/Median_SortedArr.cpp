#include<iostream>
using namespace std;
void merge(int res[], int arr1[],int arr2[],int n1, int n2)
{
    int i,j,k;
    i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j]) res[k++]=arr1[i++];
        else res[k++]=arr2[j++];
    }
    if(i==n1) while(j<n2) res[k++]=arr2[j++];
    else while(i<n1) res[k++]=arr1[j++];
}
int MedianArr(int arr1[],int arr2[],int n1,int n2)  // Brute force and we are using extra space
{
    int x = n1+n2;
    int res[x];
    merge(res,arr1,arr2,n1,n1);
    if(x%2!=0)return res[x/2];
    else return(res[x/2]+res[x/2 - 1])/2;
}
int main()
{
    int arr1[]={1,3,4,7,10,12};
    int arr2[]={2,3,6,15};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<MedianArr(arr1,arr2,n1,n2);
}