#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define all(n) n.begin(),n.end() 
#define vec vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
//Recursion way to find the fibonacci
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
//FInding the Fibonaccii number using the Dynamic Programming.
int fibDP(int n,vector<int>&dp){
   if(n==0||n==1) return n;
   if(dp[n]!=-1) return dp[n];
   return dp[n]=fibDP(n-1,dp)+fibDP(n-2,dp);
}
int fibDPBU(int n){
    vector<int>arr(n+1,-1);
    arr[0]=0;
    arr[1]=1;
    for(int a=2;a<=n;a++){
        arr[a]=arr[a-1]+arr[a-2];
    }
    return arr[n];
}
//Most optimised space complexity to find the fibonacci number
int fibua(int a){
    if(a==0||a==1){
        return a;
    }
    int b=0;
    int c=1;
    int d=0;
    for(int e=2;e<=a;e++){
            d=b+c;
            b=c;
            c=d;
    }
    return d;
}


int main(){
int n;
cin>>n;
vector<int>arr(n+1,-1);
cout<<fibDP(n,arr)<<" "<<fibDPBU(n)<<" "<<fibua(n)<<endl;


return 0;
}