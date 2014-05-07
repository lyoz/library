// 凸多角形psの内部に点pがあるときtrue(境界を含む)
// ps.size()==0のときtrue
// ps.size()==1のとき，ps[0]とpが一致していればtrue
// ps.size()==2のとき，ps[0],ps[1]上にpがあればtrue
bool CoverGP(const vector<Point>& ps,Point p){
	rep(i,ps.size()){
		int ccw=CCW(ps[i],ps[(i+1)%ps.size()],p);
		if(!(ccw==1 || ccw==0))
			return false;
	}
	return true;
}
// 凸多角形psが凸多角形qsを内部にもつときtrue(境界を含む)
// ps.size()==0またはqs.size()==0のときtrue
bool CoverGG(const vector<Point>& ps,vector<Point>& qs){
	rep(i,qs.size())
		if(!CoverGP(ps,qs[i]))
			return false;
	return true;
}
