// Verify: LightOJ 1222

vi KuhnMunkres(const vvi& a)
{
	int m=a.size(),n=a[0].size();
	vi lmatch(m,-1),rmatch(n,-1);
	vi loffset(m),roffset(n);

	auto residue=[&](int i,int j){return a[i][j]+loffset[i]+roffset[j];};

	rep(root,m){
		vi lused(m),rused(n);
		vi parent(n),mini(n,root);
		lused[root]=true;
		for(;;){
			int mn=INF;
			rep(j,n) if(!rused[j]) mn=min(mn,residue(mini[j],j));
			rep(i,m) if(lused[i]) loffset[i]-=mn;
			rep(j,n) if(rused[j]) roffset[j]+=mn;

			int v=-1;
			rep(j,n) if(!rused[j]&&residue(mini[j],j)==0) v=j;
			parent[v]=mini[v];
			int u=rmatch[v];
			if(u==-1){
				for(;v!=-1;){
					int p=parent[v],w=lmatch[p];
					lmatch[p]=v;
					rmatch[v]=p;
					v=w;
				}
				break;
			}
			lused[u]=rused[v]=true;
			rep(j,n) if(residue(mini[j],j)>residue(u,j)) mini[j]=u;
		}
	}
	return lmatch;
}
