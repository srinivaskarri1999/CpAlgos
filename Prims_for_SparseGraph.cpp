
//Prims algo for Sparse graphs Time Complexity ==> O(M * log(N)) M ==> number of edges
//G is orginal Graph
//mst stores minimum spanning tree graph 
//mstedges stores edges present in minimum spanning tree

//solve() Returns -1 if there is no minimum spanning tree
//else minimum cost of spanning tree

template<typename T>
struct Prims {
    struct Edge {
        T w=inf;int to=-1;
        bool operator<(Edge const& o) const {
            if(w==o.w)
                return to<o.to;
            return w<o.w;
        }
    };
    int nt;
    vector<Edge> G[N];
    vector<int> mst[N];
    vector<pair<int,int>> mstedges;
    Prims(int n) {
        ifr(i,0,n) G[i].clear(),mst[i].clear();
        nt=n;mstedges.clear();
    }
    void AddEdge(int x,int y,T w) {
        Edge r={w,y};
        G[x].pb(r);
        r={w,x};
        G[y].pb(r);
    }
    T solve() {
        T total_weight = 0;
        vector<bool> selected(nt,0);
        vector<Edge> min_e(nt);
        min_e[0].w=0;
        set<Edge> s;
        s.insert({0,0});
        ifr(i,0,nt) {
            if(s.empty()) return -1;
            Edge e = *(s.begin());
            int v = e.to;
            selected[v]=1;
            s.erase(s.begin());
            total_weight+=e.w;
            if(min_e[v].to!=-1) {
                mstedges.pb(v,min_e[v].to);
                mst[v].pb(min_e[v].to);
                mst[min_e[v].to].pb(v);
            }
            for(auto ch:G[v]) {
                if(!selected[ch.to] && ch.w<min_e[ch.to].w) {
                    s.erase({min_e[ch.to].w,ch.to});
                    min_e[ch.to]={ch.w,v};
                    s.insert(ch);
                }
            }
        }
        return total_weight;
    }
};