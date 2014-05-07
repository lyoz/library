typedef complex<double> Point;

namespace std
{
	bool operator<(const Point& lhs,const Point& rhs)
	{
		if(real(lhs)==real(rhs))
			return imag(lhs)<imag(rhs);
		else
			return real(lhs)<real(rhs);
	}
}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
};
typedef Line Segment;

struct Circle{
	Point center;
	double radius;
	Circle(){}
	Circle(Point center,double radius):center(center),radius(radius){}
};
