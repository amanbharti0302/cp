#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  string s;
  cin>>n>>k>>s;

  int ind[26];
  memset(ind,-1,sizeof(ind));
  int dp[n+1] = {0};
  int ans = 0;

  for(int i = 0;i<n;i++){
    char x = s[i];
    int maxm = 1;
    for(char j = 'a';j<='z';j++){
      if(abs(j-x)>k)continue;
      if(ind[j-'a']==-1)continue;
      int index = ind[j-'a'];
      if(dp[index]+1>maxm){
        maxm = dp[index]+1;
      }
    }
    ind[s[i]-'a'] = i;
    dp[i] = maxm;
    ans = max(ans,dp[i]);
  }

  cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  int t;
  cin>>t;
  while(t--)solve();
}