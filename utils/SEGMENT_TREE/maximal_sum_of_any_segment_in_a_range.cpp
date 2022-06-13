#include<bits/stdc++.h>
using namespace std;


struct data{
  int sum,pref,suff,ans;
};

data seg[300005];

data combine(data l,data r){
  data res;
  res.sum = l.sum+r.sum;
  res.pref = max(l.pref, l.sum+r.pref);
  res.suff = max(r.suff,r.sum+l.suff);
  res.ans = max(max(l.ans,r.ans),l.suff+r.pref);
  return res;
}

data make_data(int val){
  data ans;
  ans.sum = val;
  ans.pref = ans.suff = ans.ans = max(0,val);
  return ans;
}

void build(int v,int l,int r,int a[]){
  if(l==r){
    seg[v] = make_data(a[l]);
    return;
  }
  int mid = (l+r)/2;
  build(2*v,l,mid,a);
  build(2*v+1,mid+1,r,a);
  seg[v] = combine(seg[2*v],seg[2*v+1]);
}

void update(int v,int l, int r,int pos,int val){
  if(l>r)return;
  if(l==r){
    seg[v] = make_data(val);
    return;
  }
  int mid = (l+r)/2;
  if(pos<=mid)update(2*v,l,mid,pos,val);
  else update(2*v+1,mid+1,r,pos,val);
  seg[v] = combine(seg[2*v],seg[2*v+1]);
}

data query(int v,int l,int r,int L,int R){
  if(L>R)return make_data(0);
  if(L<=l&& r<=R){
    return seg[v];
  }
  int mid = (l+r)/2;
  return combine( query(2*v,l,mid,L,min(R,mid)), query(2*v+1,mid+1,r,max(mid+1,L),R) );  
}

int32_t main(){
  int n;
  cin>>n;
  int a[n+1];
  for(int i = 1;i<=n;i++)cin>>a[i];
  build(1,1,n,a);

  while(1){
    int type;
    cin>>type;
    if(type == -1)break;
    if(type == 1){
      cout<<"ind val"<<endl;
      int ind,val;
      cin>>ind>>val;
      update(1,1,n,ind,val);
    }
    else{
      cout<<"L R"<<endl;
      int l,r;
      cin>>l>>r;
      cout<<query(1,1,n,l,r).ans<<endl;
    }
  }

}