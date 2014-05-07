// Verify: POJ 1273, POJ 1459(344ms)

void BFS(const Graph& g,int begin,int end,const vvi& capacity,const vvi& flow,vi& label)
{
	queue<pii> q;
	q.push(mp(begin,0));
	while(!q.empty()){
		pii v=q.front(); q.pop();
		if(label[v.first]<=v.second)
			continue;
		label[v.first]=v.second;
		foreach(e,g[v.first])
			if(capacity[e->src][e->dst]-flow[e->src][e->dst]>0)
				q.push(mp(e->dst,v.second+1));
	}
}

int DFS(const Graph& g,int v,int end,const vvi& capacity,vvi& flow,
		vi& label,vi& finished,int f)
{
	if(v==end)
		return f;
	if(finished[v])
		return 0;
	finished[v]=true;
	
	foreach(e,g[v]){
		if(label[e->src]>=label[e->dst])
			continue;
		int r=capacity[e->src][e->dst]-flow[e->src][e->dst];
		if(r<=0)
			continue;
		int inc=DFS(g,e->dst,end,capacity,flow,label,finished,min(f,r));
		if(inc>0){
			flow[e->src][e->dst]+=inc;
			flow[e->dst][e->src]-=inc;
			finished[v]=false;
			return inc;
		}
	}
	
	return 0;
}

int Dinic(const Graph& _g,int begin,int end)
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
		vi label(size,INFTY);
		BFS(g,begin,end,capacity,flow,label);
		if(label[end]==INFTY)
			break;
		vi finished(size);
		while(DFS(g,begin,end,capacity,flow,label,finished,INFTY))
			;
	}
	
	return accumulate(all(flow[begin]),0);
}
