import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class Main{public static void main(String[] args){new Solver();}}

class Solver{
	ScanReader reader=new ScanReader(System.in);
	PrintWriter writer=new PrintWriter(System.out);
	Solver(){main(); writer.flush();}
	
	void main(){
	}
}

class ScanReader{
	BufferedReader br;
	StringTokenizer st;
	public ScanReader(InputStream in){
		br=new BufferedReader(new InputStreamReader(in));
		st=null;
	}
	public boolean hasNext(){
		while(st==null || !st.hasMoreTokens()){
			try{
				if(!br.ready())
					return false;
				st=new StringTokenizer(br.readLine());
			}
			catch(IOException e){
				throw new RuntimeException(e);
			}
		}
		return true;
	}
	public String nextLine(){
		hasNext();
		return st.nextToken("");
	}
	public String next(){
		hasNext();
		return st.nextToken();
	}
}
