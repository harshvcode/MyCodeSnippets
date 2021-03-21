import java.util.*;
import java.io.*;

//Linkedlist implementation
class Node {//node class
	int x;
	Node next;
	Node(int x) {
		this.x = x;
		next = null;
	}
}

class Linkedlist {//main linkedlist class
	Node head;
	void add(int x) {
		Node new_ = new Node(x);
		new_.next = head;
		head = new_;
	}
	void trv() {//traversal method
		Node tmp = head;
		while(tmp != null) {
			System.out.print(tmp.x + " ");
			tmp = tmp.next;
		}
		System.out.println();
	}
}

class Main {
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		Linkedlist ll = new Linkedlist();
		for(int i = 1; i <= 10; ++i) {
			ll.add(i);
		}
		ll.trv();
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