
//modular inverse
long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}