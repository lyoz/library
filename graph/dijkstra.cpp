// Verify: UVA 341

void Dijkstra(const Graph& g,int begin,vi& cost,vi& prev)
{
	int size=g.size();
	cost.assign(size,INFTY);
	prev.assign(size,-1);
	priority_queue<Edge,vector<Edge>,greater<Edge> > pq;
	pq.push(Edge(-1,begin,0));
	while(!pq.empty()){
		Edge cur=pq.top(); pq.pop();
		if(cost[cur.dst]!=INFTY)
			continue;
		cost[cur.dst]=cur.weight;
		prev[cur.dst]=cur.src;
		foreach(e,g[cur.dst])
			pq.push(Edge(e->src,e->dst,e->weight+cur.weight));
	}
}

void BuildPath(const vi& prev,int begin,int end,vi& path)
{
	path.clear();
	for(int i=end;;i=prev[i]){
		path.push_back(i);
		if(i==begin)
			break;
	}
	reverse(all(path));
}
