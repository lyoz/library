// Verify: AOJ 0180, POJ 1287, POJ 1861

int Kruskal(const Graph& g,vector<Edge>& forest)
{
	forest.clear();
	
	vector<Edge> es;
	rep(i,g.size()) rep(j,g[i].size())
		es.push_back(g[i][j]);
	sort(all(es));
	
	UnionFind uf(g.size());
	int res=0;
	rep(i,es.size())
		if(uf.Find(es[i].src)!=uf.Find(es[i].dst)){
			uf.Unite(es[i].src,es[i].dst);
			res+=es[i].weight;
			forest.push_back(es[i]);
		}
	return res;
}
