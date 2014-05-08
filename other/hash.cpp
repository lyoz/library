namespace std{
	template<>
	struct hash<pair<int,int>>{
		size_t operator()(const pair<int,int>& p)const{
			const char* ptr=(const char*)&p;
			size_t res=2166136261;
			rep(i,sizeof(p)) (res^=*ptr++)*=16777619;
			return res;
		}
	};
}
