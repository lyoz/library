// Verify: SRM618 Family

bool DFS(const Graph& g,int u,int c,vi& color){
	if(color[u]!=-1)
		return color[u]==c;
	color[u]=c;
	rep(i,g[u].size())
		if(!DFS(g,g[u][i].dst,!c,color))
			return false;
	return true;
}

bool IsBipartite(const Graph& g){
	int n=g.size();
	vi color(n,-1);
	rep(i,n) if(color[i]==-1)
		if(!DFS(g,i,0,color))
			return false;
	return true;
}
