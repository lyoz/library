// Verify: AOJ 2402

double Dot(Point a,Point b)
{
	return real(conj(a)*b);
}

double Cross(Point a,Point b)
{
	return imag(conj(a)*b);
}
