struct tt{
    int siz;
    ll mat[6][6];
    tt(int r){
        siz=r;
        ifr(i,0,siz)
            ifr(j,0,siz)
                mat[i][j]=0;
    }
    int size() {
        return siz;
    }
};

// void print(tt &x){
//     ifr(i,0,x.size()){
//         ifr(j,0,x.size())
//             cout<<x.mat[i][j]<<" ";
//         cout<<endl;
//     }
//     cout<<endl;
// }

tt operator+(tt &o,tt &p){
    tt res=tt(o.size());
    ifr(i,0,o.size()) ifr(j,0,o.size())
        res.mat[i][j] = (o.mat[i][j]+p.mat[i][j])%mod;
    return res;
}

tt operator*(tt &o,tt &p){
    tt res=tt(o.size());
    ifr(i,0,o.size()) ifr(j,0,o.size()) ifr(k,0,o.size()) {
        res.mat[i][j]+=(o.mat[i][k]*p.mat[k][j])%mod;
        res.mat[i][j]%=mod;
    }
    return res;
}

tt power(tt a,ll b){
    tt res=tt(a.size());
    ifr(i,0,a.size())
        res.mat[i][i]=1;
    while(b){
        if(b&1)
            res=(res*a);
        b>>=1;
        a=(a*a);
    }
    return res;
}