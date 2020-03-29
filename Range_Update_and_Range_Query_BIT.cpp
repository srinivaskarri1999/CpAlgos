//range update and range query using BIT
ll bit[2][N];

void up(ll a,ll v,ll x) {
    for(;a<N;a+=(a&(-a))) bit[x][a]+=v;
}

void upd(ll a,ll b,ll v) {
    up(a,v,0);
    up(b+1,-v,0);
    up(a,v*(a-1),1);
    up(b+1,-v*(b),1);
}

ll que(ll a,ll x) {
    ll sum = 0;
    for(;a>0;a-=(a&(-a))) sum+=bit[x][a];
    return sum;
}

ll que(ll a) {
    return que(a,0)*a - que(a,1);
}

ll getsum(ll a,ll b) {
    return que(b) - que(a-1);
}