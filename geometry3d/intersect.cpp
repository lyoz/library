pair<Point,Point> InterPointSL(Sphere s,Line l){
	Point p=l.pos-s.center,d=l.dir;
	double a=Abs2(d),b=Dot(p,d),c=Abs2(p)-pow(s.radius,2);
	double t1=(-b-sqrt(b*b-a*c))/a;
	double t2=(-b+sqrt(b*b-a*c))/a;
	return mp(Point(l.pos+l.dir*t1),Point(l.pos+l.dir*t2));
}
