
struct point{
	ll x,y;
	bool operator<(const point& t)const {
		if(this->x==t.x)
			return this->y<t.y;
		return this->x<t.x;
	}
	bool operator==(const point& t)const {
		return ((this->x==t.x) && (this->y==t.y) );
	}
};

point p[N],start;

ll check(point a,point b,point c){
	return (a.x-b.x)*(a.y-c.y) - (a.y-b.y)*(a.x-c.x);
}

ll dist(point a,point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool com(point a,point b){
	ll val=check(start,a,b);
	// cout<<"a "<<a.x<<" "<<a.y<<endl;
	// cout<<"b "<<b.x<<" "<<b.y<<endl;
	// cout<<"val "<<val<<endl;
	if(val==0)
		return dist(start,a)<=dist(start,b);
	return val>0;
}

point next(stack<point> &s){
	point t=s.top();
	s.pop();
	point res=s.top();
	s.push(t);
	return res;
}

void fun(ll n){
	start = p[0];
	ll id=0;
	ifr(i,0,n)
		if( (start.y>p[i].y) || ( start.y==p[i].y && start.x>p[i].x ) ) start=p[i],id=i;
	swap(p[n-1],p[id]);
	n--;
	sort(p,p+n,com);
	ll m=0;
	ifr(i,0,n){
		while(i<n-2 && check(start,p[i],p[i+1])==0)
			i++;
		p[m++]=p[i];
	}
	if(m<3){
		cout<<"convex hull is not possible\n";
		return;
	}
	stack<point> s;
	s.push(start);
	s.push(p[0]);
	s.push(p[1]);
	ifr(i,3,m){
		while(check(next(s),s.top(),p[i])<=0)
			s.pop();
		s.push(p[i]);
	}
	while(!s.empty())
	{
		cout<<s.top().x<<" "<<s.top().y<<endl;
		s.pop();
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    ll n;
    cin>>n;
    ifr(i,n)cin>>p[i].x>>p[i].y;
    fun(n);
	return 0;
}