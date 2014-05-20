// 連続する3点が同一直線上にある場合はfalseを返す
bool IsConvex(const vector<Point>& ps){
	int n=ps.size(),res=true;
	rep(i,n) res&=CCW(ps[i],ps[(i+1)%n],ps[(i+2)%n])==1;
	return res;
}

// 同一直線上の点はとらない．
// もしとりたければ，while(n>=2 && CCW(cs[n-2],cs[n-1],ps[i])<=0)と書き換える．
vector<Point> ConvexHull(vector<Point> ps){
	if(ps.size()==1) return ps;
	sort(all(ps),LessX());
	vector<Point> res;
	rep(_,2){
		int n=0;
		vector<Point> half(ps.size());
		rep(i,ps.size()){
			while(n>=2 && CCW(half[n-2],half[n-1],ps[i])!=1)
				n--;
			half[n++]=ps[i];
		}
		res.insert(res.end(),half.begin(),half.begin()+n-1);
		reverse(all(ps));
	}
	return res;
}
