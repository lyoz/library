// Verify: AOJ 0109

typedef pair<int,const char*> parsed;

parsed expr(const char*);
parsed term(const char*);
parsed fact(const char*);

parsed expr(const char* s)
{
	parsed now=term(s);
	while(*now.second=='+' || *now.second=='-'){
		char op=*now.second;
		parsed next=term(now.second+1);
		if(op=='+')
			now=parsed(now.first+next.first,next.second);
		else
			now=parsed(now.first-next.first,next.second);
	}
	return now;
}

parsed term(const char* s)
{
	parsed now=fact(s);
	while(*now.second=='*' || *now.second=='/'){
		char op=*now.second;
		parsed next=fact(now.second+1);
		if(op=='*')
			now=parsed(now.first*next.first,next.second);
		else
			now=parsed(now.first/next.first,next.second);
	}
	return now;
}

parsed fact(const char* s)
{
	if(s[0]=='('){
		parsed res=expr(s+1);
		res.second++;
		return res;
	}
	else{
		const char* p=s;
		if(*p=='-')
			p++;
		ll n=0;
		while(isdigit(*p)){
			n=n*10+(*p-'0');
			p++;
		}
		return parsed(n,p);
	}
}
