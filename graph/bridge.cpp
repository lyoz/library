// Verify: LOJ 1026

int DFS(const Graph& g,int u,int prev,int x,vi& ord,vi& low)
{
	ord[u]=low[u]=x++;
	rep(i,g[u].size()){
		int v=g[u][i].dst;
		if(ord[v]==-1){
			x=DFS(g,v,u,x,ord,low);
			low[u]=min(low[u],low[v]);
		}
		else if(v!=prev)
			low[u]=min(low[u],ord[v]);
	}
	return x;
}

void Bridge(const Graph& g,vector<Edge>& bs)
{
	bs.clear();
	int n=g.size();
	vi ord(n,-1),low(n);
	rep(i,n) if(ord[i]==-1)
		DFS(g,i,-1,0,ord,low);
	rep(i,n) foreach(e,g[i])
		if(ord[e->src]<low[e->dst])
			bs.push_back(*e);
}
