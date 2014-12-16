struct Dice{
	int face[6]; // top,bottom,left,right,front,back
	void Rotate(int a,int b,int c,int d){
		int temp=face[a];
		face[a]=face[b];
		face[b]=face[c];
		face[c]=face[d];
		face[d]=temp;
	}
	void TurnF(int n){rep(i,n)Rotate(0,2,1,3);} // x軸を回転軸として右回りに90n度回転
	void TurnR(int n){rep(i,n)Rotate(0,4,1,5);} // y軸を回転軸として右回りに90n度回転
	void TurnU(int n){rep(i,n)Rotate(4,3,5,2);} // z軸を回転軸として右回りに90n度回転
	void TurnF(){TurnF(1);}
	void TurnR(){TurnR(1);}
	void TurnU(){TurnU(1);}
};
