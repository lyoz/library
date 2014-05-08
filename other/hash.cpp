namespace std{
	template<>
	struct hash<tuple<int,int>>{
		size_t operator()(const tuple<int,int>& x)const{
			const char* p=(const char*)&x;
			size_t res=2166136261;
			rep(i,sizeof(x)) (res^=*p++)*=16777619;
			return res;
		}
	};
}
