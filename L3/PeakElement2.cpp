#include<iostream>
#include<vector>
using namespace std;

bool Peak(vector<vector<int> >v)
{
    // Brute O(n*m*4)
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
    cout<<Peak(v);
}