//st[i] ==> starting index of subtree of node i in base array
//en[i] ==> ending index of subtree of node i in base array
int st[N], en[N], base[N], tim=0;

void dfs(int u, int pa) {
    base[tim] = u;
    st[u] = tim++;

    for(auto it:G[u]) {
        if(it==pa) 
            continue;
        dfs(it, u);
    }
    en[u] = tim-1;
}