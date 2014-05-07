// Verify: UVA 341

bool BellmanFord(const Graph& g,int begin,vi& cost,vi& prev)
{
	int size=g.size();
	cost.assign(size,INFTY);
	prev.assign(size,-1);
	
	cost[begin]=0;
	rep(k,size-1){
		rep(i,size){
			rep(j,g[i].size()){
				Edge cand=g[i][j]; // candidate
				if(cost[cand.dst]>cost[i]+cand.weight){
					cost[cand.dst]=cost[i]+cand.weight;
					prev[cand.dst]=cand.src;
				}
			}
		}
	}
	rep(i,size){
		rep(j,g[i].size()){
			Edge cand=g[i][j]; // candidate
			if(cost[cand.dst]>cost[j]+cand.weight)
				return false;
		}
	}
	return true;
}

void BuildPath(const vi& prev,int begin,int end,vi& path)
{
	path.clear();
	for(int i=end;;i=prev[i]){
		path.push_back(i);
		if(i==begin)
			break;
	}
	reverse(all(path));
}
