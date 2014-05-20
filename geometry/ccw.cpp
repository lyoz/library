int CCW(Point a,Point b,Point c){
	b-=a,c-=a;
	if(int sign=Signum(Cross(b,c)))
		return sign; // 1:ccw,-1:cw
	if(Dot(b,c)<-EPS)
		return -2;   // c-a-b
	if(Abs2(b)<Abs2(c)-EPS)
		return 2;    // a-b-c
	return 0;        // a-c-b (inclusive)
}
