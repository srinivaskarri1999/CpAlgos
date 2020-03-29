cnt = ((r>>(i+1))<<i);
if((r>>i)&1) cnt+=(r & ((1ll<<i)-1));
cnt -= ((l>>(i+1))<<i);
if((l>>i)&1) cnt-=(l & ((1ll<<i)-1));