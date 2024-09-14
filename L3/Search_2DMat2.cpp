#include<iostream>
#include<vector>
using namespace std;

bool Search(vector<vector<int> >v,int tar)
{
    int n = v.size();
    int m = v[0].size();
    // Starting r=0 and col = m-1 
    int r = 0;
    int c = m-1;
    while(r<n && c>=0)                      // O(n+m)
    {
        if(v[r][c]==tar)
        return true;
        else if(v[r][c]<tar)
        r++;
        else c--;
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