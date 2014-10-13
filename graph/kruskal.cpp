// Verify: AOJ 0180, POJ 1861

int Kruskal(const Graph& g,vector<Edge>& forest)
{
	int n=g.size();
	vector<Edge> es;
	rep(i,n) es.insert(end(es),all(g[i]));
	sort(all(es));
	
	UnionFind uf(n);
	int res=0;
	for(auto e:es)
		if(uf.Unite(e.src,e.dst)){
			res+=e.weight;
			forest.push_back(e);
		}
	return res;
}
