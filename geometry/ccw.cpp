int CCW(Point a,Point b,Point c){
	Point d1=b-a,d2=c-a;
	if(int sign=Signum(Cross(d1,d2)))
		return sign;	// 1:ccw,-1:cw
	if(Dot(d1,d2)<-EPS)
		return -2;		// c-a-b
	if(Abs2(d1)<Abs2(d2)-EPS)
		return 2;		// a-b-c
	return 0;			// a-c-b
}
