#include<bits/stdc++.h>
#define int long long
#define IO   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);std::ifstream infile("soln.in");if(infile.good()){assert(freopen("soln.in","r",stdin));assert(freopen("soln.out","w",stdout));}
using namespace std;

void cal();

int calc(vector<int>v,vector<int>&arr,int n,int ans){
  if(v.size()==0)return ans;
  int temp = abs(v[1]-v[0]) + abs(arr[0]-v[1])+ans;
  for(int i = 1;i<n;i++){
    int tt = ans-abs(arr[i]-arr[i-1]);
    temp = min(temp,abs(v[0]-arr[i-1]) + tt+ abs(v[1]-arr[i]));
  }
  temp = min(temp,abs(v[1]-v[0]) + abs(arr[n-1]-v[1])+ans);
  return temp;
}

int32_t main(){
  IO

  int tt;
  cin>>tt;

  while(tt--)cal();
  return 0;
}

void cal(){
  int minm = INT64_MAX;
  int maxm = INT32_MIN;
  int n,x;
  cin>>n>>x;
  vector<int>arr(n);
  for(auto &y:arr){
    cin>>y;
    minm = min(minm,y);
    maxm = max(maxm,y);
  }


  vector<int>p1,p2;
  if(minm>1){
    p1.push_back(1);
    p1.push_back(min(minm-1,x));
  }
  
  if(maxm<x){
    p2.push_back(maxm+1);
    p2.push_back(x);
  }

  int ans = 0,res = 0;
  for(int i = 1;i<n;i++)ans+=abs(arr[i]-arr[i-1]);
  res = ans;
  if(p1.size()>0)res=calc(p1,arr,n,ans);
  if(p2.size()>0)res=(calc(p2,arr,n,res));

  cout<<res<<endl;
}
