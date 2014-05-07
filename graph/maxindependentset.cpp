// Verify: POJ 1419, SRM 589 Medium

void DFS(const Graph& g,int u,vi& vis,int cur,int rem,int& res)
{
	int n=g.size();
	if(cur+rem<=res) return;
	res=max(res,cur);
	if(u==n) return;

	if(vis[u]){
		DFS(g,u+1,vis,cur,rem,res);
		return;
	}

	// use u
	vi tmp=vis;
	vis[u]=1;
	rep(i,g[u].size()){
		int v=g[u][i].dst;
		if(!vis[v]) vis[v]=1,rem--;
	}
	DFS(g,u+1,vis,cur+1,rem-1,res);
	swap(vis,tmp);
	rep(i,g[u].size()){
		int v=g[u][i].dst;
		if(!vis[v]) rem++;
	}

	// don't use u
	if(g[u].size()>1){
		vis[u]=1;
		DFS(g,u+1,vis,cur,rem-1,res);
		vis[u]=0;
	}
}

int MaxIndependentSet(const Graph& g)
{
	int n=g.size();
	vi vis(n);
	int res=0;
	DFS(g,0,vis,0,n,res);
	return res;
}
