// Verify: ZOJ 3645

bool Gauss(const vvd& _a,const vd& _b,vd& x)
{
	vvd a=_a; vd b=_b;
	int n=a.size();
	
	rep(i,n){
		int pivot=i;
		repi(j,i+1,n)
			if(abs(a[j][i])>abs(a[pivot][i]))
				pivot=j;
		if(abs(a[pivot][i])<EPS)
			return false;
		
		swap(a[i],a[pivot]);
		swap(b[i],b[pivot]);
		
		repi(j,i+1,n)
			a[i][j]/=a[i][i];
		b[i]/=a[i][i];
		
		repi(j,i+1,n){
			repi(k,i+1,n)
				a[j][k]-=a[j][i]*a[i][k];
			b[j]-=a[j][i]*b[i];
		}
	}
	
	per(i,n) per(j,i)
		b[j]-=a[j][i]*b[i];
	x=b;
	return true;
}
