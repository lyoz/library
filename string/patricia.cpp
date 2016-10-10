// Verify: Code Festival 2016 予選B 問題E

constexpr int ALPHABET=26;

int ToInt(char c)
{
	return c-'a';
}

char ToChar(int x)
{
	return x+'a';
}

struct Node{
	char value;
	shared_ptr<Node> parent;
	array<shared_ptr<Node>,ALPHABET> children;
	bool last;
	int count;
	Node(char v):value(v),last(false),count(0){}
};

struct Patricia{
	shared_ptr<Node> root;
	vector<shared_ptr<Node>> lasts;
	Patricia():root(make_shared<Node>('!')){}
	void Add(const string& s){
		auto cur=root;
		for(char c:s){
			auto& child=cur->children[ToInt(c)];
			if(!child){
				child=make_shared<Node>(c);
				child->parent=cur;
			}
			cur=child;
			cur->count++;
		}
		cur->last=true;
		lasts.push_back(cur);
	}
	void Compress(){
		for(auto cur:lasts){
			while(cur && cur->parent && cur->parent->parent){
				auto p=cur->parent,g=p->parent;
				if(cur->count==p->count){
					g->children[ToInt(p->value)]=cur;
					cur->value=p->value;
					cur->parent=g;
				}
				else
					cur=p;
			}
		}
	}
};
