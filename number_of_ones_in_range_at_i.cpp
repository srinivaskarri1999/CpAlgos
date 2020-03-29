
// cnt stores number of 1's in a range from 'l' to 'r-1' (inclusive) at ith bit

// count upto r
cnt = ((r>>(i+1))<<i);
if((r>>i)&1) cnt+=(r & ((1ll<<i)-1));
//sub count upto l from cnt
cnt -= ((l>>(i+1))<<i);
if((l>>i)&1) cnt-=(l & ((1ll<<i)-1));