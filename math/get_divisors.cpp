// Verify: Codeforces Round #424 Div1 C

// n/dの商が切り替わる最小のdたちを返す
// 例: n=100ならres={1,2,3,...,34,51,101}
vi divisors(int n)
{
	vi res={1};
	for(int r=n;r>0;){
		ll d=n/r+1;
		res.push_back(d);
		r=n/d;
	}
	return res;
}
