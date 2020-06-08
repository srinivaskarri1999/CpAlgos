//modulo inverse
// inv[i] is inverse of i
inv[1] = 1; 
ifr(i, 2, N) inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
