//BINARY LIFITING 

#define Ln 18 // log2(N)

int pa[N][18],d[N];

void pre_dfs(int u,int p=-1) {
    pa[u][0] = p;
    ifr(i, 1, 18) pa[u][i] = ~pa[u][i-1]?pa[pa[u][i-1]][i-1]:-1;
    for(int ch:G[u])
        if(ch != p) {
            d[ch] = d[u]+1;
            pre_dfs(ch, u);
        }
}

int walk(int u,int k) {
    ifr(i,0,LN) if((k>>i)&1) u = pa[u][i];
    return u;
}

int lca(int x,int y) {
    if(d[x] < d[y] ) swap(x,y);
    x = walk(x, d[x] - d[y]);
    if(x==y) return x;
    ifr(i,LN,0) if(pa[x][i]!=pa[y][i]) {
        x = pa[x][i];
        y = pa[y][i];
    }
    return pa[x][0];
}
