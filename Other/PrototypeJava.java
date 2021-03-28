/*
 dedidec | hvsreal.223@gmail.com
*/
import java.util.*;
import java.io.*;
class Temp {
  int mod = (int)1e9 + 8;
  long inf = (long)1e18;
  void nl() { System.out.println(); }
  long stbits(long n) { return Long.bitCount(n); }
  long zrbits(long n) { return 32 + (32 - Long.numberOfLeadingZeros(n) - stbits(n)); }
  void ssp(int[] s,char d) { for(int e : s) System.out.print(e + ""+ d); nl(); }
  void ssp(int[] s,int n,char d) { for(int i=0; i<n; ++i) System.out.print(s[i] + ""+ d); nl(); }
  void ssp(long[] s,int n,char d) { for(int i=0; i<n; ++i) System.out.print(s[i] + ""+ d); nl(); }
  void ssp(long[] s,char d) { for(long e : s) System.out.print(e + ""+ d); nl(); }
  void ssp(char[] s,int n,char d) { for(int i=0; i<n; ++i) System.out.print(s[i] + ""+ d); nl(); }
  void ssp(char[] s,char d) { for(char e : s) System.out.print(e + ""+ d); nl(); }
  void ssp(String[] s,int n,char d) { for(int i=0; i<n; ++i) System.out.print(s[i] + ""+ d); nl(); }
  void ssp(String[] s,char d) { for(String e : s) System.out.print(e + ""+ d); nl(); }
  void ssp(double[] s,int n,char d) { for(int i=0; i<n; ++i) System.out.print(s[i] + ""+ d); nl(); }
  void ssp(double[] s,char d) { for(double e : s) System.out.print(e + ""+ d); nl(); }
  int gcd(int a,int b) { return b!=0 ? gcd (b, a % b) : a; }
  long gcd(long a,long b) { return b!=0 ? gcd (b, a % b) : a; }
  int max(int a,int b) { return a > b ? a : b; }
  long max(long a,long b) { return a > b ? a : b; }
  int min(int a,int b) { return a < b ? a : b; }
  long min(long a,long b) { return a < b ? a : b; }
  void dedidec() {System.out.print
  }
}
class Main {
  /*******************MAIN************************/
  public static void main(String[] args) throws IOException {
    Temp late = new Temp();
    late.dedidec();
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
