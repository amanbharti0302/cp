void sieve(){
    memset(prime,true,sizeof(prime));

    for(int i = 2;i*i<N-1;i++){
        if(!prime[i])continue;
        for(int j= i*i;j<N-1;j+=i)prime[j] = false;
    }

}


void sieveinlinear(){
    for(int i = 2;i<N;i++){
        if(lp[i]==0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N ;j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    return;
}

