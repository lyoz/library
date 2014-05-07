// Verify: AOJ 2251

int MinPathCover(const Graph& g)
{
	int n=g.size();
	Graph bg(2*n);
	rep(i,n) foreach(e,g[i])
		bg[e->src].push_back(Edge(e->src,n+e->dst));
	vi side(2*n),match(2*n);
	fill(n+all(side),1);
	return n-HopcroftKarp(bg,side,match);
}
