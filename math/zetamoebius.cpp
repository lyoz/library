// Verify: AOJ 2446

template<typename T>
vector<T> Zeta(const vector<T>& g)
{
	int n=31-clz(g.size());
	vector<T> f=g;
	rep(i,n) rep(s,1<<n)
		if(s>>i&1) f[s]+=f[s^1<<i];
	return f;
}

template<typename T>
vector<T> Moebius(const vector<T>& f)
{
	int n=31-clz(f.size());
	vector<T> g=f;
	rep(i,n) rep(s,1<<n)
		if(s>>i&1) g[s]-=g[s^1<<i];
	return g;
}
