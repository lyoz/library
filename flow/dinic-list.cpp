// Verify: POJ 1273, POJ 1459(344ms), SPOJ 4110(int->ll,4.60s)

const int INFTY=1<<29;

struct Edge{
	int src,dst,flow,capacity;
	Edge(){}
	Edge(int s,int d,int f,int c):src(s),dst(d),flow(f),capacity(c){}
};
typedef vector<vector<Edge> > Graph;

vi BFS(const Graph& g,int begin)
{
	int size=g.size();
	vi label(size,size);
	queue<pii> q;
	q.push(mp(begin,0));
	while(q.size()){
		pii cur=q.front(); q.pop();
		if(label[cur.first]<=cur.second)
			continue;
		label[cur.first]=cur.second;
		foreach(e,g[cur.first])
			if(e->capacity-e->flow>0)
				q.push(mp(e->dst,cur.second+1));
	}
	return label;
}

int DFS(Graph& g,const vvi& rev,vi& now,int v,int end,const vi& label,int f)
{
	if(v==end)
		return f;
	
	for(int& i=now[v];i<g[v].size();i++){
		Edge& e=g[v][i];
		if(label[e.src]>=label[e.dst])
			continue;
		int residue=e.capacity-e.flow;
		if(residue<=0)
			continue;
		int augment=DFS(g,rev,now,e.dst,end,label,min(f,residue));
		if(augment>0){
			e.flow+=augment;
			g[e.dst][rev[v][i]].flow-=augment;
			return augment;
		}
	}
	
	return 0;
}

int Dinic(const Graph& _g,int begin,int end)
{
	int size=_g.size();
	Graph g(size);
	vvi rev(size);
	rep(i,size) foreach(e,_g[i]){
		g[e->src].push_back(Edge(e->src,e->dst,0,e->capacity));
		g[e->dst].push_back(Edge(e->dst,e->src,0,0));
		rev[e->src].push_back(rev[e->dst].size());
		rev[e->dst].push_back(rev[e->src].size()-1);
	}
	
	for(;;){
		vi label=BFS(g,begin);
		if(label[end]==size)
			break;
		vi now(size);
		while(DFS(g,rev,now,begin,end,label,INFTY))
			;
	}
	
	int res=0;
	foreach(e,g[begin])
		res+=e->flow;
	return res;
}
