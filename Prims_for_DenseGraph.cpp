
//Prims algo for Dense graphs Time Complexity ==> O(N^2)
//G is orginal Graph
//mst stores minimum spanning tree graph 
//mstedges stores edges present in minimum spanning tree

//solve() Returns -1 if there is no minimum spanning tree
//else minimum cost of spanning tree

template<typename T>
struct Prims {
    struct Edge {
        T weight=inf;int to=-1;
    };
    vector<Edge> G[N];
    vector<int> mst[N];
    vector<pair<int,int>> mstedges;
    int nt;
    Prims(int n) {
        nt = n;
        for(int i=0;i<n;i++) G[i].clear(),mst[i].clear();
        mstedges.clear();
    }
    void AddEdge(int x,int y,T w) {
        Edge r;r.weight = w;r.to = y;
        G[x].pb(r);
        r.to = x;
        G[y].pb(r);
    }
    //Returns -1 if there is no minimum spanning tree
    //else minimum cost of spanning tree
    T solve() {
        T total_weight = 0;
        vector<bool> selected(nt,0);
        vector<Edge> min_e(nt);
        min_e[0].weight=0;
        for(int i=0;i<nt;i++){
            int v=-1;
            for(int j=0;j<nt;j++) {
                if(!selected[j] && (v==-1 || min_e[j].weight<min_e[v].weight))
                    v=j;
            }
            if(v==-1) return -1;
            selected[v]=1;
            total_weight+=min_e[v].weight;
            if(min_e[v].to!=-1) mst[v].pb(min_e[v].to),mst[min_e[v].to].pb(v),mstedges.pb(v,min_e[v].to);
            for(auto ch:G[v])
                if(ch.weight<min_e[ch.to].weight)
                    min_e[ch.to]={ch.weight,v};
        }
        return total_weight;
    }
};