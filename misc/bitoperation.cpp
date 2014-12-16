// population count
inline int popcount(uint x)
{
	x=(x&0x55555555)+(x>>1&0x55555555);
	x=(x&0x33333333)+(x>>2&0x33333333);
	x=(x&0x0f0f0f0f)+(x>>4&0x0f0f0f0f);
	x=(x&0x00ff00ff)+(x>>8&0x00ff00ff);
	return (x&0x0000ffff)+(x>>16&0x0000ffff);
}
inline int popcountll(ull x)
{
	return popcount(x)+popcount(x>>32);
}

// count leading zero
inline int clz(uint x)
{
	int i=0;
	if(!(x&0xffff0000)) i+=16,x<<=16;
	if(!(x&0xff000000)) i+=8,x<<=8;
	if(!(x&0xf0000000)) i+=4,x<<=4;
	if(!(x&0xc0000000)) i+=2,x<<=2;
	if(!(x&0x80000000)) i+=1,x<<=1;
	return i+!x;
}
inline int clzll(ull x)
{
	int y=clz(x>>32);
	return y==32?y+clz(x):y;
}

// count trailing zero
inline int ctz(uint x)
{
	int i=0;
	if(!(x&0x0000ffff)) i+=16,x>>=16;
	if(!(x&0x000000ff)) i+=8,x>>=8;
	if(!(x&0x0000000f)) i+=4,x>>=4;
	if(!(x&0x00000003)) i+=2,x>>=2;
	if(!(x&0x00000001)) i+=1,x>>=1;
	return i+!x;
}
inline int ctzll(ull x)
{
	int y=ctz(x);
	return y==32?y+ctz(x>>32):y;
}

// find first set
inline int ffs(uint x)
{
	return x?clz(x)+1:0;
}
inline int ffs(ull x)
{
	return x?clzll(x)+1:0;
}

// bitwise reverse
inline uint bitrev(uint x)
{
	x=(x&0xaaaaaaaa)>>1|(x&0x55555555)<<1;
	x=(x&0xcccccccc)>>2|(x&0x33333333)<<2;
	x=(x&0xf0f0f0f0)>>4|(x&0x0f0f0f0f)<<4;
	x=(x&0xff00ff00)>>8|(x&0x00ff00ff)<<8;
	return (x&0xffff0000)>>16|(x&0x0000ffff)<<16;
}
inline ull bitrev(ull x)
{
	return bitrev(x>>32)|(ull)bitrev(x)<<32;
}

// 非零部分集合を列挙
for(int s=b;s;s=(s-1)&b){
	...
}

// {0,1,...,n-1}の，サイズkの部分集合を列挙
// 最終行を s|=(lz>>ffs(lo))-1 とすれば除算をなくせる
// 注意: 0<k<=n でなければならない
for(int s=(1<<k)-1;!(s&1<<n);){
	/* ... */
	int lo=s&-s,lz=(s+lo)&~s;
	s=(s|lz)&~(lz-1);
	s|=(lz/lo/2-1);
}
