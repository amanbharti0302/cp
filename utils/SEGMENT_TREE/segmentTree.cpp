class SEG{           //1 based segment indexing while 0 based array position
  private:  
  int _sz;
  int __N;
  vector<int>_s;

  public:

  SEG(int n){
    this->__N = n;
    this->_sz = n*4;
    _s.assign(_sz,0);
  }

  int _oper(int a,int b){return a+b;}   // change type of segment tree from here 

  void build(vector<int>&a,int l, int r,int idx){
    if(l>r)return;
    if(l==r){
      _s[idx] = a[l];
      return;
    }
    int mid = (l+r)/2;
    build(a,l,mid,2*idx);
    build(a,mid+1,r,2*idx+1);
    _s[idx] = _oper(_s[2*idx],_s[2*idx+1]);
  }

  void build(vector<int>&a){
    int l = 0;
    int r = __N-1;
    build(a,l,r,1);
  }


  void update(int l,int r,int &pos,int idx,int &val){
    if(l>r)return;
    if(l==r){
      _s[idx] = val;
      return;
    }

    int mid = (l+r)/2;
    if(pos<=mid)update(l,mid,pos,2*idx,val);
    else update(mid+1,r,pos,2*idx+1,val);
    _s[idx] = _oper(_s[2*idx], _s[2*idx+1]);
  }
  
  void update(int pos,int val){
    pos--;     //Keep in notice to check indexing
    int l = 0;
    int r = __N-1;
    update(l,r,pos,1,val);
  }

  int query(int l,int r,int LL,int RL, int idx){
    if(l>RL || r<LL)return 0;
    if(LL<=l && r<=RL)return _s[idx];
    int mid = (l+r)/2;
    return _oper( query(l,mid,LL,min(r,RL),2*idx), query(mid+1,r,max(l,LL),RL,2*idx+1) );
  }

  int query(int LL,int RL){
    int l = 0;
    int r = __N-1;

    LL--;RL--;     //Keep in notice to check indexing
    
    return query(l,r,LL,RL,1);
  }

};