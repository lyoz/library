struct Edge{
	int src,dst,weight;
	Edge(){}
	Edge(int s,int d,int w):src(s),dst(d),weight(w){}
	bool operator<(const Edge& e)const{return weight<e.weight;}
	bool operator>(const Edge& e)const{return weight>e.weight;}
};
typedef vector<vector<Edge> > Graph;
