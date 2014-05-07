// 点更新/区間質問
// Verify: POJ 3067, POJ 3928

struct FenwickTree{
	vector<ll> data;
	FenwickTree(int n):data(n+1){}
	void Add(int i,int x){
		for(i++;i<data.size();i+=i&-i)
			data[i]+=x;
	}
	ll Sum(int i){
		ll res=0;
		for(;i;i-=i&-i)
			res+=data[i];
		return res;
	}
	ll Sum(int i,int j){
		return Sum(j)-Sum(i);
	}
};

// 区間更新/点質問
// Verify: AOJ 2412, LOJ 1080, POJ 2182

struct FenwickTree{
	vector<ll> data;
	FenwickTree(int n):data(n+1){}
	void AddRange(int i,int x){
		for(;i;i-=i&-i)
			data[i]+=x;
	}
	void AddRange(int i,int j,int x){
		AddRange(i,-x);
		AddRange(j,x);
	}
	int Get(int i){
		ll res=0;
		for(i++;i<data.size();i+=i&-i)
			res+=data[i];
		return res;
	}
};

// 2次元版，点更新/区間質問
// Verify: POJ 1195

struct FenwickTree2D{
	vector<FenwickTree> data;
	FenwickTree2D(int h,int w):data(h+1,FenwickTree(w)){}
	void Add(int i,int j,int x){
		for(i++;i<data.size();i+=i&-i)
			data[i].Add(j,x);
	}
	ll Sum(int i,int j){
		ll res=0;
		for(;i;i-=i&-i)
			res+=data[i].Sum(j);
		return res;
	}
	ll Sum(int i,int j,int k,int l){
		return Sum(k,l)-Sum(k,j)-Sum(i,l)+Sum(i,j);
	}
};
