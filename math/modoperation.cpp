// Verify: [ModPow] AOJ NTL_1_B, AOJ NTL_1_E
//         [ModInverse] LOJ 1067, LOJ 1102

int ModPow(int a,int r,int m)
{
	int x=1;
	for(;r;r>>=1){
		if(r&1) x=(ll)x*a%m;
		a=(ll)a*a%m;
	}
	return x;
}

// 再帰版
int ModInverse(int a,int m)
{
	int x,y,g=ExtendedGCD(a,m,x,y);
	if(g==1)
		return (x+m)%m;
	else
		return 0; // invalid
}

// 非再帰版
int ModInverse(int a,int m)
{
	int x=1;
	for(int b=m,u=0;b;){
		ll t=a/b;
		swap(a-=b*t,b);
		swap(x-=u*t,u);
	}
	return (x+m)%m;
}

// inv[i]:=i^-1 (mod m)
void ModInverses(int m,vi& inv)
{
	inv[1]=1;
	repi(i,2,inv.size())
		inv[i]=ll(m-m/i)*inv[m%i]%m;
}
