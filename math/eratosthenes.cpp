// Verify: AOJ 1172

void Eratosthenes(vi& isp)
{
	isp[0]=isp[1]=0;
	fill(2+all(isp),1);
	for(int i=2;i*i<isp.size();i++)
		if(isp[i])
			for(int j=i*i;j<isp.size();j+=i)
				isp[j]=0;
}
