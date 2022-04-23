#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector","fast-math","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
#define MAXN   300005
#define br  cout<<endl;
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>void logger(string vars, Args&&... values);
int power(int a,int b);
int powerwithmod(int a,int b);
void add(int& x, int y);
const int M = 2e5+5;


void solve(){
  
}

int32_t main(){

  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  std::ifstream infile("soln.in");
  if(infile.good()){
  assert(freopen("soln.in","r",stdin));
  assert(freopen("soln.out","w",stdout));
  }

  int test=1;
  cin>>test;

  while(test--){solve();}
  cerr<<endl<<"Time: "<<(clock() * 1000. / CLOCKS_PER_SEC)<<" ms"<<endl;
  return 0;
}

void add(int& x, int y) {x += y;x %= mod;}
int power(int a,int b) {int res=1LL;while(b>0){if(b&1)res=(res*a);a=(a*a);b>>=1;}return res;}
int powerwithmod(int a,int b) {int res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res%mod;}
template<typename ...Args>void logger(string vars, Args&&... values) {cerr<<" { " << vars << " = ";string delim = "";(..., (cerr << delim << values, delim = ", "));cerr<<" }"<<endl;}