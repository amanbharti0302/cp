#include<bits/stdc++.h>
using namespace std;

class BIT{
    public:
    int size;
    vector<int>bit;
    const int INF = (int)1e9;

    BIT(int n){
        this->size = n;
        bit.resize(n+1,0);
    }

    void update(int idx, int val){
        for(;idx<=this->size;idx+=(idx&(-idx)))bit[idx]+=val;
    }

    void range(int l,int r ,int val){
        this->update(l,val);
        this->update(r+1,-val);
    }

    int query(int idx){
        int ans = 0;
        for(; idx>0 ; idx-=idx&(-idx))ans+=bit[idx];
        return ans;
    }
};


int main(){
    BIT *a = new BIT(10);
    a->range(3,7,4);
    a->range(5,7,-3);
    cout<<a->query(1)<<endl;
    cout<<a->query(3)<<endl;
    cout<<a->query(6)<<endl;
    cout<<a->query(7)<<endl;
    cout<<a->query(9)<<endl;
    return 0;
}
