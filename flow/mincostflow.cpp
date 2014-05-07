// Verify: PKU 2135(297ms), PKU 2195(157ms), UVA 10594(int→ll,344ms),
//         SRM506Div1 Medium, SRM611 GoodCompanyDivOne

struct Edge{
	int src,dst,cap,cost;
	Edge(){}
	Edge(int s,int d,int ca,int co):src(s),dst(d),cap(ca),cost(co){}
};
typedef vector<vector<Edge> > Graph;

int MinCostFlow(const Graph& _g,int begin,int end,int flow)
{
	int size=_g.size();
	Graph g(size);
	vvi rev(size);
	rep(i,size) foreach(e,_g[i]){
		g[i].push_back(*e);
		g[e->dst].push_back(Edge(e->dst,e->src,0,-e->cost));
		rev[i].push_back(g[e->dst].size()-1);
		rev[e->dst].push_back(g[i].size()-1);
	}
	
	int res=0;
	vi pots(size);
	while(flow){
		vi dist(size,INFTY);
		vector<pii> prev(size,mp(-1,-1));
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		pq.push(mp(0,begin));
		dist[begin]=0;
		while(!pq.empty()){
			int curd=pq.top().first,curv=pq.top().second; pq.pop();
			if(dist[curv]<curd)
				continue;
			rep(i,g[curv].size()){
				Edge e=g[curv][i];
				if(e.cap==0)
					continue;
				int newdist=dist[e.src]+e.cost+pots[e.src]-pots[e.dst];
				if(dist[e.dst]>newdist){
					dist[e.dst]=newdist;
					prev[e.dst]=mp(e.src,i);
					pq.push(mp(newdist,e.dst));
				}
			}
		}
		
		if(prev[end].first==-1)
			return -1;
		rep(i,size)
			pots[i]+=dist[i];
		
		int f=flow;
		for(int v=end;v!=begin;v=prev[v].first){
			Edge e=g[prev[v].first][prev[v].second];
			f=min(f,e.cap);
		}
		for(int v=end;v!=begin;v=prev[v].first){
			int i=prev[v].first,j=prev[v].second;
			g[i][j].cap-=f;
			g[g[i][j].dst][rev[i][j]].cap+=f;
		}
		flow-=f;
		res+=f*pots[end];
	}
	
	return res;
}
