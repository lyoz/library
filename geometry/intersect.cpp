bool IntersectLL(Line a,Line b){
	return abs(Cross(a.dir,b.dir))>EPS || abs(Cross(a.dir,b.pos-a.pos))<EPS;
}
bool IntersectLS(Line l,Segment s){
	Point a=s.pos-l.pos,b=s.pos+s.dir-l.pos;
	return Signum(Cross(l.dir,a))*Signum(Cross(l.dir,b))<=0;
}
bool IntersectSS(Segment a,Segment b){
	int c1=CCW(a.pos,a.pos+a.dir,b.pos),c2=CCW(a.pos,a.pos+a.dir,b.pos+b.dir);
	int c3=CCW(b.pos,b.pos+b.dir,a.pos),c4=CCW(b.pos,b.pos+b.dir,a.pos+a.dir);
	return c1*c2<=0 && c3*c4<=0;
}
bool IntersectSP(Segment s,Point p){
	return CCW(s.pos,s.pos+s.dir,p)==0;
}
// 交点の個数を返す
int IntersectCC(Circle c1,Circle c2){
	if(c1==c2)
		return INFTY;
	double r1=c1.radius,r2=c2.radius,d=Abs(c1.center-c2.center);
	if(d>r1+r2+EPS || d<abs(r1-r2)-EPS)
		return 0;
	if(abs(d-(r1+r2))<EPS || abs(d-abs(r1-r2))<EPS)
		return 1;
	return 2;
}

// aとbは必ず交差していること
Point InterPointLL(Line a,Line b){
	if(abs(Cross(a.dir,b.dir))<EPS)
		return a.pos;
	return a.pos+Cross(b.pos-a.pos,b.dir)/Cross(a.dir,b.dir)*a.dir;
}
Point InterPointLS(Line l,Segment s){
	return InterPointLL(s,l);
}
Point InterPointSS(Segment a,Segment b){
	if(abs(Cross(a.dir,b.dir))<EPS){
		if(IntersectSP(b,a.pos)) return a.pos;
		if(IntersectSP(b,a.pos+a.dir)) return a.pos+a.dir;
		if(IntersectSP(a,b.pos)) return b.pos;
		if(IntersectSP(a,b.pos+b.dir)) return b.pos+b.dir;
	}
	return InterPointLL(a,b);
}

// c1とc2は必ず2点で交わること
pair<Point,Point> InterPointCC(Circle c1,Circle c2){
	Point p1=c1.center,p2=c2.center;
	double r1=c1.radius,r2=c2.radius;
	double d=Abs(p1-p2);
	double a=(d*d+r1*r1-r2*r2)/(2*d);
	double s=sqrt(r1*r1-a*a);
	return mp(p1+a/d*(p2-p1)+s*Rot((p2-p1)/d,PI/2),
			  p1+a/d*(p2-p1)-s*Rot((p2-p1)/d,PI/2));
}
