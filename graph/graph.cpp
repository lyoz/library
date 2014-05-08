struct Edge{
	int src,dst,weight;
	Edge(){}
	Edge(int s,int d,int w):src(s),dst(d),weight(w){}
};
typedef vector<vector<Edge> > Graph;
bool operator<(const Edge& a,const Edge& b)const{return a.weight<b.weight;}
bool operator>(const Edge& a,const Edge& b)const{return a.weight>b.weight;}
