// 同一直線上の点はとらない．
// もしとりたければ，if(CCW(cs[j-2],cs[j-1],ps[i])<=0)と書き換える．
// Verify: POJ 2007, POJ 2187

struct LessX{
	bool operator()(const Point& a,const Point& b){
		return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
	}
};

vector<Point> ConvexHull(const vector<Point>& _ps)
{
	vector<Point> ps=_ps;
	sort(all(ps),LessX());
	vector<Point> cs(ps.size()+1);
	int j=0;
	rep(i,ps.size()){
		while(j>=2 && CCW(cs[j-2],cs[j-1],ps[i])!=1)
			j--;
		cs[j++]=ps[i];
	}
	int k=j;
	per(i,ps.size()-1){
		while(j>=k+1 && CCW(cs[j-2],cs[j-1],ps[i])!=1)
			j--;
		cs[j++]=ps[i];
	}
	cs.resize(j-1);
	return cs;
}
