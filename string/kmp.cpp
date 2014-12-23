// Verify: [ctor] POJ 1961, POJ 2406
//         [Matches] POJ 3461, LOJ 1255, SPOJ 32

struct KMP{
	string p;
	vi fs;
	KMP(const string& p):p(p),fs(p.size()+1){
		for(int i=0,j=fs[0]=-1;i<p.size();){
			while(j>=0 && p[i]!=p[j]) j=fs[j];
			i++,j++;
			//fs[i]=j; // Morris-Pratt
			fs[i]=i<p.size()&&p[i]==p[j]?fs[j]:j;
		}
	}
	int Match(const string& s){
		for(int i=0,j=0;i<s.size();){
			while(j>=0 && s[i]!=p[j]) j=fs[j];
			i++,j++;
			if(j==p.size()) return i-j;
		}
		return -1;
	}
	vi Matches(const string& s){
		vi res;
		for(int i=0,j=0;i<s.size();){
			while(j>=0 && s[i]!=p[j]) j=fs[j];
			i++,j++;
			if(j==p.size()){
				res.push_back(i-j);
				j=fs[j];
			}
		}
		return res;
	}
};
