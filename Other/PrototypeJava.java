import java.util.*;
import java.io.*;
//20m52t
public class Main implements Comparator<String> {	
  /**************Number Sorter String Positive*********/
  public int compare(String a, String b) {
    if(a.length() == b.length()) return a.compareTo(b);
		else if(a.length() < b.length()) return -1;
		else return 1;
  }
  /*******************SOLVER**********************/
  static void solve(FastReader in) throws IOException {//System.out.println(
  }
  /*******************MAIN************************/
  public static void main(String[] args) throws IOException {
		FastReader in = new FastReader();
		int tc = in.nextInt() + 1;
		while(--tc > 0) solve(in);
  }
}
/**********************FAST READER*********************/
class FastReader {
	BufferedReader br;
  StringTokenizer st;
  public FastReader() {
	  br = new BufferedReader(new InputStreamReader(System.in));
  }
  String next() {
	  while (st == null || !st.hasMoreElements()) {
  	  try {
    		st = new StringTokenizer(br.readLine());
      }
      catch (IOException e) {
      	e.printStackTrace();
      }
    }
    return st.nextToken();
  }
  int nextInt() { return Integer.parseInt(next()); }
  long nextLong() { return Long.parseLong(next()); } 
  double nextDouble() { return Double.parseDouble(next()); }
  String nextLine() {
  	String str = "";
  	try {
  		str = br.readLine();
    }
    catch (IOException e) {
	    e.printStackTrace();
    }
	  return str;
  }
}
