struct Stopwatch{
	using clock=chrono::system_clock;
	clock::time_point t0;
	clock::duration d0={};
	bool running=false;
	void Start(){
		if(!exchange(running,true))
			t0=clock::now();
	}
	void Stop(){
		if(exchange(running,false))
			d0+=clock::now()-t0;
	}
	void Reset(){
		d0={};
		running=false;
	}
	void Restart(){
		Reset();
		Start();
	}
	double Elapsed(){
		auto d=running?d0+(clock::now()-t0):d0;
		return chrono::duration_cast<chrono::nanoseconds>(d).count()*1e-9;
	}
};
