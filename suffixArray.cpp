// Reference :- https://cp-algorithms.com/string/suffix-array.html
vector<int> sortSuffix(string const &s) {
    int n = s.length(),t = 256;
    vector<int> p(n),c(n),cnt(max(n,t),0);
    ifr(i,0,n) cnt[s[i]]++;
    ifr(i,1,t) cnt[i]+=cnt[i-1];
    ifr(i,0,n) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int cls = 1;
    ifr(i,1,n) {
        if(s[p[i]]!=s[p[i-1]])
            cls++;
        c[p[i]] = cls - 1;
    }

    vector<int> pn(n),cn(n);
    pair<int,int> prev,curr;
    for(int h = 0; (1<<h)<n; h++) {
        ifr(i,0,n) {
            pn[i] = p[i] - (1<<h);
            if(pn[i]<0) pn[i] += n;
        }
        fill(cnt.begin(),cnt.begin()+cls,0);
        ifr(i,0,n) cnt[c[pn[i]]]++;
        ifr(i,1,cls) cnt[i] += cnt[i-1];
        ifr(i,n,0) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        cls = 1;
        ifr(i,1,n) {
            prev = { c[p[i-1]], c[(p[i-1]+(1<<h))%n] };
            curr = { c[p[i]], c[(p[i]+(1<<h))%n]};
            if(prev != curr)
                cls++;
            cn[p[i]] = cls - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffixCon(string s) {
    s += "$";
    vector<int> res = sortSuffix(s);
    res.erase(res.begin());
    return res;
}

//lcp of subtrings starting with i and j is min of ( lcp[i], lcp[i+1], .... lcp[j] )
vector<int> lcpCon(string const &s, vector<int> const &p) {
    int n = s.length();
    vector<int> has(n,0);
    ifr(i,0,n) has[p[i]] = i;
    int k = 0,j;
    vector<int> lcp(n-1,0);
    ifr(i, 0, n) {
        if(has[i]==n-1) {
            k = 0;
            continue;
        }

        j = p[has[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k])
            k++;
        lcp[has[i]] = k;
        if(k) k--;
    }
    return lcp;
}