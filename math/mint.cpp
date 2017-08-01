template<unsigned M>
struct mint{
	unsigned val;
	mint(unsigned x):val((x%M+M)%M){}
	mint inv()const{
		unsigned x=1;
		for(unsigned a=val,b=M,u=0;b;){
			ll t=a/b;
			swap(a-=b*t,b);
			swap(x-=u*t,u);
		}
		return x;
	}
	mint& operator=(const mint& x)&{val=x.val; return *this;}
	mint& operator+=(const mint& x)&{if((val+=x.val)>=M) val-=M; return *this;}
	mint& operator-=(const mint& x)&{if((val+=M-x.val)>=M) val-=M; return *this;}
	mint& operator*=(const mint& x)&{val=(ll)val*x.val%M; return *this;}
	mint& operator/=(const mint& x)&{val=(ll)val*x.inv().val%M; return *this;}
};

template<unsigned M> bool operator==(const mint<M>& a,const mint<M>& b){return a.val==b.val;}
template<unsigned M> bool operator!=(const mint<M>& a,const mint<M>& b){return a.val!=b.val;}
template<unsigned M> mint<M> operator+(mint<M> a,const mint<M>& b){a+=b; return a;}
template<unsigned M> mint<M> operator-(mint<M> a,const mint<M>& b){a-=b; return a;}
template<unsigned M> mint<M> operator*(mint<M> a,const mint<M>& b){a*=b; return a;}
template<unsigned M> mint<M> operator/(mint<M> a,const mint<M>& b){a/=b; return a;}
template<unsigned M> ostream& operator<<(ostream& os,const mint<M>& x){return os<<x.val;}
