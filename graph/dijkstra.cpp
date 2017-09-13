// Verify: UVA 341, AOJ 0155

// dist(n,INF),prev(n,-1)で初期化しておくこと
void Dijkstra(const Graph& g,int src,vi& dist,vi& prev)
{
	priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
	pq.emplace(-1,src,0);
	while(pq.size()){
		Edge cur=pq.top(); pq.pop();
		if(dist[cur.dst]!=INF) continue;
		dist[cur.dst]=cur.weight;
		prev[cur.dst]=cur.src;
		for(Edge e:g[cur.dst])
			pq.emplace(e.src,e.dst,cur.weight+e.weight);
	}
}

void BuildPath(const vi& prev,int dst,vi& path)
{
	for(int v=dst;v!=-1;v=prev[v])
		path.push_back(v);
	reverse(all(path));
}
