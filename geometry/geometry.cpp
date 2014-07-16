const double PI=acos(-1);

int Signum(double x){
	return x<-EPS?-1:x>EPS?1:0;
}

struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point& operator+=(Point p){x+=p.x,y+=p.y; return *this;}
	Point& operator-=(Point p){x-=p.x,y-=p.y; return *this;}
	Point& operator*=(double c){x*=c,y*=c; return *this;}
	Point& operator/=(double c){x/=c,y/=c; return *this;}
};
Point operator+(Point a,Point b){return a+=b;}
Point operator-(Point a,Point b){return a-=b;}
Point operator*(Point a,double c){return a*=c;}
Point operator*(double c,Point a){return a*=c;}
Point operator/(Point a,double c){return a/=c;}
bool operator==(Point a,Point b){return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;}
bool operator!=(Point a,Point b){return !(a==b);}

double Abs(Point p){
	return sqrt(p.x*p.x+p.y*p.y);
}
double Abs2(Point p){
	return p.x*p.x+p.y*p.y;
}
double Arg(Point p){
	return atan2(p.y,p.x);
}
double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
double Cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
Point Rot(Point p,double t){
	return Point(cos(t)*p.x-sin(t)*p.y,sin(t)*p.x+cos(t)*p.y);
}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(double x,double y,double u,double v):pos(x,y),dir(u,v){}
};

bool Orthogonal(Line a,Line b){
	return abs(Dot(a.dir,b.dir))<EPS;
}
bool Parallel(Line a,Line b){
	return abs(Cross(a.dir,b.dir))<EPS;
}
Point Proj(Line l,Point p){
	Point a=p-l.pos,b=l.dir;
	return l.pos+Dot(a,b)/Abs2(b)*b;
}

struct Segment{
	Point pos,dir;
	Segment(){}
	Segment(Point p,Point d):pos(p),dir(d){}
	Segment(double x,double y,double u,double v):pos(x,y),dir(u,v){}
	explicit Segment(Line l):pos(l.pos),dir(l.dir){}
	explicit operator Line()const{return Line(pos,dir);}
};

struct Circle{
	Point center;
	double radius;
	Circle(){}
	Circle(Point c,double r):center(c),radius(r){}
	Circle(double x,double y,double r):center(x,y),radius(r){}
};
bool operator==(Circle a,Circle b){
	return a.center==b.center && abs(a.radius-b.radius)<EPS;
}
bool operator!=(Circle a,Circle b){
	return !(a==b);
}

// stream
ostream& operator<<(ostream& os,const Point& p){
	return os<<'('<<p.x<<','<<p.y<<')';
}
ostream& operator<<(ostream& os,const Line& l){
	return os<<'('<<l.pos<<','<<l.dir<<')';
}
ostream& operator<<(ostream& os,const Segment& s){
	return os<<'('<<s.pos<<','<<s.dir<<')';
}
ostream& operator<<(ostream& os,const Circle& c){
	return os<<'('<<c.center.x<<','<<c.center.y<<','<<c.radius<<')';
}

// comparer
struct LessX{
	bool operator()(Point a,Point b){
		return abs(a.x-b.x)>EPS?a.x<b.x-EPS:a.y<b.y-EPS;
	}
};
