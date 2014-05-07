// headはvector<int>(頂点数,-1)で初期化されていること．
// 典型的な問題では，グラフの各辺について
//   AddEdge(es,head,src,dst,0,cap);
//   AddEdge(es,head,src,dst,0,0);
// と書く．
// Verify: POJ 1459(141ms), POJ 3498(2625ms), SPOJ 4110(int->ll,2.81s), AOJ 2076(0.025s)
//         UVa 10249(0.588s), COJ 1644(421ms)

struct Edge{
	int src,dst,flow,capacity,next;
	Edge(){}
	Edge(int s,int d,int f,int c,int n):src(s),dst(d),flow(f),capacity(c),next(n){}
};

void AddEdge(vector<Edge>& es,vi& head,int src,int dst,int flow,int capacity)
{
	es.push_back(Edge(src,dst,flow,capacity,head[src]));
	head[src]=es.size()-1;
}

vi BFS(const vector<Edge>& es,const vi& head,int begin)
{
	int size=head.size();
	vi label(size,size);
	queue<pii> q;
	q.push(mp(begin,0));
	while(q.size()){
		pii cur=q.front(); q.pop();
		if(label[cur.first]<=cur.second)
			continue;
		label[cur.first]=cur.second;
		for(int i=head[cur.first];i!=-1;i=es[i].next)
			if(es[i].capacity-es[i].flow>0)
				q.push(mp(es[i].dst,cur.second+1));
	}
	return label;
}

int DFS(vector<Edge>& es,vi& head,int v,int end,const vi& label,int f)
{
	if(v==end)
		return f;
	for(int& i=head[v];i!=-1;i=es[i].next){
		Edge& e=es[i];
		if(label[e.src]>=label[e.dst])
			continue;
		int residue=e.capacity-e.flow;
		if(residue<=0)
			continue;
		int augment=DFS(es,head,e.dst,end,label,min(residue,f));
		if(augment>0){
			e.flow+=augment;
			es[i^1].flow-=augment;
			return augment;
		}
	}
	return 0;
}

int Dinic(vector<Edge>& es,const vi& head,int begin,int end)
{
	int size=head.size();
	for(;;){
		vi label=BFS(es,head,begin);
		if(label[end]==size)
			break;
		vi temp=head;
		while(DFS(es,temp,begin,end,label,INFTY))
			;
	}
	int res=0;
	for(int i=head[begin];i!=-1;i=es[i].next)
		res+=es[i].flow;
	return res;
}
