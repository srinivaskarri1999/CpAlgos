int cmp_size,subSize[N],centroidpa[N];
bool deleted[N];
void decompose_precal(int u,int prev) {
    subSize[u] = 1;
    cmp_size++;
    for(auto it:G[u]) {
        if(it==prev || deleted[it]) continue;
        decompose_precal(it,u);
        subSize[u]+=subSize[it];
    }
}
int find_centroid(int u,int prev) {
    for(auto it:G[u]) {
        if(it==prev || deleted[it]) continue;
        if(subSize[it]>cmp_size/2)
            return find_centroid(it,u);
    }
    return u;
}
void decompose(int u,int prev) {
    cmp_size = 0;
    decompose_precal(u,-1);
    int centroid = find_centroid(u,-1);
    u = centroid;
    deleted[u] = 1;
    centroidpa[u] = prev;
    for(auto it:G[u]) {
        if(it==prev || deleted[it]) continue;
        decompose(it,u);
    }
}