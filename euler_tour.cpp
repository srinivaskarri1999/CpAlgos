//st[i] ==> starting index of subtree of node i in base array
//en[i] ==> ending index of subtree of node i in base array
int st[N], en[N], base[N], time=0;

void dfs(int u, int pa) {
    base[time] = u;
    st[u] = time++;

    for(auto it:G[u]) {
        if(it==pa) 
            continue;
        dfs(it, u);
    }
    en[u] = time-1;
}