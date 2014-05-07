// Verify: POJ 2914(5657ms)

int NagamochiIbaraki(const Graph& g)
{
	int size=g.size();
	vvi a(size,vi(size));
	rep(i,size) foreach(e,g[i])
		a[e->src][e->dst]+=e->weight;
	vi toi(size);
	rep(i,size) toi[i]=i;
	
	int res=INFTY;
	for(int n=size;n>=2;n--){
		vi ws(n);
		int u,v,w;
		rep(i,n){
			u=v; v=max_element(all(ws))-ws.begin();
			w=ws[v]; ws[v]=-1;
			rep(j,n) if(ws[j]>=0)
				ws[j]+=a[toi[v]][toi[j]];
		}
		res=min(res,w);
		rep(i,n){
			a[toi[u]][toi[i]]+=a[toi[v]][toi[i]];
			a[toi[i]][toi[u]]+=a[toi[i]][toi[v]];
		}
		toi.erase(toi.begin()+v);
	}
	return res;
}
