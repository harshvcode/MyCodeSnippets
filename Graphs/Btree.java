import java.util.*;
import java.io.*;

class Node {//class to create nodes
	int key;
	Node left, right;
	Node(int item) {
		key = item;
		left = right = null;
	}
}

class BinaryTree {
	Node root;
	public void trv(Node node) {
		if(node != null) {
			trv(node.left);
			System.out.print(node.key + " ");
			trv(node.right);
		}
	}
}

class Main {
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		BinaryTree tree = new BinaryTree();
	    // create nodes of the tree
    	tree.root = new Node(1);
    	tree.root.left = new Node(2);
    	tree.root.right = new Node(3);
    	tree.root.left.left = new Node(4);
    	tree.trv(tree.root);
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