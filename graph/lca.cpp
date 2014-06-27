// Verify: AOJ GRL_5_C

// by Doubling, O(n log n)-space
struct LCA{
	vi ds;
	vvi ps;
	LCA(const Graph& g,int root):ds(g.size()),ps(32-clz(g.size()),vi(g.size(),-1)){
		DFS(g,-1,root,0);
		rep(i,ps.size()-1) rep(j,ps[i].size())
			ps[i+1][j]=ps[i][j]==-1?-1:ps[i][ps[i][j]];
	}
	void DFS(const Graph& g,int p,int v,int d){
		ds[v]=d;
		ps[0][v]=p;
		for(auto e:g[v]) if(e.dst!=p)
			DFS(g,e.src,e.dst,d+1);
	}
	int Find(int u,int v){
		if(ds[u]>ds[v]) swap(u,v);
		rep(i,ps.size())
			if(ds[v]-ds[u]>>i&1)
				v=ps[i][v];
		if(u==v) return u;
		per(i,ps.size())
			if(ps[i][u]!=ps[i][v])
				u=ps[i][u],v=ps[i][v];
		return ps[0][u];
	}
};

// by RMQ, O(n)-space
struct LCA{
	vi tour,fs;
	SegmentTree st;
	LCA(const Graph& g,int root):fs(g.size(),INF),st(1){
		vi ds;
		DFS(g,-1,root,0,ds);
		rep(i,tour.size()) if(fs[tour[i]]==INF) fs[tour[i]]=i;
		st=SegmentTree(ds);
	}
	void DFS(const Graph& g,int p,int v,int d,vi& ds){
		tour.push_back(v);
		ds.push_back(d);
		for(auto e:g[v]) if(e.dst!=p){
			DFS(g,e.src,e.dst,d+1,ds);
			tour.push_back(v);
			ds.push_back(d);
		}
	}
	int Find(int u,int v){
		if(fs[u]>fs[v]) swap(u,v);
		return tour[st.QueryIndex(fs[u],fs[v]+1)];
	}
};
