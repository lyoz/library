int ModInverse(int a,int m)
{
	int x,y,g=ExtendedGCD(a,m,x,y);
	if(g==1)
		return (x+m)%m;
	else
		return 0; // invalid
}

void ModInverse(int m,vi& inv)
{
	inv[1]=1;
	repi(i,2,inv.size())
		inv[i]=ll(m-m/i)*inv[m%i]%m;
}
