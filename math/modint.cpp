template<unsigned M>
struct modint{
	unsigned val;
	modint(unsigned x):val((x%M+M)%M){}
	modint pow(unsigned r)const{
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
	modint& operator=(const modint& x)&{val=x.val; return *this;}
	modint& operator+=(const modint& x)&{if((val+=x.val)>=M) val-=M; return *this;}
	modint& operator-=(const modint& x)&{if((val+=M-x.val)>=M) val-=M; return *this;}
	modint& operator*=(const modint& x)&{val=(ll)val*x.val%M; return *this;}
	modint& operator/=(const modint& x)&{val=(ll)val*x.inv().val%M; return *this;}
};

template<unsigned M> bool operator==(const modint<M>& a,const modint<M>& b){return a.val==b.val;}
template<unsigned M> bool operator!=(const modint<M>& a,const modint<M>& b){return a.val!=b.val;}
template<unsigned M> modint<M> operator+(modint<M> a,const modint<M>& b){a+=b; return a;}
template<unsigned M> modint<M> operator-(modint<M> a,const modint<M>& b){a-=b; return a;}
template<unsigned M> modint<M> operator*(modint<M> a,const modint<M>& b){a*=b; return a;}
template<unsigned M> modint<M> operator/(modint<M> a,const modint<M>& b){a/=b; return a;}
template<unsigned M> ostream& operator<<(ostream& os,const modint<M>& x){return os<<x.val;}

using mint=modint<MOD>;
