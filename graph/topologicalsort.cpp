// Verify: UVA 10305

bool Visit(const Graph& g,int v,vi& color,vi& order)
{
	if(color[v]==1)
		return false;
	if(color[v]==2)
		return true;
	color[v]=1;
	rep(i,g[v].size())
		if(!Visit(g,g[v][i].dst,color,order))
			return false;
	color[v]=2;
	order.push_back(v);
	return true;
}

bool TopologicalSort(const Graph& g,vi& order)
{
	int size=g.size();
	order.clear();
	vi colors(size);
	rep(i,size){
		if(!Visit(g,i,colors,order)){
			order.clear();
			return false;
		}
	}
	reverse(all(order));
	return true;
}
