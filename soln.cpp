#include<bits/stdc++.h>
#if __has_include("commands/local/main.h")
  #include "commands/local/main.h"
#endif
using namespace std;

template<typename ...Args>void print(Args&&... values);
#define int long long
#define mod 1000000007
int powerwithmod(int a,int b);
const int M = 2e5+5;

int n;

void solve(){
  cin>>n;
  if(n==7){
    cout<<2<<" "<<4<<" "<<1<<endl;
    return;
  }
  int a = n/3, b = n/3, c = n/3+(n%3);
  vector<int>v = {a,b,c};
  sort(v.begin(),v.end(),greater<int>());
  swap(v[0],v[1]);

  if(v[1]==v[0])v[1]++,v[2]--;
  if(v[0]==v[2])v[0]++,v[2]--;
  if(v[1]==v[0])v[1]++,v[2]--;


  for(auto x: v)cout<<x<<" ";
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