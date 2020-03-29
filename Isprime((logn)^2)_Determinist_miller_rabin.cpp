//Deterministic Miller Rabin
//timecomplexity O( (log2(n))^2 )
ll power(ll a,ll b,ll m) {
    a%=m;
    ll res =1;
    while(b) {
        if(b&1) res=(res*a)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return res;
}

bool check_composite(ll a,ll &r,ll &d,ll &n) {
    a=power(a,d,n);
    if(a==1 || a==n-1) return 0;
    ifr(i,1,r) {
        a=(1ll*a*a)%n;
        if(a==n-1) return 0;
    }
    return 1;
}

bool isprime(ll n) {
    if(n<=1) return 0;
    ll d=n-1,r=0;
    while(!(d&1)) {
        r++;
        d>>=1;
    }
    for(auto a:{2,3,5,7,11,13,17,19,23,29,31,37}) {
        if(n==a) return 1;
        if(check_composite(a,r,d,n)) return 0;
    }
    return 1;
}