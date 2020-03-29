struct BPM
{
    vector<set<int>> G;
    vector<int> L,R;
    vector<bool> Viz;
    void init(int n,int m) {
        G.clear();L.clear();R.clear();Viz.clear();
        G.resize(n);L.assign(n,-1);R.assign(m,-1);Viz.assign(n,0);
    }
    void AddEdge(int a,int b) {G[a].insert(b);}
    bool Match(int u) {
        if(Viz[u]) return 0;
        Viz[u]=1;
        for(auto it:G[u]) {
            if(R[it]==-1 || Match(R[it])) {
                L[u]=it;
                R[it]=u;
                return 1;
            }
        }
        return 0;
    }
    int Solve() {
        int f=1;int res=0;
        while(f--) {
            ifr(i,0,Viz.size()) Viz[i]=0;
            ifr(i,0,L.size())
                if(L[i]==-1) 
                    f|=Match(i);
        }
        ifr(i,0,L.size()) res+=(L[i]!=-1);
        return res;       
    }
};
