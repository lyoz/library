// Verify: AOJ 1163, LOJ 1149

struct Edge{
	int src,dst;
	Edge(){}
	Edge(int s,int d):src(s),dst(d){}
};
typedef vector<vector<Edge> > Graph;

bool Augment(const Graph& g,int u,vi& vis,vi& match)
{
	rep(i,g[u].size()){
		int v=g[u][i].dst;
		if(vis[v]) continue;
		vis[v]=1;
		if(match[v]==-1 || Augment(g,match[v],vis,match)){
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;
}

int BipartiteMatching(const Graph& g,vi& match)
{
	int n=g.size();
	match.assign(n,-1);
	int res=0;
	rep(i,n) if(match[i]==-1){
		vi vis(n);
		res+=Augment(g,i,vis,match);
	}
	return res;
}
