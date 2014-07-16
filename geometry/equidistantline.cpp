vector<Line> EquidistantLine(Line a,Line b){
	if(Parallel(a,b))
		return {Line((a.pos+b.pos)/2,a.dir)};
	Point p=InterPointLL(a,b);
	a.dir/=Abs(a.dir),b.dir/=Abs(b.dir);
	return {Line(p,(a.dir+b.dir)/2),Line(p,(a.dir-b.dir)/2)};
}
