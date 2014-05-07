// Verify: POJ 1330

struct LCA{
	vi ds;
	vvi ps;
	LCA(vvi& g,int root){
		ds.resize(g.size());
		ps.resize(33-__builtin_clz(g.size()-1),vi(g.size(),-1));
		DFS(g,root,-1,0);
		rep(i,ps.size()-1)
			rep(j,ps[i].size())
				ps[i+1][j]=ps[i][j]==-1?-1:ps[i][ps[i][j]];
	}
	void DFS(vvi& g,int cur,int prev,int depth){
		ds[cur]=depth;
		ps[0][cur]=prev;
		rep(i,g[cur].size())
			if(g[cur][i]!=prev)
				DFS(g,g[cur][i],cur,depth+1);
	}
	int Find(int a,int b){
		if(ds[a]>ds[b])
			swap(a,b);
		rep(i,ps.size())
			if(ds[b]-ds[a]&1<<i)
				b=ps[i][b];
		if(a==b)
			return a;
		per(i,ps.size())
			if(ps[i][a]!=ps[i][b]){
				a=ps[i][a];
				b=ps[i][b];
			}
		return ps[0][a];
	}
};
