// Verify: AOJ 2402

Point Proj(Line l,Point p)
{
	Point a=p-l.pos,b=l.dir;
	return Dot(a,b)/norm(b)*b+l.pos;
}
