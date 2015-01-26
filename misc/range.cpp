class range{
	struct range_iterator{
		int value,step;
		range_iterator(int value,int step=1):value(value),step(step){}
		int operator*(){return value;}
		bool operator!=(const range_iterator& it){return value<it.value;}
		range_iterator& operator++(){value+=step; return *this;}
	};
public:
	int start,stop,step;
	range(int stop):start(0),stop(stop),step(1){}
	range(int start,int stop,int step=1):start(start),stop(stop),step(step){}
	range_iterator begin(){return range_iterator(start,step);}
	range_iterator end(){return range_iterator(stop);}
};
