#include<iostream>
#include<vector>
using namespace std;

bool Search(vector<vector<int> >v,int tar)
{
    int n = v.size();
    int m = v[0].size();
    int l=0;
    int h = n*m-1;                      // Flatten 2d into 1d array
    while(l<=h)                        // O(log(n*m))
    {
        int mid = (l+h)/2;
        int r = mid%m;
        int c = mid/m;
        if(v[r][c]==tar)return true;
        else if(v[r][c]>tar)
            h=mid-1;  
        else l=mid+1;                           
    }
    return false;
}
int main()
{
    int m,n;
    cout<<"Enter rows and cols :- ";
    cin>>n>>m;
    vector<vector<int> >v;
    cout<<"Enter elements of vector :- ";
    for(int i=0;i<n;i++)
    {
        vector<int>t;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            t.push_back(x);
        }
        v.push_back(t);
    }

    int tar;
    cout<<"Enter target :- ";
    cin>>tar;
    cout<<Search(v,tar);
}