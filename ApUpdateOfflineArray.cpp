
// offline ap updates in array

void add(int l,int r,int a,int d){  // adds AP with first term a and difference d on the range [l...r] (OFFLINE)
    ans[l] += a;
    ans[r+1] -= a + d * (r - l + 1);
    ansf[l] += d;
    ansf[r+1] -= d;
}

void process(){  // Process the offline AP updates
    rep(i , 1 , N){
        ansf[i] += ansf[i-1];
    }
    rep(i , 1 , N){
        ans[i] = ans[i] + ansf[i-1];
    }
    rep(i , 1 , N){
        ans[i] += ans[i-1];
    }
}