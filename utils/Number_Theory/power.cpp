int power(int a,int b){
    int res = 1;
    while(b){
        if(b&1)res = res *a;
        a = a*a;
        b>>=1;
    }
    return res;
}



//similar for power with mod