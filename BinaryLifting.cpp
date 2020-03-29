//BINARY LIFITING 

int pa[LN][N];

int dept[N];

void pre_dfs(int u,int par) {
    for(auto ch:G[u]) {
        if(ch!=par) {
            pa[0][ch]=u;
            dept[ch]=dept[u]+1;
            pre_dfs(ch,u);
        }
    }
}

int walk(int u,int k) {
    ifr(i,0,LN) if((k>>i)&1) u = pa[i][u];
    return u;
}

int lca(int x,int y) {
    if(dept[x] < dept[y] ) swap(x,y);
    x = walk(x,dept[x] - dept[y]);
    if(x==y) return x;
    ifr(i,LN,0) if(pa[i][x]!=pa[i][y]) {
        x = pa[i][x];
        y = pa[i][y];
    }
    return pa[0][x];
}

void precal(int n){
    dept[0]=0;
    pre_dfs(0,0);
    ifr(i,1,LN) ifr(j,0,n) if(pa[i-1][j]!=-1) 
        pa[i][j] = pa[i-1][pa[i-1][j]];
}
