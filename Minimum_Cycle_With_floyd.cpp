
//Floyd's improved writing method can solve the minimum loop problem, the time complexity is still O (n ^ 3), and the storage structure is also an adjacency matrix
 
int mincircle = infinity;
Dist = Graph;

for(int k=0;k<nVertex;++k){
    for(int i=0;i<k;++i)
        for(int j=0;j<i;++j)
            mincircle = min(mincircle,Dist[i][j]+Graph[j][k]+Graph[k][i]);
    // The usual floyd part:
    for(int i=0;i<nVertex;++i)
        for(int j=0;j<i;++j){
            int temp = Dist[i][k] + Disk[k][j];
            if(temp < Dist[i][j])
                Dist[i][j] = Dist[j][i] = temp;
        }
}

 
// The above is the case for undirected graphs.
// The Floyd algorithm ensures that the shortest path between all vertices with 0 ... k-1 as the middle point is obtained when the outermost layer loops to k. A ring has at least 3 vertices. Let the vertex with the largest number in a ring be L. The two vertices directly connected to it in the ring are numbered M and N (M, N <L). The length of the ring is Graph (M, L) + Graph (N, L) + Dist (M, N), where Dist (M, N) represents the shortest path when the vertex 0… L-1 is the middle point, which is just right According to the situation where the outermost loop of Floyd's algorithm reaches k = L, then at this time, for all combinations of vertices with numbers less than L for M and N loops, the smallest ring with the largest number L can be found. After going through the outermost k cycle, we can find the smallest circle of the whole graph.
 
// If it is a directed graph, only minor changes are required. Pay attention to consider the case where two vertices in a directed graph can form a ring.