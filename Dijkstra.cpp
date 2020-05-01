
// d vector stores shortest distance from src to all nodes
// p vector stores shortest path from src to all nodes

vector<int> path(int src, int dest, vll &d, vector<int> &p) {
    if(d[dest]==inf){
        // there is no path form src to dest
        return {-2};
    }
    vector<int> res;
    while(dest!=src) {
        res.pb(dest);
        dest = p[dest];
    }
    res.pb(src);
    reverse(all(res));
    return res;
}

void dijkstra(int src, vll &d, vector<int> &p) {
    d.assign(n,inf);
    p.assign(n,-1);

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    d[src] = 0;
    q.push({0,src});
    ll dist;
    int u;
    while(!q.empty()) {
        tie(dist,u) = q.top();
        q.pop();
        // check if queue has updated value else continue
        if(d[u]!=dist) continue;

        // it.ff is next node
        // it.ss is length of edge connecting u.ss and it.ff
        for(auto it:G[u]) {
            if( d[it.ff] > (dist + it.ss) ) {
                d[it.ff] = dist + it.ss;
                p[it.ff] = u;
                q.push({d[it.ff],it.ff});
            }
        }
    }
}