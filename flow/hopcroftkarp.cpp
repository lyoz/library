// Verify: AOJ 1163, LOJ 1171, LOJ 1356, POJ 1466, POJ 2446, SPOJ 4206 (2.31s)

struct Edge{
	int src,dst;
	Edge(){}
	Edge(int s,int d):src(s),dst(d){}
};
typedef vector<vector<Edge> > Graph;

bool BFS(const Graph& g,const vi& side,const vi& match,vi& level)
{
	int n=g.size();
	level.assign(n,n);
	queue<pii> q;
	rep(i,n) if(side[i]==0 && match[i]==-1)
		q.push(mp(i,0));
	bool res=false;
	while(!q.empty()){
		pii cur=q.front(); q.pop();
		int u=cur.first,l=cur.second;
		if(level[u]<=l) continue;
		level[u]=l;
		rep(i,g[u].size()){
			int v=g[u][i].dst;
			if(match[v]==-1)
				res=true;
			else
				q.push(mp(match[v],l+2));
		}
	}
	return res;
}

bool DFS(const Graph& g,const vi& side,int u,vi& match,vi& level)
{
	rep(i,g[u].size()){
		int v=g[u][i].dst;
		if(match[v]==-1 || level[match[v]]>level[u] && DFS(g,side,match[v],match,level)){
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	level[u]=-1;
	return false;
}

int HopcroftKarp(const Graph& g,const vi& side,vi& match)
{
	int n=g.size();
	match.assign(n,-1);
	int res=0;
	for(vi level;BFS(g,side,match,level);)
		rep(i,n) if(side[i]==0 && match[i]==-1)
			res+=DFS(g,side,i,match,level);
	return res;
}
