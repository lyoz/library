vector<Point> ConvexCut(const vector<Point>& ps,Line l){
	int n=ps.size();
	vector<Point> res;
	rep(i,n){
		int c1=CCW(l.pos,l.pos+l.dir,ps[i]);
		int c2=CCW(l.pos,l.pos+l.dir,ps[(i+1)%n]);
		if(c1!=-1)
			res.push_back(ps[i]);
		if(c1*c2==-1)
			res.push_back(InterPointLS(l,Segment(ps[i],ps[(i+1)%n]-ps[i])));
	}
	return res;
}
