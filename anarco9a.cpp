//IMplemenatation to count the number of times we need to convert a non balancing paranthesis string to balanced parenthesis string.
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define t int 
#define in cin
#define ff vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int count_number_of_times(string s){
         stack<char>arr;
         int a=0;
         int closing=0;
         while(s[a]!='\0'){
             if(s[a]=='{'){
                 arr.push('{');
             }else{
                    if(arr.empty()==false){
                        arr.pop();
                    }else{
                        closing+=1;
                    }
             }
             a++;
         }
         int ans=0;
   if(arr.size()>0){
       if(arr.size()%2!=0){
            ans+=2;
            closing-=1;
       }
       ans+=arr.size()/2;
   }
   if(closing>0){
       ans+=closing/2;
   }
   return ans;


        


}
int main(){
int a=1;
string s;
while(a){
    cin>>s;
    if(s[0]=='-'){
        break;
    }else{
        cout<<a<<". "<<count_number_of_times(s)<<endl;
    }
    a++;
}


return 0;
}