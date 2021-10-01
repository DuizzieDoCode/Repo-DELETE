#include<bits/stdc++.h>
using namespace std;
void bordersort(int a[][],int n)
{
    int k=floor((n-1)/2);
    for(int i=0;i<=k;i++)
    {
        vector<int> v;
        for(int j=k;j<n-k;j++)
        {
            v.push_back(a[k][j]);
        }
        for(int j=k+1;j<n;j++)
        {
            v.push_back(a[j][n-1-k]);
        }
        for(int j=n-2-k;j>=k;j--)
        {
            v.push_back(a[n-1-k][j]);
        }
        for(int j=n-2-k;j>k;j--)
        {
            v.push_back(a[j][k]);
        }
        sort(v.begin(),v.end());
        int c=0;
        for(int j=k;j<n-k;j++)
        {
            a[k][j]=v[c];
            c++;
        }
        for(int j=k+1;j<n;j++)
        {
            a[j][n-1-k]=v[c];
            c++;
        }
        for(int j=n-2-k;j>=k;j--)
        {
            a[n-1-k][j]=v[c];
            c++;
        }
        for(int j=n-2-k;j>k;j--)
        {
            a[j][k]=v[c];
            c++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}