//number of divisors in n^(1/3).

ll divisors(ll n) {
    ll ans = 1,c;
    for(ll i=2;i*i*i<=n;i++) {
        c=1;
        while(n%i==0){
            n/=i;
            c++;
        }
        ans=(ans*c);
    }
    if(isprime(n))
        ans*=2;
    else if(n!=1 && issquare(n))
        ans*=3;
    else if(n!=1)
        ans*=4;
    return ans-1;
}