## geometry.cpp
	省略

## ccw.cpp
+ int CCW(Point a,Point b,Point c)
	- AOJ 1183

## distance.cpp
+ double DistLP(Line l,Point p)
	- AOJ 2201
+ double DistSS(Segment a,Segment b)
	- AOJ 2402

## tangent.cpp
+ vector<Line> Intangent(Circle c1,Circle c2)
	- AOJ 2201
+ vector<Line> Extangent(Circle c1,Circle c2)
	- AOJ 2201

## convexhull.cpp
+ vector<Point> ConvexHull(vector<Point> ps)
	- POJ 2007, POJ 2187, AOJ 1298

## convexcut.cpp
+ vector<Point> ConvexCut(const vector<Point>& ps,Line l)
	- AOJ 1089, AOJ 1267, AOJ 1283, UVa 609, UVa 10117

## area.cpp
+ double Area(const vector<Point>& ps)
	- AOJ 1089, UVa 10117

## intersect.cpp
+ bool IntersectLL(Line a,Line b)
	- UVa 11068 (同一直線の場合について未検証)
+ bool IntersectLS(Line l,Segment s)
+ bool IntersectSS(Segment a,Segment b)
	- AOJ CGL_2_B, AOJ 1298, POJ 1127
+ bool IntersectSP(Segment s,Point p)
	- AOJ 1279
+ int IntersectCC(Circle c1,Circle c2)
	- AOJ 1047 (検証不十分)
+ Point InterPointLL(Line a,Line b)
	- UVa 11068 (同一直線の場合について未検証)
+ Point InterPointSS(Segment a,Segment b){
	- AOJ 1279
+ pair<Point,Point> InterPointCC(Circle c1,Circle c2)
	- AOJ 1066, AOJ 1047, AOJ 1183

## cover.cpp
+ bool CoverGG(const vector<Point>& ps,vector<Point>& qs)
	- AOJ 1298

## segmentarrangement.cpp
+ void SegmentArrangement(const vector<Segment>& ss,Graph& g,vector<Point>& ps)
	- AOJ 1279
