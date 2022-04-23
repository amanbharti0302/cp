#include<bits/stdc++.h>
using namespace std;

class DSU{
    int size;
    vector<int>parent;
    vector<int>rank;
    
    void make_set(int v){
        this->parent[v] = v;
    }

    DSU(int n){
        this->size = n;
        this->parent.resize(n+5,0);
        this->parent.resize(n+5,0);

        for(int i = 0; i<=this->size; i++){
            make_set(i);
        }
    }

    int find_set(int v){
        if(v==parent[v])return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a,int b){
        a = find_set(a);
        b = find_set(b);
        if(a==b)return;
        
        if(rank[a]<rank[b]){
            swap(a,b);
        }

        parent[b] = a;
        rank[a]+=rank[b];
    }
};


int main(){
    return 0;
}
