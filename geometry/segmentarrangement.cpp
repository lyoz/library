// オーバーラップする線分は取り除いておくこと．
struct Edge{
	int src,dst;
	double weight;
	Edge(){}
	Edge(int s,int d,double w):src(s),dst(d),weight(w){}
	bool operator<(const Edge& e)const{return Signum(weight-e.weight)<0;}
	bool operator>(const Edge& e)const{return Signum(weight-e.weight)>0;}
};
void SegmentArrangement(const vector<Segment>& ss,Graph& g,vector<Point>& ps){
	rep(i,ss.size()){
		ps.push_back(ss[i].pos);
		ps.push_back(ss[i].pos+ss[i].dir);
		repi(j,i+1,ss.size()) if(IntersectSS(ss[i],ss[j]))
			ps.push_back(InterPointSS(ss[i],ss[j]));
	}
	sort(all(ps),LessX());
	ps.erase(unique(all(ps)),ps.end());
	
	g.resize(ps.size());
	rep(i,ss.size()){
		vector<pair<double,int> > ds;
		rep(j,ps.size()) if(IntersectSP(ss[i],ps[j]))
			ds.push_back(mp(Abs(ps[j]-ss[i].pos),j));
		sort(all(ds));
		rep(j,ds.size()-1){
			int u=ds[j].second,v=ds[j+1].second;
			double w=ds[j+1].first-ds[j].first;
			g[u].push_back(Edge(u,v,w));
			g[v].push_back(Edge(v,u,w));
		}
	}
}
