// Verify: [ctor] POJ 1961, POJ 2406, [MatchAll] POJ 3461, LOJ 1255, SPOJ 32

struct KMP{
	string pat;
	vi fail;
	KMP(const string& p):pat(p),fail(p.size()+1){
		fail[0]=-1;
		for(int i=0,j=-1;i<pat.size();){
			while(j>=0 && pat[i]!=pat[j])
				j=fail[j];
			i++,j++;
			fail[i]=j;
		}
	}
	int Match(const string& text){
		for(int i=0,j=0;i<text.size();){
			while(j>=0 && text[i]!=pat[j])
				j=fail[j];
			i++,j++;
			if(j==pat.size())
				return i-j;
		}
		return -1;
	}
	vi MatchAll(const string& text){
		vi res;
		for(int i=0,j=0;i<text.size();){
			while(j>=0 && text[i]!=pat[j])
				j=fail[j];
			i++,j++;
			if(j==pat.size()){
				res.push_back(i-j);
				j=fail[j];
			}
		}
		return res;
	}
};
