// Verify: PKU 0155

void WarshallFloyd(vvd& dist,vvi& next)
{
	int n=dist.size();
	
	rep(i,n) rep(j,n)
		next[i][j]=j;
	
	rep(k,n) rep(i,n) rep(j,n){
		if(dist[i][j]>dist[i][k]+dist[k][j]){
			dist[i][j]=dist[i][k]+dist[k][j];
			next[i][j]=next[i][k];
		}
	}
}
