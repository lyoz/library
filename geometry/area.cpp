double Area(const vector<Point>& ps){
	double res=0;
	repi(i,2,ps.size())
		res+=Cross(ps[i-1]-ps[0],ps[i]-ps[0])/2;
	return res;
}
