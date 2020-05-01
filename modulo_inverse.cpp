//modulo inverse

ifac[1] = 1; 
ifr(i, 2, N) ifac[i] = (mod - (mod/i) * ifac[mod%i] % mod) % mod;
