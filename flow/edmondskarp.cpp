// Verify: PKU 1273, PKU 1459(1844ms)

int EdmondsKarp(const Graph& _g,int begin,int end)
{
	int size=_g.size();
	
	// 逆方向の辺を加える(容量は0にする)
	Graph g=_g;
	rep(i,size)
		foreach(e,_g[i])
			g[e->dst].push_back(Edge(e->dst,e->src,0));
	
	vvi capacity(size,vi(size)),flow(size,vi(size));
	rep(i,size)
		foreach(e,g[i])
			capacity[e->src][e->dst]+=e->weight;
	
	for(;;){
		vi visited(size),prev(size,-1);
		visited[begin]=true;
		queue<int> q;
		q.push(begin);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(now==end)
				break;
			foreach(e,g[now]){
				if(visited[e->dst] || capacity[now][e->dst]-flow[now][e->dst]==0)
					continue;
				visited[e->dst]=true;
				prev[e->dst]=now;
				q.push(e->dst);
			}
		}
		if(!visited[end])
			break;
		
		vi path;
		for(int i=end;i!=-1;i=prev[i])
			path.push_back(i);
		reverse(all(path));
		
		int f=INT_MAX;
		rep(i,path.size()-1)
			f=min(f,capacity[path[i]][path[i+1]]-flow[path[i]][path[i+1]]);
		rep(i,path.size()-1){
			flow[path[i]][path[i+1]]+=f;
			flow[path[i+1]][path[i]]-=f;
		}
	}
	
	int res=0;
	rep(i,size)
		res+=flow[begin][i];
	return res;
}
