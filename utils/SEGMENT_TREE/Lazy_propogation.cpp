//In update there may be bugs in this programme.

#include<bits/stdc++.h>
using namespace std;

class ST{
    public:
    int size;
    vector<int>seg;
    vector<int>lazy;

    ST(int sz){
        this->size = 4*sz+3;
        seg.resize(4*sz+3);
        lazy.resize(4*sz+3);
    }

    void build(int v,int l,int r){
        if(r>l)return;

        if(l==r){
            seg[v]+=1e9;
        }
        int mid = (l+r)/2;
        build(2*v, l,mid);
        build(2*v+1,mid+1,r);
        seg[v] = min(seg[2*v],seg[2*v+1]);
    }

    void propogate(int v,int L,int R){
        if(L!=R && 2*v < this->size){
            lazy[2*v]=lazy[v];
            lazy[2*v+1]=lazy[v];
        }
        seg[v] = lazy[v];
        lazy[v] = 0;
    }

    void update(int v,int L,int R, int l,int r,int val){
        if(r<L||l>L)return;
        
        propogate(v,L,R);

        if(l<=L&&R<=r){
            lazy[v] = val;
            propogate(v,L,R);
            return; 
        }

        int mid = (L+R)/2;
        update(v*2,L,mid,l,r,val);
        update(v*2+1,mid+1,R,l,r,val);
        seg[v] = min(seg[2*v],seg[2*v+1]);
    }

    int query(int v,int L,int R,int l,int r){
        if(r<L||l>L)return 1e9;
        
        propogate(v,L,R);

        if(l<=L&&R<=r){
            return seg[v]; 
        }

        int mid = (L+R)/2;
        query(v*2,L,mid,l,r);
        query(v*2+1,mid+1,R,l,r);
        return seg[v] = min(seg[2*v],seg[2*v+1]);
    }

};


int main(){
    return 0;
}


//Problem 1 (Max Query - Point Update with Coordinate Compression): http://codeforces.com/gym/100733/problem/F
//Solution 1: http://codeforces.com/gym/100733/submission/41643795

//Problem 2 (Min Query - Offline processing): https://codeforces.com/problemset/problem/522/D
//Solution 2: https://codeforces.com/contest/522/submission/45493164
