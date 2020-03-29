
template<typename T>
struct vectorSpace {
    int Ln,sz;
    vector<T> basis;
    vectorSpace(const T n) {
        Ln = log2(n) + 1;
        basis.assign(Ln, 0);
        sz=0;
    }
    // returns size of vector basis
    int size() { return sz; }

    // insert's mask into vector basis
    void insert(T mask) {
        for(int i=0; i<Ln; i++) {
            if( !((mask>>i)&1) ) continue;
            if(!basis[i]) { 
                basis[i] = mask;
                sz++;
                return;
            }
            mask ^= basis[i];
        }
    }

    // returns true if mask can be represented by linear combination of vector basis
    bool check(T mask) {
        for(int i=0; i<Ln; i++) {
            if(!((mask>>i)&1) ) continue;
            if(!basis[i]) return 0;
            mask ^= basis[i];
        }
        return 1;
    }

};