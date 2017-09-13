// Verify: ABC061 Problem D

// dist(n,INF),prev(n,-1)で初期化しておくこと
bool BellmanFord(const Graph& g,int src,vi& dist,vi& prev)
{
	int n=g.size();
	dist[src]=0;
	rep(k,n-1)
		rep(u,n) for(auto e:g[u])
			if(dist[e.dst]>dist[e.src]+e.weight){
				dist[e.dst]=dist[e.src]+e.weight;
				prev[e.dst]=u;
			}
	rep(u,n) for(auto e:g[u])
		if(dist[e.dst]>dist[e.src]+e.weight)
			return false;
	return true;
}

void BuildPath(const vi& prev,int dst,vi& path)
{
	for(int v=dst;v!=-1;v=prev[v])
		path.push_back(v);
	reverse(all(path));
}
