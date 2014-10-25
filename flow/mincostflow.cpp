// Verify: UVA 10594(int→ll,248ms), SRM 637 GreaterGame

struct Edge{
	int src,dst,cost,cap,flow;
	Edge(){}
	Edge(int s,int d,int co,int ca=0,int f=0):src(s),dst(d),cost(co),cap(ca),flow(f){}
};
struct Graph{
	vector<Edge> es;
	vi head,next;
	Graph(){}
	Graph(int n):head(n,-1){}
	// コスト:-co,容量:0の逆辺も追加する
	void AddEdge(int u,int v,int co,int ca){
		es.emplace_back(u,v,co,ca); next.push_back(head[u]); head[u]=es.size()-1;
		es.emplace_back(v,u,-co,0); next.push_back(head[v]); head[v]=es.size()-1;
	}
};

int MinCostFlow(Graph& g,int tap,int sink,int flow)
{
	int n=g.head.size();
	
	int res=0;
	vi pots(n);
	while(flow){
		vi cost(n,INF),prev(n,-1);
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		cost[tap]=0;
		pq.emplace(0,tap);
		while(pq.size()){
			int c,v; tie(c,v)=pq.top(); pq.pop();
			if(c>cost[v]) continue;
			for(int i=g.head[v];i!=-1;i=g.next[i]){
				Edge e=g.es[i];
				if(e.cap-e.flow==0) continue;
				if(cost[e.dst]>cost[e.src]+e.cost+pots[e.src]-pots[e.dst]){
					cost[e.dst]=cost[e.src]+e.cost+pots[e.src]-pots[e.dst];
					prev[e.dst]=i;
					pq.emplace(cost[e.dst],e.dst);
				}
			}
		}
		
		if(cost[sink]==INF) return -1;
		rep(i,n) pots[i]+=cost[i];
		
		int augment=flow;
		for(int v=sink;v!=tap;v=g.es[prev[v]].src){
			Edge e=g.es[prev[v]];
			augment=min(augment,e.cap-e.flow);
		}
		for(int v=sink;v!=tap;v=g.es[prev[v]].src){
			int i=prev[v];
			g.es[i].flow+=augment;
			g.es[i^1].flow-=augment;
		}
		flow-=augment;
		res+=augment*pots[sink];
	}
	
	return res;
}
