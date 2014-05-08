// Verify: UVA 341, AOJ 0155

void Dijkstra(const Graph& g,int v,vi& dist,vi& prev)
{
	priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
	pq.emplace(-1,v,0);
	while(pq.size()){
		Edge cur=pq.top(); pq.pop();
		if(dist[cur.dst]!=INF) continue;
		dist[cur.dst]=cur.weight;
		prev[cur.dst]=cur.src;
		for(Edge e:g[cur.dst])
			pq.emplace(e.src,e.dst,cur.weight+e.weight);
	}
}

void BuildPath(const vi& prev,int v,vi& path)
{
	for(int u=v;u!=-1;u=prev[u])
		path.push_back(u);
	reverse(all(path));
}
