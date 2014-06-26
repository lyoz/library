// Verify: UVa 12299, POJ 3264, AOJ 1068

int Need(int x)
{
	x--;
	for(int i=1;i<32;i*=2) x|=x>>i;
	return x+1;
}

struct SegmentTree{
	int size;
	vi data;
	SegmentTree(int s):size(Need(s)),data(size*2,INFTY){}
	SegmentTree(const vi& a):size(Need(a.size())),data(size*2,INFTY){
		copy(all(a),data.begin()+size);
		for(int i=size;--i;)
			data[i]=min(data[i*2],data[i*2+1]);
	}
	int Get(int i){
		return data[size+i];
	}
	void Update(int i,int x){
		data[size+i]=x;
		for(i=(i+size)/2;i;i/=2)
			data[i]=min(data[i*2],data[i*2+1]);
	}
	int Query(int a,int b,int i,int l,int r){
		if(b<=l || r<=a) return INFTY;
		if(a<=l && r<=b) return data[i];
		return min(Query(a,b,i*2,l,(l+r)/2),Query(a,b,i*2+1,(l+r)/2,r));
	}
	int Query(int a,int b){
		return Query(a,b,1,0,size);
	}
};

// Query()で対応するインデックスを返す
// Verify: AOJ DSL_2_A

struct SegmentTree{
	int I(){return numeric_limits<int>::max();}
	int F(int a,int b){return min(a,b);}
	int size;
	vi data;
	SegmentTree(int s):size(Need(s)),data(size*2,I()){
		Build();
	}
	SegmentTree(const vi& a):size(Need(a.size())),data(size*2,I()){
		copy(all(a),begin(data)+size);
		Build();
	}
	void Build(){
		peri(i,1,size){
			int u=i*2,v=i*2+1;
			if(v<size) u=data[u],v=data[v];
			data[i]=data[u]==F(data[u],data[v])?u:v;
		}
	}
	int Get(int i){
		return data[size+i];
	}
	void Update(int i,int x){
		data[i+=size]=x;
		while(i/=2){
			int u=i*2,v=i*2+1;
			if(v<size) u=data[u],v=data[v];
			data[i]=data[u]==F(data[u],data[v])?u:v;
		}
	}
	int QueryIndex(int a,int b,int i,int l,int r){
		if(b<=l || r<=a) return 0;
		if(a<=l && r<=b) return i<size?data[i]:i;
		int u=QueryIndex(a,b,i*2,l,(l+r)/2),v=QueryIndex(a,b,i*2+1,(l+r)/2,r);
		return data[u]==F(data[u],data[v])?u:v;
	}
	int QueryIndex(int a,int b){
		int res=QueryIndex(a,b,1,0,size);
		return res==0?-1:res-size;
	}
	int Query(int a,int b){
		return data[QueryIndex(a,b,1,0,size)];
	}
};

// 2次元版
// Verify: AOJ 1068

struct SegmentTree2D{
	int size;
	vector<SegmentTree> data;
	SegmentTree2D(int h,int w):size(Need(h)),data(size*2,SegmentTree(w)){}
	SegmentTree2D(const vvi& a):size(Need(a.size())),data(size*2,SegmentTree(a[0].size())){
		copy(all(a),data.begin()+size);
		for(int i=size;--i;)
			repi(j,1,data[i].data.size())
				data[i].data[j]=min(data[i*2].data[j],data[i*2+1].data[j]);
	}
	int Get(int i,int j){
		return data[size+i].Get(j);
	}
	void Update(int i,int j,int x){
		data[size+i].Update(j,x);
		for(i=(i+size)/2;i;i/=2)
			data[i].Update(j,min(data[i*2].Get(j),data[i*2+1].Get(j)));
	}
	int Query(int a,int b,int c,int d,int i,int to,int bo){
		if(c<=to || bo<=a) return INFTY;
		if(a<=to && bo<=c) return data[i].Query(b,d);
		return min(Query(a,b,c,d,i*2,to,(to+bo)/2),Query(a,b,c,d,i*2+1,(to+bo)/2,bo));
	}
	int Query(int a,int b,int c,int d){
		return Query(a,b,c,d,1,0,size);
	}
};

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


