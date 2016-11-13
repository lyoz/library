// Verify: AGC006 Problem E

ll InversionNumber(const vi& a)
{
	FenwickTree ft(a.size());
	ll res=0;
	rep(i,a.size()){
		res+=ft.Sum(a[i],a.size());
		ft.Add(a[i],1);
	}
	return res;
}
