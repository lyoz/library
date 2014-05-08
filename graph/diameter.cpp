// Verify: AOJ GRL_5_A, LOJ 1094

pii DFS(const Graph& g,int u,int p)
{
	pii res(0,u);
	for(Edge e:g[u]) if(e.dst!=p){
		pii t=DFS(g,e.dst,e.src);
		t.first+=e.weight;
		if(res.first<t.first) res=t;
	}
	return res;
}

int Diameter(const Graph& g)
{
	int u,v,w;
	tie(w,u)=DFS(g,0,-1);
	tie(w,v)=DFS(g,u,-1);
	return w;
}
