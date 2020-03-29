#define Ln 18
int chainIndex[N],chainHead[N],subSize[N],pa[Ln][N];
int posInBase[N],pi,chainNo,dept[N];
// write segment tree code here
//Write LCA BINARY LIFTING CODE and CALCULATE SubSize in that LCA_DFS function
segtree<tt,int> st;
tt base[N],cost[N];
void hld(int u,int prev) {
    if(chainHead[chainNo]==-1) chainHead[chainNo] = u;
    chainIndex[u] = chainNo;
    posInBase[u] = pi;
    base[pi++] = cost[u]; 
    int sc=-1;
    for(auto it:G[u]){
        if(it==prev) continue;
        if(sc==-1 || subSize[sc]<subSize[it])
            sc = it;
    }
    if(sc!=-1) hld(sc,u);
    for(auto it:G[u]) {
        if(it==prev || it==sc) continue;
        chainNo++;
        hld(it,u);
    }
}
tt query_up(int u,int v) {
    int uchain,vchain = chainIndex[v];
    tt ans;
    while(1) {
        uchain = chainIndex[u];
        if(uchain == vchain) {
            st.merge(ans,ans,st.query(posInBase[v],posInBase[u]));
            break;
        }
        st.merge(ans,ans,st.query(posInBase[chainHead[uchain]],posInBase[u]));
        u = chainHead[uchain];
        u = pa[0][u];
    }
    return ans;
}
tt query(int l,int r) {
    int lca = LCA(l,r);
    tt tmp;
    st.merge(tmp,query_up(l,lca),query_up(r,lca));
    return tmp;
}
void init() {
    ifr(i,0,N) chainHead[i]=-1,G[i].clear();
    dept[0] = pi = chainNo =0;
    ifr(i,0,Ln) ifr(j,0,N) pa[i][j] = -1;
}
