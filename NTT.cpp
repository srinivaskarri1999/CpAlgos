
int power(int a,int b,int m) {
    int res = 1;
    while(b) {
        if(b&1) res = (1ll*res*a)%m;
        a=(1ll*a*a)%m;
        b>>=1;
    }
    return res;
}

int power(int &a,int b){
    return power(a,b,mod);
}

int inverse(int &a) {
    return power(a,mod-2);
}

int checkpr(int &a) {
    return power(a,(mod-1)/2)!=1;
}

struct NTT {
    int k = 23;
    int c = 7*17;

    int pr,prc;

    NTT() {
        pr = 2;
        while(!checkpr(pr)) pr++;
        prc = power(pr,c);
    }

    void transform(vector<int> &a,bool inv) {
        int n = a.size(),bit;
        for(int i=1,j=0;i<n;i++) {
            bit = n>>1;
            for(;j&bit;bit>>=1) j^=bit;
            j^=bit;
            if(i<j) swap(a[i],a[j]);
        }
        int wlen,w,pw,u,v;
        for(int len=2;len<=n;len<<=1) {
            pw = (1ll<<k)/len;
            wlen = power(prc,pw);
            if(inv) wlen = inverse(wlen);
            for(int i=0;i<n;i+=len) {
                w = 1;
                for(int j=0;j<len/2;j++) {
                    u = a[i+j];
                    v = (1ll*a[i+j+len/2]*w)%mod;
                    a[i+j] = (u+v)<mod?(u+v):(u+v-mod);
                    a[i+j+len/2] = (u>=v)?(u-v):(u-v+mod);
                    w = (1ll*w * wlen)%mod;
                }
            }
        }
        if(inv) {
            int rev = inverse(n);
            for(int i=0;i<n;i++)
                a[i] = (1ll*a[i]*rev)%mod;
        }
    }
}x;
