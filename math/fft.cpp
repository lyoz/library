// Verify: AtCoder Typical Contest 001 C

using Complex=complex<double>;
constexpr Complex I(0,1);

void FFT(vector<Complex>& a,bool inverse=false)
{
	int n=a.size();
	for(int i=0;i<n;i++){
		int j=0;
		for(int k=0;(1<<k)<n;k++)
			(j<<=1)|=i>>k&1;
		if(i<j)
			swap(a[i],a[j]);
	}
	int sign=inverse?1:-1;
	for(int m=2;m<=n;m*=2){
		double theta=sign*2*PI/m;
		for(int i=0;i<m/2;i++){
			Complex wi=exp(I*theta*(double)i);
			for(int j=0;j<n;j+=m){
				Complex &x=a[i+j],&y=a[i+m/2+j];
				tie(x,y)=mt(x+y*wi,x-y*wi);
			}
		}
	}
	if(inverse)
		for(int i=0;i<n;i++)
			a[i]/=n;
}
