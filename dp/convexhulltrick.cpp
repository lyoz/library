// Verify: Codeforces #185 Div1 Problem B

// クエリ1回あたりO(log n)
struct ConvexHullTrick{
	vl as,bs;
	// 傾きaは単調非増加でなければならない
	void AddLine(ll a,ll b){
		while(as.size()>=2){
			ll a1=as[as.size()-2],b1=bs[bs.size()-2];
			ll a2=as[as.size()-1],b2=bs[bs.size()-1];
			if((a1-a2)*(b1-b)<(a1-a)*(b1-b2)) break;
			as.pop_back(); bs.pop_back();
		}
		as.push_back(a); bs.push_back(b);
	}
	// 最小のax+bを返す
	ll Find(ll x){
		int lo=0,hi=as.size()-1;
		while(lo<hi){
			int mi=(lo+hi)/2;
			if(F(mi,x)<=F(mi+1,x))
				hi=mi;
			else
				lo=mi+1;
		}
		return F(lo,x);
	}
	ll F(int i,ll x){
		return as[i]*x+bs[i];
	}
};

// xが単調非減少に与えられるならこちらを使う
// クエリ1回あたりamortized O(1)
struct ConvexHullTrick{
	deque<ll> as,bs;
	// 傾きaは単調非増加でなければならない
	void AddLine(ll a,ll b){
		while(as.size()>=2){
			ll a1=as[as.size()-2],b1=bs[bs.size()-2];
			ll a2=as[as.size()-1],b2=bs[bs.size()-1];
			if((a1-a2)*(b1-b)<(a1-a)*(b1-b2)) break;
			as.pop_back(); bs.pop_back();
		}
		as.push_back(a); bs.push_back(b);
	}
	// 最小のax+bを返す
	ll Find(ll x){
		while(as.size()>=2){
			if(F(0,x)<F(1,x))
				break;
			as.pop_front(); bs.pop_front();
		}
		return F(0,x);
	}
	ll F(int i,ll x){
		return as[i]*x+bs[i];
	}
};
