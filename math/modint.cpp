template<uint M>
struct modint{
	uint val;
	modint(ll x):val((x%M+M)%M){}
	modint pow(uint r)const{
		ll a=val,x=1;
		for(;r;r>>=1){
			if(r&1)
				(x*=a)%=M;
			(a*=a)%=M;
		}
		return x;
	}
	modint inv()const{
		ll x=1;
		for(ll a=val,b=M,u=0;b;){
			ll t=a/b;
			swap(a-=b*t,b);
			swap(x-=u*t,u);
		}
		return (x+M)%M;
	}
	modint& operator+=(const modint& x)&{if((val+=x.val)>=M) val-=M; return *this;}
	modint& operator-=(const modint& x)&{if((val+=M-x.val)>=M) val-=M; return *this;}
	modint& operator*=(const modint& x)&{val=(ll)val*x.val%M; return *this;}
	modint& operator/=(const modint& x)&{val=(ll)val*x.inv().val%M; return *this;}
	explicit operator uint()const{return val;}
	friend bool operator==(const modint& a,const modint& b){return a.val==b.val;}
	friend bool operator!=(const modint& a,const modint& b){return a.val!=b.val;}
	friend modint operator+(modint a,const modint& b){a+=b; return a;}
	friend modint operator-(modint a,const modint& b){a-=b; return a;}
	friend modint operator*(modint a,const modint& b){a*=b; return a;}
	friend modint operator/(modint a,const modint& b){a/=b; return a;}
	friend ostream& operator<<(ostream& os,const modint& x){return os<<x.val;}
};

using mint=modint<MOD>;
