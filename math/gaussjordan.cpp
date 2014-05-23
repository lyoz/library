// Verify: AOJ 1328, ZOJ 3645

bool GaussJordan(const vvd& _a,const vd& b,vd& x)
{
	int n=_a.size();
	vvd a(n,vd(n+1));
	rep(i,n){
		copy(all(_a[i]),begin(a[i]));
		a[i][n]=b[i];
	}
	
	rep(i,n){
		int p=i;
		repi(j,i+1,n) if(abs(a[p][i])<abs(a[j][i])) p=j;
		if(abs(a[p][i])<EPS) return false;
		swap(a[i],a[p]);
		peri(j,i,n+1) a[i][j]/=a[i][i];
		rep(j,n) if(j!=i) peri(k,i,n+1) a[j][k]-=a[j][i]*a[i][k];
	}
	
	rep(i,n) x[i]=a[i][n];
	return true;
}
