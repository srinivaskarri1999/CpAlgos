
//xor convulution (fft)

void fun(vector<int> &a,int n,int inverse) {
    for(int len=2;len<=n;len<<=1) {
        for(int i=0;i<n;i+=len) {
            for(int j=0;j<(len/2);j++) {
                int u = a[i+j];int v = a[i+j+(len)/2];
                a[i+j] = u+v;
                a[i+j+(len/2)] = u-v;
            }
        }
    }
    if(inverse) {
        ll inv = power(n,mod-2);
        for(auto &it:a)
            it=(it*inv)%mod;
    }
}