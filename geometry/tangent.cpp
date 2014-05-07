vector<Line> Intangent(Circle c1,Circle c2)
{
	double r1=c1.radius,r2=c2.radius;
	double d=Abs(c1.center-c2.center);
	vector<Line> res;
	if(d>r1+r2+EPS){
		double t=acos((r1+r2)/d);
		rep(i,2){
			Point p1=c1.center+Rot(r1/d*(c2.center-c1.center),(i?1:-1)*t);
			Point p2=c2.center+Rot(r2/d*(c1.center-c2.center),(i?1:-1)*t);
			res.push_back(Line(p1,p2-p1));
		}
	}
	else if(d>r1+r2-EPS){
		Point p=c1.center+r1/d*(c2.center-c1.center);
		res.push_back(Line(p,Rot(p-c1.center,PI/2)));
	}
	return res;
}
vector<Line> Extangent(Circle c1,Circle c2)
{
	double r1=c1.radius,r2=c2.radius;
	double d=Abs(c1.center-c2.center);
	vector<Line> res;
	if(d>abs(r2-r1)+EPS){
		double t=acos((r1-r2)/d);
		rep(i,2){
			Point p1=c1.center+Rot(r1/d*(c2.center-c1.center),(i?1:-1)*t);
			Point p2=c2.center+Rot(r2/d*(c2.center-c1.center),(i?1:-1)*t);
			res.push_back(Line(p1,p2-p1));
		}
	}
	else if(d>abs(r2-r1)-EPS){
		Point p=c1.center+r1/d*(c2.center-c1.center);
		res.push_back(Line(p,Rot(p-c1.center,PI/2)));
	}
	return res;
}
