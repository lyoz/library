// Verify: AOJ 2402

bool InterLS(Line l,Segment s)
{
	Point a=l.pos,b=l.pos+l.dir;
	Point c=s.pos,d=s.pos+s.dir;
	return CCW(a,b,c)*CCW(a,b,d)<0;
}
bool InterSS(Segment a,Segment b)
{
	return InterLS(a,b) && InterLS(b,a);
}
