#include<bits/stdc++.h>
using namespace std;

int seg[300005];
int a[100005];

void build(int v, int l,int r){
  if(l==r){
    seg[v] = (a[l]==0);
    return;
  }
  int mid = (l+r)/2;
  build(2*v,l,mid);
  build(2*v+1,mid+1,r);
  seg[v] = seg[2*v]+seg[2*v+1];
}

void update(int idx,int val,int v,int l,int r){
  if(l>r)return;
  if(l==r){
    seg[v] = (val==0);
    return;
  }
  int mid = (l+r)/2;
  if(idx<=mid)update(idx,val,2*v,l,mid);
  else update(idx,val,2*v+1,mid+1,r);
  seg[v] = seg[2*v]+seg[2*v+1];
}

int query(int v,int L,int R,int l, int r){
  if(l>R || r<L)return 0;
  if(L<=l && r<=R)return seg[v];
  int mid = (l+r)/2;
  return query(2*v,L,min(R,r),l,mid)+query(2*v+1,max(L,l),R,mid+1,r);
}

int find_kth(int v,int l,int r,int k){
  if(seg[v]<k)return -1;
  if(l==r)return l;
  int mid = (l+r)/2;
  if(seg[2*v]>=k)find_kth(2*v,l,mid,k);
  else find_kth(2*v+1,mid+1,r,k-seg[2*v]);
}

void solve(){
  int n;
  cin>>n;

  for(int i = 1;i<=n;i++)cin>>a[i];
  build(1,1,n);

  while (1){
    int type;
    cin>>type;

    if(type == -1)break;
    if(type == 1){
      cout<<"IND "<<" "<<"val"<<endl;
      int ind , val;
      cin>>ind>>val;
      update(ind,val,1,1,n);
    }
    else if(type == 2){
      cout<<"Enter K : "<<endl;
      int k;
      cin>>k;
      cout<<find_kth(1,1,n,k)<<endl;
    }
    else {
      cout<<"l: r"<<endl;
      int ll,rr;
      cin>>ll>>rr;
      cout<<query(1,ll,rr,1,n)<<endl;
    }
  }
  
}

int32_t main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  
  int test=1;
  // cin>>test;
  
  while(test--)solve();
}