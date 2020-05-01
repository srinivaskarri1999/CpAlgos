
// d vector stores shortest distance from src to all nodes
// p vector stores shortest path from src to all nodes
void dijkstra(int src, vector<int> &d, vector<int> &p) {
    d.assign(n,inf);
    p.assign(n,-1);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    d[src] = 0;
    q.push({0,src});
    pair<int,int> u;
    while(!q.empty()) {
        // u.ff is shortest distance from src to u.ss
        u = q.top();
        q.pop();
        // check if queue has updated value else continue
        if(d[u.ss]!=u.ff)
            continue;

        // it.ff is next node
        // it.ss is length of edge connecting u.ss and it.ff
        for(auto it:G[u.ss]) {
            if(u.ff+it.ss < d[it.ff]) {
                d[it.ff] = u.ff + it.ss;
                p[it.ff] = u.ss;
                q.push({d[it.ff],it.ff});
            }
        }
    }
}