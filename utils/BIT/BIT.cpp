//In update
#include<bits/stdc++.h>
using namespace std;

class BIT{
    public:
    int size;
    vector<int>bit;

    BIT(int sz){
        this->size = sz;
        bit.resize(sz+1,0);
    }

    void update(int idx,int val){
        for(;idx<=this->size;idx+=idx & (-idx))bit[idx]+=val;
    }

    int getsum(int idx){
        int ans = 0;
        for(;idx>0;idx-=(idx&(-idx)))ans+=bit[idx];
        return ans;
    }

    int getsum(int l,int r){
        return getsum(r)-getsum(l-1);
    }

};

int main(){

    BIT *a = new BIT(10);
    a->update(5,5);
    cout<<a->getsum(5,10)<<endl;

    return 0;
}