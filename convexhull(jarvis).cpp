//srinivas
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
// using namespace __gnu_pbds;

#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define ff first
#define ss second
#define allr(c) (c).rbegin(),(c).rend()
#define fr(x,in,n,r) for(ll x=in;x<n;x+=r)
#define ifr(x,n) for(ll x=0;x<n;x++)
#define dfr(x,n) for(ll x=n-1;x>=0;x--)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pof(a) pop_front(a)
#define pob(a) pop_back(a)
#define eb(a) emplace_back(a)
#define ef(a) emplace_front(a)
typedef long long ll;
typedef map<ll,ll> mll;
typedef map<string,ll> msll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mod 1000000007

struct point{ 
    ll x,y;
	
	bool operator<(const point& t) const
    { 
        if(this->x==t.x)
			return (this->y < t.y);
		return (this->x<t.x);
    } 
};
set<point> p;

ll check(point a,point b,point c){
	return (a.y-c.y)*(a.x-b.x) - (a.x-c.x)*(a.y-b.y);
}

bool dis(point a,point b,point c){
	return (((b.y-a.y)*(b.y-a.y)) + ((b.x-a.x)*(b.x-a.x)))
		 < (((c.y-a.y)*(c.y-a.y)) + ((c.x-a.x)*(c.x-a.x)));
}

void fun(ll n)
{
    if(p.size()<3){
        cout<<"-1\n";
        return;
    }
	point start=*(p.begin());
	set<point>::iterator it,pt;
	it=p.begin();
	for(++it;it!=p.end();it++)
		if(start.x>it->x)
			start=*(it);
	point cur=start;
	set<point> collinear;
	set<point> hull;
	hull.insert(cur);
	while(1){
		point next = *(p.begin());
		it=p.begin();
		for(++it;it!=p.end();it++){
			if(cur.x==it->x && cur.y==it->y)
				continue;
			ll val = check(cur,next,*(it));
			if(val==0){
				if(dis(cur,next,*(it))){
					collinear.insert(next);
					next=*(it);
				}
				else
					collinear.insert(*(it));
			}
			else{
				if(val>0){
					collinear.clear();
					next=*(it);
				}
			}
		}
		it=collinear.begin();
		for(;it!=collinear.end();it++)
			hull.insert(*it);
		collinear.clear();
		if(next.x == start.x && next.y == start.y)
			break;
		cur = next;
		hull.insert(next);
	}
	ll xt=hull.size(),c=1;
	for(it=hull.begin();it!=hull.end();it++){
		cout<<it->x<<" "<<it->y;
		if(c!=xt)
			cout<<", ";
		c++;
	}
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t;
	cin>>n;
	point r;
	ifr(i,n){
		cin>>r.x>>r.y;
		p.insert(r);
	}
	fun(n);
	return 0;
}