#include<iostream>
#include<vector>
using namespace std;
int N_One(vector<int>v)
{
    int l = 0;
    int h = v.size()-1;
    int ans;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(v[mid]==1)
        {
            ans = mid;
            h=mid-1;
        }
        else
        l=mid+1;
    }
    return v.size()-ans;
}
int RMax_One(vector<vector<int> >v)
{
    int n = v.size();
    int m = v[0].size();
    int mx = 0;
    for(int i=0;i<n;i++)                    // O(n)*log(m)
        mx = max(mx,N_One(v[i]));
    return mx;
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
    cout<<RMax_One(v);
}