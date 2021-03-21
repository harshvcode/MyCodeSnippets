import java.util.*;
import java.io.*;

class Main {
	static int find_lin(int[] arr, int val) {
		int len = arr.length;
		for(int i = 0; i < len; ++i) {
			if(arr[i] == val) return i;
		}
		return -1;
	}
	
	static int find_binary(int[] arr, int val) {
		int i = 0, n = arr.length, j = n - 1, mid = (i + (j - i) / 2 );
		while(i <= j) {
			mid = (i + (j - i) / 2);
			if(arr[mid] == val) return mid;
			else if(arr[mid] < val) i = mid + 1;
			else j = mid - 1;
		}
		return -1;
	}
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		int[] arr = {23,61,62,63,64,65,66,67,68};
		System.out.println(find_lin(arr, 22) + " " + find_binary(arr, 93));
	}
}

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while (! tokenizer.hasMoreTokens()) {
            //TO DO add check for eof if necessary
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
	
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}