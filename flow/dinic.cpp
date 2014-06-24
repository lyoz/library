// Verify: AOJ 2076(0.19s), SPOJ 4110(int->ll,2.84s), UVa 10249(0.352s)

struct Edge{
	int src,dst,cap,flow;
	Edge(){}
	Edge(int s,int d,int c,int f=0):src(s),dst(d),cap(c),flow(f){}
};
struct Graph{
	vector<Edge> es;
	vi head,next;
	Graph(){}
	Graph(int n):head(n,-1){}
	// 有向辺を追加するとき逆辺の容量c2は普通0である．
	// 両方向に容量があるならc2も指定する．
	void AddEdge(int u,int v,int c1,int c2=0){
		es.emplace_back(u,v,c1); next.push_back(head[u]); head[u]=es.size()-1;
		es.emplace_back(v,u,c2); next.push_back(head[v]); head[v]=es.size()-1;
	}
};

void BFS(const Graph& g,int tap,vi& layer)
{
	queue<pii> q; q.emplace(tap,0);
	while(q.size()){
		int u,d; tie(u,d)=q.front(); q.pop();
		if(layer[u]!=INF) continue;
		layer[u]=d;
		for(int i=g.head[u];i!=-1;i=g.next[i])
			if(g.es[i].cap-g.es[i].flow>0)
				q.emplace(g.es[i].dst,d+1);
	}
}

int DFS(Graph& g,int v,int sink,const vi& layer,int flow)
{
	if(v==sink) return flow;
	int f=flow;
	for(int& i=g.head[v];i!=-1;i=g.next[i]){
		Edge& e=g.es[i];
		if(layer[e.src]>=layer[e.dst]) continue;
		int residue=e.cap-e.flow;
		if(residue==0) continue;
		int augment=DFS(g,e.dst,sink,layer,min(residue,f));
		e.flow+=augment;
		g.es[i^1].flow-=augment;
		f-=augment;
		if(f==0) break;
	}
	return flow-f;
}

int Dinic(Graph& g,int tap,int sink)
{
	int res=0;
	for(int n=g.head.size();;){
		vi layer(n,INF);
		BFS(g,tap,layer);
		if(layer[sink]==INF) break;
		vi temp=g.head;
		res+=DFS(g,tap,sink,layer,INF);
		swap(g.head,temp);
	}
	return res;
}
