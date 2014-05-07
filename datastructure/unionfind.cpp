// Verify: PKU 2524, PKU 1182

struct UnionFind{
	vi data;
	UnionFind(int size):data(size,-1){}
	int Find(int n){
		return data[n]<0?n:(data[n]=Find(data[n]));
	}
	void Unite(int a,int b){
		int ra=Find(a),rb=Find(b);
		if(ra!=rb){
			if(-data[ra]<-data[rb])
				swap(ra,rb);
			data[ra]+=data[rb];
			data[rb]=ra;
		}
	}
	int Size(int n){
		return -data[Find(n)];
	}
};
