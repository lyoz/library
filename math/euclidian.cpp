// Verify: [ExtendedGCD] AOJ NTL_1_E, LOJ 1067

int GCD(int a,int b)
{
	return b==0?a:GCD(b,a%b);
}

int LCM(int a,int b)
{
	return a/GCD(a,b)*b;
}

// 再帰版
int ExtendedGCD(int a,int b,int& x,int& y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	else{
		int g=ExtendedGCD(b,a%b,x,y);
		tie(x,y)=make_tuple(y,x-a/b*y);
		return g;
	}
}

// 非再帰版
int ExtendedGCD(int a,int b,int& x,int& y)
{
	x=1,y=0;
	for(int u=0,v=1;b;){
		ll t=a/b;
		swap(a-=b*t,b);
		swap(x-=u*t,u);
		swap(y-=v*t,v);
	}
	return a;
}
