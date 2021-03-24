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
		//graph.get(b).add(a);//comment if graph is directed
		
	}
	/*************DFS*******************/
	void dfs(int x) {
		Stack<Integer> st = new Stack<>();
		st.push(x);
		looked[x] = true;
		while(! st.isEmpty()) {
			x = st.pop();
			System.out.print(x + " ");
			for(int e : graph.get(x)) {
				if(! looked[e]) {
					st.push(e);
					looked[e] = true;
				}
			}
		}
	}
	/*********************BFS*********/
	void bfs(int x) {
		Queue<Integer> q = new LinkedList<>();
		q.add(x);
		looked[x] = true;
		while(! q.isEmpty()) {
			x = q.poll();// This method retrieves and removes the head.
			System.out.print(x + " ");
			for(int e : graph.get(x)) {
				if(! looked[e]) {
					q.add(e);
					looked[e] = true;
				}
			}
		}
	}
	/******************MST Basic*********/
	void mst(int x) {
		/*Input
		0 1
		0 2
		1 3
		2 4
		3 5
		4 5
		4 6
		5 6
		*/
		Stack<Integer> st = new Stack<>(), mst_trv = new Stack<>();
		st.push(x);
		looked[x] = true;
		mst_trv.push(x);
		while(! st.isEmpty()) {
			x = st.pop();
			for(int e : graph.get(x)) {
				if(! looked[e]) {
					st.push(e);
					mst_trv.push(e);
					looked[e] = true;
				}
			}
		}
		//Printing minimum spanning tree vertices
		while(! mst_trv.isEmpty()) {
			System.out.print(mst_trv.pop() + " ");
		}
		System.out.println();
	}
	
	/*************See Graph**********/
	
	void visu() {//to see what's the adjacency list contains
		System.out.println(graph);
	}
	
	/*****************Reset Looked to 0*************/
	void reset_looked(boolean print_ln) {//sets all vertices to unlooked
		if(print_ln) System.out.println();
		for(int i = 0; i < max_size; ++i) looked[i] = false;
	}
	
	/**********Cycle Detection Undirected Graph*************/
	boolean cycle_det_und() {//call this
		/*Input
		0 1
		0 6
		1 2
		2 4
		2 7
		3 7
		5 6
		5 3//comment or uncomment to see effect
		6 5
		7 2
		7 3
		*/
		reset_looked(false);
		for(int i = 0; i < max_size; ++i) {
			if(looked[i] == false && Helper_cycle_det_und(i, -1) == true)
				return true;
		}
		return false;
	}
	boolean Helper_cycle_det_und(int curr, int par) {//abstract helper
		looked[curr] = true;
		for (int i = 0; i < graph.get(curr).size() ; ++i) {
				List<Integer> list = new ArrayList<>(graph.get(curr));//hashset to list
                int vertex = list.get(i);
                //check the adjacent vertex from current vertex
                if(vertex != par) {
                    //if destination vertex is not its direct parent then
                    if(looked[vertex]){
                        //if here means this destination vertex is already visited
                        //means cycle has been detected
                        return true;
                    }
                    else{
                        //recursion from destination node
                        if (Helper_cycle_det_und(vertex, curr)) {
                            return true;
                        }
                    }
                }
        }
        return false;
	}
	
	/**********Cycle Detection Directed Graph*************
	Input:
		0 1
		0 2
		0 3
		1 2
		3 4
		4 5
		5 3  Comment or uncomment to see effect
		*/
	boolean cycle_found=false;
	int[] color_box;
	void color_ini() {//call this first
		cycle_found = false;
		reset_looked(false);
		color_box = new int[max_size];
		for(int i = 0; i < max_size; ++i) color_box[i] = 0;
		//System.out.println("Hey " + Arrays.toString(color_box));
	}
	void cycle_det_dir(int x) {//then call this
		//System.out.println("a");
		looked[x] = true;
		//System.out.println("b");
  		color_box[x] = 1;
  		//System.out.println("c");
  		for(int e: graph.get(x)) {
  			//System.out.println("d");
  			if(looked[e] == false && color_box[e] == 0) {
  				//System.out.println("e");
				cycle_det_dir(e);
			}
			else if(color_box[e] == 1) {
				//System.out.println("f");
				cycle_found = true;
				return;
			}
		}
		//System.out.println("g");
		color_box[x] = 0;
	}
	/*************Use till here*************/
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
		Graph gg = new Graph(6);
		for(int i = 0; i < 7; ++i) {
			gg.add(Reader.nextInt(), Reader.nextInt());
		}
		gg.color_ini();
		System.out.println(gg.cycle_found);
		gg.cycle_det_dir(0);
		System.out.println(gg.cycle_found);
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
