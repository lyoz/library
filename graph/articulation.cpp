// Verify: POJ 1144

int DFS(const Graph& g,int u,int prev,int x,vi& ord,vi& low,vi& as)
{
	ord[u]=low[u]=x++;
	int deg=0,isart=0;
	rep(i,g[u].size()){
		int v=g[u][i].dst;
		if(ord[v]==-1){
			x=DFS(g,v,u,x,ord,low,as);
			low[u]=min(low[u],low[v]);
			deg++;
			isart|=ord[u]<=low[v];
		}
		else if(v!=prev)
			low[u]=min(low[u],ord[v]);
	}
	if(prev==-1 && deg>=2 || prev!=-1 && isart)
		as.push_back(u);
	return x;
}

void Articulation(const Graph& g,vi& as)
{
	as.clear();
	int n=g.size();
	vi ord(n,-1),low(n);
	rep(i,n) if(ord[i]==-1)
		DFS(g,i,-1,i,ord,low,as);
}
