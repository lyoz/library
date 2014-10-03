int GCD(int a,int b)
{
	return b==0?a:GCD(b,a%b);
}

int LCM(int a,int b)
{
	return a/GCD(a,b)*b;
}

int ExtendedGCD(int a,int b,int& x,int& y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	else{
		int g=ExtendedGCD(b,a%b,y,x);
		y-=a/b*x;
		return g;
	}
}
