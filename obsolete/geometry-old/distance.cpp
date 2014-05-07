// Verify: AOJ 2402

double DistLP(Line l,Point p)
{
	return abs(Proj(l,p)-p);
}

double DistSP(Segment s,Point p)
{
	int ccw=CCW(s.pos,s.pos+s.dir,Proj(s,p));
	if(ccw==-2)
		return abs(p-s.pos);
	if(ccw==2)
		return abs(p-(s.pos+s.dir));
	return DistLP(s,p);
}

double DistSS(Segment a,Segment b)
{
	if(InterSS(a,b)) return 0;
	double d1=min(DistSP(a,b.pos),DistSP(a,b.pos+b.dir));
	double d2=min(DistSP(b,a.pos),DistSP(b,a.pos+a.dir));
	return min(d1,d2);
}
