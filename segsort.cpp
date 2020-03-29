#include <bits/stdc++.h>
using namespace std;
#define ms 1000000000
typedef long long ll;
ll *tree[4*100001],ma=1000000000000000005,sol=0;

ll getClosest(ll val1, ll val2, ll target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

ll findClosest(ll arr[], int n, ll target)
{
    if (target <= ms-arr[0])
        return arr[0];
    if (target >= ms-arr[n - 1])
        return arr[n - 1];
    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
        if (ms-arr[mid] == target)
            return arr[mid];
        if (target < ms-arr[mid]) {
            if (mid > 0 && target > ms-arr[mid - 1])
                return ms-getClosest(ms-arr[mid - 1],ms-arr[mid], target);
            j = mid;
        }
        else {
            if (mid < n - 1 && target < ms-arr[mid + 1])
                return ms-getClosest(ms-arr[mid],ms-arr[mid + 1], target);
            i = mid + 1; 
        }
    }
    return arr[mid];
}

ll *con(ll *p1,ll *p2,int l,int mid,int r,int pos)
{
	ll *arr;
	arr=new ll[r-l+1];
	int i=0,j=0,k=0,n1=mid-l+1,n2=r-mid;
	while(i<n1 && j<n2)
	{
	    if((ms-p1[i])>(ms-p2[j]))
	    arr[k++]=p2[j++];
	    else
	    arr[k++]=p1[i++];
	}
	while(i<n1)
	arr[k++]=p1[i++];
	while(j<n2)
	arr[k++]=p2[j++];
	return arr;
}

ll query(ll *a,int s,int e,int l,int r,int pos,ll k)
{
    if(r<s || l>e)
    return ma;
    if (s<=l && e>=r){
	//cout<<"f"<<findClosest(tree[pos],r-l+1,k)<<endl;
        return findClosest(tree[pos],r-l+1,k);
    }
    int mid=l+(r-l)/2;
    ll p1=query(a,s,e,l,mid,2*pos+1,k);
    ll p2=query(a,s,e,mid+1,r,2*pos+2,k);
    if(ms-p1 > ms-p2)
    {
    	ll temp=p2;
    	p2=p1;
    	p1=temp;
    }
    //cout<<p1<<" "<<p2<<endl;
    if(p1==ma)
    {
    	//cout<<p2<<endl;
        return p2;
    }
    if(p2==ma)
    {
    	//cout<<p1<<endl;
        return p1;
    }
    sol=getClosest(ms-p1,ms-p2,k);
    //cout<<ms-sol<<endl;
    return ms-sol;
}

ll *construct(ll *a,int l,int r,int pos)
{
	if(l==r)
	{
		tree[pos]=new ll(a[l]);
		return tree[pos];
	}
	int mid=l+(r-l)/2;
	ll *p1=construct(a,l,mid,2*pos+1);
	ll *p2=construct(a,mid+1,r,2*pos+2);
	tree[pos]=con(p1,p2,l,mid,r,pos);
	return tree[pos];
}

int main() {
    int n,q;
	cin>>n>>q;
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	construct(a,0,n-1,0);
	while(q--)
	{
	    int l,r;
	    ll k;
	    cin>>l>>r>>k;
	    cout<<query(a,l-1,r-1,0,n-1,0,k)<<endl;
	    //cout<<sol<<endl;
	    //cout<<findClosest(ans, r-l+1,k)<<endl;
	}
	return 0;
}