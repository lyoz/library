// 周期は2^k-1 (k=32,64,128).
// 参考: http://www.jstatsoft.org/v08/i14/paper

uint xor32(){
	static uint y=2463534242;
	y^=y<<13; y=y>>17;
	return y^=y<<5;
}

uint xor64()
{
	static ull x=88172645463325252ll;
	x^=x<<13; x^=x>>7;
	return x^=x<<17;
}

uint xor128(){
	static uint x=123456789,y=362436069,z=521288629,w=88675123;
	uint t=x^x<<11;
	x=y; y=z; z=w;
	return w=w^w>>19^t^t>>8;
}

// N3337: 26.5.1.3 Uniform random number generator requirements を満たすジェネレータ
struct xor128_generator{
	using result_type=uint;
	static constexpr uint min(){return 0;}
	static constexpr uint max(){return UINT_MAX;}
	uint operator()(){return xor128();}
};
