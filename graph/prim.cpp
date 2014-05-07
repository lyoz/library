// Verify: AOJ 0180, POJ 1287, POJ 1861

int Prim(const Graph& g,vector<Edge>& tree,int root=0)
{
	tree.clear();
	
	vi vis(g.size());
	priority_queue<Edge,vector<Edge>,greater<Edge> > pq;
	pq.push(Edge(-1,root,0));
	int res=0;
	while(pq.size()){
		Edge cur=pq.top(); pq.pop();
		if(vis[cur.dst])
			continue;
		vis[cur.dst]=true;
		res+=cur.weight;
		if(cur.src!=-1)
			tree.push_back(cur);
		foreach(e,g[cur.dst])
			pq.push(*e);
	}
	return res;
}
