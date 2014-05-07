// Verify: LiveArchive 5821, ACPC2012 F

struct Point{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
};
bool LessX(Point a,Point b){
	return a.x<b.x;
}
bool LessY(Point a,Point b){
	return a.y<b.y;
}

struct RangeTree2D{
	vector<Point> yps;
	struct RangeNode2D{
		vector<Point> xps;
		RangeNode2D *left,*right;
		RangeNode2D(const vector<Point>& ps):xps(ps),left(0),right(0){
			sort(all(xps),LessX);
		}
		~RangeNode2D(){
			delete left;
			delete right;
		}
	}*root;
	RangeTree2D(const vector<Point>& ps):yps(ps){
		sort(all(yps),LessY);
		root=Build(0,yps.size());
	}
	~RangeTree2D(){
		delete root;
	}
	RangeNode2D* Build(int first,int last){
		RangeNode2D* node=new RangeNode2D(vector<Point>(yps.begin()+first,yps.begin()+last));
		if(last-first>=2){
			int middle=(first+last)/2;
			node->left=Build(first,middle);
			node->right=Build(middle,last);
		}
		return node;
	}
	int Query(int to,int le,int bo,int ri,RangeNode2D* root,int first,int last){
		if(first==last || yps[last-1].y<to || bo<=yps[first].y)
			return 0;
		if(to<=yps[first].y && yps[last-1].y<bo){
			iter(root->xps) i=lower_bound(all(root->xps),Point(le,0),LessX);
			iter(root->xps) j=lower_bound(all(root->xps),Point(ri,0),LessX);
			return j-i;
		}
		int middle=(first+last)/2,res=0;
		res+=Query(to,le,bo,ri,root->left,first,middle);
		res+=Query(to,le,bo,ri,root->right,middle,last);
		return res;
	}
	int Query(int to,int le,int bo,int ri){
		return Query(to,le,bo,ri,root,0,yps.size());
	}
};
