// ModMulとwsは問題に応じて使い分けること．
// witnessは以下のページを参考にした:
//   http://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
//   http://mathworld.wolfram.com/StrongPseudoprime.html
//   http://oeis.org/A014233
// Verify: SPOJ 288

// a*b mod m
ull ModMul(ull a,ull b,ull m)
{
	//return a*b%m;
	ull c=0;
	for(;b;b>>=1,(a<<=1)%=m)
		if(b&1)
			(c+=a)%=m;
	return c;
}
// a^r mod m
ull ModPow(ull a,ull r,ull m)
{
	if(r==0) return 1;
	ull b=ModPow(a,r/2,m);
	b=ModMul(b,b,m);
	return r&1?ModMul(b,a,m):b;
}
bool MillerTest(ull n,int a,ull d,int s)
{
	ull x=ModPow(a,d,n);
	if(x==1) return true;
	for(int i=0;i<s;i++){
		if(x==n-1) return true;
		x=ModMul(x,x,n);
	}
	return false;
}
bool MillerRabin(ull n)
{
	if(n<=1)   return false;
	if(n%2==0) return n==2;
	ull d=n-1; int s=0;
	while(d%2==0)
		d/=2,s++;
	//int ws[]={2,7,61,-1}; // n<4759123141
	int ws[]={2,3,5,7,11,13,17,19,23,-1}; // n<3825123056546413051 (conjectured)
	for(int i=0;~ws[i] && ws[i]<n;i++)
		if(!MillerTest(n,ws[i],d,s))
			return false;
	return true;
}
