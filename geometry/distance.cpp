double DistLP(Line l,Point p){
	return Abs(Proj(l,p)-p);
}
double DistSP(Segment s,Point p){
	int ccw=CCW(s.pos,s.pos+s.dir,Proj(s,p));
	if(ccw==-2) return Abs(p-s.pos);
	if(ccw== 2) return Abs(p-(s.pos+s.dir));
	return DistLP(s,p);
}
double DistLS(Line l,Segment s){
	if(IntersectLS(l,s)) return 0;
	return min(DistLP(l,s.pos),DistLP(l,s.pos+s.dir));
}
double DistSS(Segment a,Segment b){
	if(IntersectSS(a,b)) return 0;
	double d1=min(DistSP(a,b.pos),DistSP(a,b.pos+b.dir));
	double d2=min(DistSP(b,a.pos),DistSP(b,a.pos+a.dir));
	return min(d1,d2);
}
