// Verify: POJ 2186, AOJ 2505

void DFS(const Graph& g,int v,vi& vis,vi& order)
{
	if(vis[v]) return;
	vis[v]=1;
	foreach(e,g[v])
		DFS(g,e->dst,vis,order);
	order.push_back(v);
}

vvi SCC(const Graph& g)
{
	int n=g.size();
	vi vis(n),order;
	rep(i,n) DFS(g,i,vis,order);
	Graph t(n);
	rep(i,n) foreach(e,g[i])
		t[e->dst].push_back(Edge(e->dst,e->src));
	fill(all(vis),0);
	vvi res;
	per(i,n) if(!vis[order[i]]){
		res.resize(res.size()+1);
		DFS(t,order[i],vis,res.back());
	}
	return res;
}
