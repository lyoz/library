// Verify: AOJ GRL_5_A, LOJ 1094

pii DFS(const Graph& g,int p,int v)
{
	pii res(0,v);
	for(Edge e:g[v]) if(e.dst!=p){
		pii t=DFS(g,e.src,e.dst);
		t.first+=e.weight;
		if(res.first<t.first) res=t;
	}
	return res;
}

int Diameter(const Graph& g)
{
	int u,v,w;
	tie(w,u)=DFS(g,-1,0);
	tie(w,v)=DFS(g,-1,u);
	return w;
}
