#include<bits/stdc++.h>
using namespace std;

class BIT{
    public:
    int size;
    vector<int>bit;
    const int INF = (int)1e9;

    BIT(int n){
        this->size = n;
        bit.resize(n+1,INF);
    }

    void update(int idx, int val){
        for(;idx<=this->size;idx+=(idx&(-idx)))bit[idx] = min(bit[idx],val);
    }

    int getmin(int idx){  // from 0 to idx
        int ret = INF;
        for(;idx>0;idx-=idx & (-idx))ret = min(ret, bit[idx]);
        return ret;
    }

};


int main(){
    BIT *a = new BIT(10);
    a->update(5,7);

    cout<<a->getmin(4)<<endl;
    cout<<a->getmin(6)<<endl;
    cout<<a->getmin(10)<<endl;

    return 0;
}
