// Verify: AtCoder Typical Contest 001 C

// Mは a.size()の倍数+1 (すなわち大きな2の冪乗の倍数)+1 となるように選ぶこと．
// 例: M=998244353=0b111011100000000000000000000001
template<unsigned M>
void NTT(vector<modint<M>>& a,unsigned root,bool inverse=false){
	int n=a.size();
	for(int i=0;i<n;i++){
		int j=0;
		for(int k=0;(1<<k)<n;k++)
			(j<<=1)|=i>>k&1;
		if(i<j)
			swap(a[i],a[j]);
	}
	for(int m=2;m<=n;m*=2){
		modint<M> r=modint<M>(root).pow((M-1)/m);
		for(int i=0;i<m/2;i++){
			modint<M> wi=r.pow(i);
			if(inverse) wi=wi.inv();
			for(int j=0;j<n;j+=m){
				modint<M> &x=a[i+j],&y=a[i+m/2+j];
				tie(x,y)=mt(x+y*wi,x-y*wi);
			}
		}
	}
	if(inverse)
		for(int i=0;i<n;i++)
			a[i]/=n;
}
