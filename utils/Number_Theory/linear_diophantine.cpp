int gcd(int a,int b,int &x,int &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }

    int x0,y0;
    int d =  gcd(b,a%b,x0,y0);
    x = y0;
    y = x0-y0*(a/b);
    return d;
}


//find x, y soln of equation ax+by = gcd