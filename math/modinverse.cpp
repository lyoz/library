int ModInverse(int a,int m)
{
	int x,y;
	int g=ExtendedGCD(a,m,x,y);
	if(g==1)
		return (x+m)%m;
	else
		return 0; // invalid
}
