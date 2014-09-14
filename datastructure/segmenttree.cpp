// 共通
int NextPow2(int x)
{
	x--;
	for(int i=1;i<32;i*=2) x|=x>>i;
	return x+1;
}
const int I=INF;
int F(int a,int b){return min(a,b);}

// 点更新/区間質問
// Verify: UVa 12299, POJ 3264, AOJ 1068

struct SegmentTree{
	int size;
	vi data;
	SegmentTree(int n):size(NextPow2(n)),data(size*2,I){}
	SegmentTree(const vi& a):size(NextPow2(a.size())),data(size*2,I){
		copy(all(a),begin(data)+size);
		peri(i,1,size) data[i]=F(data[i*2],data[i*2+1]);
	}
	int Get(int i){
		return data[size+i];
	}
	void Update(int i,int x){
		data[size+i]=x;
		for(i+=size;i/=2;) data[i]=F(data[i*2],data[i*2+1]);
	}
	int Query(int a,int b,int i,int l,int r){
		if(b<=l || r<=a) return I;
		if(a<=l && r<=b) return data[i];
		return F(Query(a,b,i*2,l,(l+r)/2),Query(a,b,i*2+1,(l+r)/2,r));
	}
	int Query(int a,int b){
		return Query(a,b,1,0,size);
	}
};

// 点更新/区間質問
// QueryIndex()で対応するインデックスを返す
// Verify: AOJ DSL_2_A

struct SegmentTree{
	int size;
	vi data,index;
	SegmentTree(int n):size(NextPow2(n)),data(size,I),index(size*2){
		iota(size+all(index),0);
		peri(i,1,size) index[i]=index[i*2];
	}
	SegmentTree(const vi& a):size(NextPow2(a.size())),data(size,I),index(size*2){
		copy(all(a),begin(data));
		iota(size+all(index),0);
		peri(i,1,size){
			int u=index[i*2],v=index[i*2+1];
			index[i]=data[u]==F(data[u],data[v])?u:v;
		}
	}
	void Update(int i,int x){
		data[i]=x;
		for(i+=size;i/=2;){
			int u=index[i*2],v=index[i*2+1];
			index[i]=data[u]==F(data[u],data[v])?u:v;
		}
	}
	int QueryIndex(int a,int b,int i,int l,int r){
		if(b<=l || r<=a) return -1;
		if(a<=l && r<=b) return index[i];
		int u=QueryIndex(a,b,i*2,l,(l+r)/2),v=QueryIndex(a,b,i*2+1,(l+r)/2,r);
		if(u==-1 || v==-1) return u!=-1?u:v;
		return data[u]==F(data[u],data[v])?u:v;
	}
	int QueryIndex(int a,int b){
		return QueryIndex(a,b,1,0,size);
	}
};

// 点更新/区間質問 (2次元版)
// Verify: AOJ 1068

struct SegmentTree2D{
	int size;
	vector<SegmentTree> data;
	SegmentTree2D(int h,int w):size(NextPow2(h)),data(size*2,SegmentTree(w)){}
	SegmentTree2D(const vvi& a):size(NextPow2(a.size())),data(size*2,SegmentTree(a[0].size())){
		copy(all(a),begin(data)+size);
		peri(i,1,size) repi(j,1,data[i].data.size())
			data[i].data[j]=F(data[i*2].data[j],data[i*2+1].data[j]);
	}
	int Get(int i,int j){
		return data[size+i].Get(j);
	}
	void Update(int i,int j,int x){
		data[size+i].Update(j,x);
		for(i+=size;i/=2;)
			data[i].Update(j,F(data[i*2].Get(j),data[i*2+1].Get(j)));
	}
	int Query(int a,int b,int c,int d,int i,int to,int bo){
		if(c<=to || bo<=a) return I;
		if(a<=to && bo<=c) return data[i].Query(b,d);
		return F(Query(a,b,c,d,i*2,to,(to+bo)/2),Query(a,b,c,d,i*2+1,(to+bo)/2,bo));
	}
	int Query(int a,int b,int c,int d){
		return Query(a,b,c,d,1,0,size);
	}
};

// 区間更新/点質問
// Verify: ARC026 C

struct SegmentTree{
	int size;
	vi data;
	SegmentTree(int n):size(NextPow2(n)),data(size*2,I){}
	SegmentTree(const vi& a):size(NextPow2(a.size())),data(size*2,I){
		copy(all(a),begin(data)+size);
	}
	void Update(int a,int b,int x,int i,int l,int r){
		if(b<=l || r<=a) return;
		if(a<=l && r<=b){
			data[i]=F(data[i],x);
			return;
		}
		Update(a,b,x,i*2+0,l,(l+r)/2);
		Update(a,b,x,i*2+1,(l+r)/2,r);
	}
	void Update(int a,int b,int x){
		Update(a,b,x,1,0,size);
	}
	int Query(int i){
		int res=I;
		for(i+=size;i;i/=2) res=F(res,data[i]);
		return res;
	}
};

// ------------------------------ 以降は古い実装 ------------------------------

// 区間更新/区間質問．PropagateとMergeを適切に書き換える
// Verify: SPOJ 7259

struct SegmentTree{
	int size;
	vi data,prop;
	SegmentTree(int s):size(Need(s)),data(size*2),prop(size*2){}
	SegmentTree(const vi& a):size(Need(a.size())),data(size*2),prop(size*2){
		copy(all(a),data.begin()+size);
		for(int i=size;--i;)
			data[i]=Merge(data[i*2],data[i*2+1]);
	}
	void Update(int a,int b,int x,int i,int l,int r){
		Propagate(i,l,r);
		if(b<=l || r<=a)
			return;
		if(a<=l && r<=b){
			prop[i]=x;
			Propagate(i,l,r);
			return;
		}
		Update(a,b,x,i*2+0,l,(l+r)/2);
		Update(a,b,x,i*2+1,(l+r)/2,r);
		data[i]=Merge(data[i*2],data[i*2+1]);
	}
	ll Query(int a,int b,int i,int l,int r){
		Propagate(i,l,r);
		if(b<=l || r<=a) return 0;
		if(a<=l && r<=b) return data[i];
		ll x=Query(a,b,i*2+0,l,(l+r)/2);
		ll y=Query(a,b,i*2+1,(l+r)/2,r);
		return Merge(x,y);
	}
	void Update(int a,int b,int x){
		Update(a,b,x,1,0,size);
	}
	int Query(int a,int b){
		return Query(a,b,1,0,size);
	}
	void Propagate(int i,int l,int r){
		if(i<size){
			prop[i*2+0]^=prop[i];
			prop[i*2+1]^=prop[i];
		}
		if(prop[i])
			data[i]=r-l-data[i];
		prop[i]=0;
	}
	int Merge(ll x,ll y){
		return x+y;
	}
};

// 区間Set,Reset,Flip,Count
// Verify: UVa 11402, Codeforces 242E

struct SegmentTree{
	int size;
	vi data,prop;
	SegmentTree(int s):size(Need(s)),data(size*2),prop(size*2){}
	SegmentTree(const vi& a):size(Need(a.size())),data(size*2),prop(size*2){
		copy(all(a),data.begin()+size);
		for(int i=size;--i;)
			data[i]=Merge(data[i*2],data[i*2+1]);
	}
	void Update(int a,int b,int x,int i,int l,int r){
		Propagate(i,l,r);
		if(b<=l || r<=a)
			return;
		if(a<=l && r<=b){
			prop[i]=x;
			Propagate(i,l,r);
			return;
		}
		Update(a,b,x,i*2+0,l,(l+r)/2);
		Update(a,b,x,i*2+1,(l+r)/2,r);
		data[i]=Merge(data[i*2],data[i*2+1]);
	}
	ll Query(int a,int b,int i,int l,int r){
		Propagate(i,l,r);
		if(b<=l || r<=a) return 0;
		if(a<=l && r<=b) return data[i];
		ll x=Query(a,b,i*2+0,l,(l+r)/2);
		ll y=Query(a,b,i*2+1,(l+r)/2,r);
		return Merge(x,y);
	}
	void Propagate(int i,int l,int r){
		if(i<size){
			if(prop[i]==1) prop[i*2+0]=prop[i*2+1]=1;
			if(prop[i]==2) prop[i*2+0]=prop[i*2+1]=2;
			if(prop[i]==3){
				prop[i*2+0]=3-prop[i*2+0];
				prop[i*2+1]=3-prop[i*2+1];
			}
		}
		if(prop[i]==1) data[i]=r-l;
		if(prop[i]==2) data[i]=0;
		if(prop[i]==3) data[i]=r-l-data[i];
		prop[i]=0;
	}
	int Merge(ll x,ll y){
		return x+y;
	}
	void Set(int a,int b){
		Update(a,b,1,1,0,size);
	}
	void Reset(int a,int b){
		Update(a,b,2,1,0,size);
	}
	void Flip(int a,int b){
		Update(a,b,3,1,0,size);
	}
	int Count(int a,int b){
		return Query(a,b,1,0,size);
	}
};
