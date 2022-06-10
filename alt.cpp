#include<bits/stdc++.h>
#if __has_include("commands/local/main.h")
  #include "commands/local/main.h"
#endif
using namespace std;

template<typename ...Args>void print(Args&&... values);
#define int long long
#define mod 1000000007
const int M = 2e5+5;

int n;

void solve(){
  cin>>n;
  vector<int>s(n),f(n),ans(n);
  for(auto &x: s)cin>>x;
  for(auto &x: f)cin>>x;
  int last = 0;
  for(int i = 0;i<n;i++){
    ans[i] = f[i]-max(s[i],last);
    last = max(last,s[i])+ans[i];
  }
  for(auto x: ans)cout<<x<<" ";
  cout<<endl;
}

int32_t main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  
  int test=1;
  cin>>test;
  
  while(test--)solve();
}

int power(int a,int b) {int res=1LL;while(b>0){if(b&1)res=(res*a);a=(a*a);b>>=1;}return res;}
int powerwithmod(int a,int b) {int res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res%mod;}
template<typename ...Args>void print(Args&&... values){(..., (cout<< values<<" ", true));cout<<endl;}