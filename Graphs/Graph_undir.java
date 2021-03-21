import java.util.*;
import java.io.*;

class Graph {
	ArrayList<HashSet<Integer>> graph;
	boolean looked[];
	int max_size;
	Graph(int nodes) {
		graph = new ArrayList<>();
		looked = new boolean[nodes];
		max_size = nodes;
		for(int i = 0 ; i < nodes; ++i) {
			graph.add(i, new HashSet<>());
		}
	}
	void add(int a, int b) {
		graph.get(a).add(b);
		graph.get(b).add(a);//comment if graph is directed
		
	}
	void dfs(int x) {
		looked[x] = true;
		System.out.print(x + " ");
		for(Integer vert : graph.get(x)) {
			if(! looked[vert])
				dfs(vert);
		}
	}
	void visu() {//to see what's the adjacency list contains
		System.out.println(graph);
	}
	void reset_looked(boolean print_ln) {//sets all vertices to unlooked
		if(print_ln) System.out.println();
		for(int i = 0; i < max_size; ++i) looked[i] = false;
	}
}

class Main {
	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		/*Input
		0 1
		0 2
		1 3
		2 4
		3 5
		4 5
		4 6
		*/
		Graph gg = new Graph(7);
		for(int i = 0; i < 7; ++i) {
			gg.add(Reader.nextInt(), Reader.nextInt());
		}
		gg.dfs(0);
		gg.reset_looked(true);
		gg.dfs(6);
		System.out.println();
		gg.visu();
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