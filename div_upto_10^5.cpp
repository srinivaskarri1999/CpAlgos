// solve(n) will return vector<ll(or)int> of divisors.
template<typename T>
struct Divisors{   
    vector<pair<T,int>> primefactors;
    vector<T> divisors;

    Divisors() {
        primefactors.clear();divisors.clear();
    }

    void primefactorization(T n){
        int c=0;
        while(n%2==0){
            c++;
            n/=2;
        }
        primefactors.pb(2,c);
        for(T i=3;i*i<=n;i+=2){
            c=0;
            while(n%i==0){
                n/=i;
                c++;
            }
            primefactors.pb(i,c);
        }
        if(n>2) primefactors.pb(n,1);
    }

    void rec(int i,T divisor){
        if(i==primefactors.size()){
            divisors.pb(divisor);
            return;
        }
        T temp = 1;
        ifr(j,0,primefactors[i].ss+1){
            rec(i+1,(T)divisor*temp);
            temp = (T)temp*primefactors[i].ff;
        }
    }

    vector<T> solve(T n) {
        primefactorization(n);
        rec(0,1);
        return divisors;
    }
};