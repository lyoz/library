// Verify: Cf#770 Problem E

using Edge=tuple<int,int,int>; // u,v,rev

void dfs(vector<vector<Edge>>& g,int u,vector<Edge>& order)
{
	while(g[u].size()){
		auto [_,v,rev]=g[u].back();
		g[u].pop_back();
		if(rev>=g[v].size())
			continue;
		dfs(g,v,order);
		order.emplace_back(u,v,rev);
	}
}

// 無向グラフ用の実装。各連結成分に対するオイラー路を返す
// 辺(u,v)を追加するときに以下のようにすること
// g[u].emplace_back(u,v,g[v].size());
// g[v].emplace_back(v,u,g[u].size()-1);
vector<vector<Edge>> EulerianTrails(const vector<vector<Edge>>& g)
{
	vector<vector<Edge>> g2=g;
	vector<vector<Edge>> orders;
	rep(u,g2.size())
		if(g2[u].size()){
			vector<Edge> order;
			dfs(g2,u,order);
			reverse(all(order));
			orders.push_back(order);
		}
	return orders;
}
