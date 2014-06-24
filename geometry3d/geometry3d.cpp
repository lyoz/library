struct Point{
	double x,y,z;
	Point(){}
	Point(double x,double y,double z):x(x),y(y),z(z){}
	Point& operator+=(Point p){x+=p.x,y+=p.y,z+=p.z; return *this;}
	Point& operator-=(Point p){x-=p.x,y-=p.y,z-=p.z; return *this;}
	Point& operator*=(double c){x*=c,y*=c,z*=c; return *this;}
	Point& operator/=(double c){x/=c,y/=c,z/=c; return *this;}
};
Point operator+(Point a,Point b){return a+=b;}
Point operator-(Point a,Point b){return a-=b;}
Point operator*(Point a,double c){return a*=c;}
Point operator*(double c,Point a){return a*=c;}
Point operator/(Point a,double c){return a/=c;}

double Abs(Point p){
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
double Abs2(Point p){
	return p.x*p.x+p.y*p.y+p.z*p.z;
}
double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(double x,double y,double z,double u,double v,double w):pos(x,y,z),dir(u,v,w){}
};

struct Segment{
	Point pos,dir;
	Segment(){}
	Segment(Point p,Point d):pos(p),dir(d){}
	Segment(double x,double y,double z,double u,double v,double w):pos(x,y,z),dir(u,v,w){}
	explicit Segment(Line l):pos(l.pos),dir(l.dir){}
	explicit operator Line()const{return Line(pos,dir);}
};

struct Sphere{
	Point center;
	double radius;
	Sphere(){}
	Sphere(Point c,double r):center(c),radius(r){}
	Sphere(double x,double y,double z,double r):center(x,y,z),radius(r){}
};
