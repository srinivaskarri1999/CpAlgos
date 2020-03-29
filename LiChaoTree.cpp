
// Convex Hull Trick Online 
// Use dynamic segment tree when range is very high

struct Point {
    ll x,y,z;
    Point(ll a=0,ll b=0,ll c=0) {
        x=a;y=b;z=c;
    }
};

struct LiChaoTree {
    vector<Point> line;
    LiChaoTree() {
        //N is the largest value of query
        line.resize(4 * N + 5,Point(0,0,inf));
    }
    ll dot(Point a,Point b) {
        return (a.x*b.x+a.y*b.y+a.z*b.z);
    }
    ll f(Point a,ll x) {
        // Modify the function acc to the question
        return dot(a,Point(x,x*x,1));
    }
    void add(Point nw,int l=0,int r=N,int pos=1) {
        int m = (l+r)/2;
        bool lef = f(nw,l) < f(line[pos],l);
        bool mid = f(nw,m) < f(line[pos],m);
        if(mid) swap(line[pos],nw);
        if(r-l == 1) return;
        if(lef!=mid) add(nw,l,m,2*pos);
        else add(nw,m,r,2*pos+1);
    }
    ll query(ll x,int l=0,int r=N,int pos=1) {
        int m = (l+r)/2;
        if(r-l == 1) return f(line[pos],x);
        if(x<m) return min(f(line[pos],x),query(x,l,m,2*pos));
        return min(f(line[pos],x),query(x,m,r,2*pos+1));
    }
};