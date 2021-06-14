import java.io.*;
import java.util.*;

class Graph {
    static PrintWriter w;
    static InputReader in;

    static class Pair {
        int to, wt;

        Pair(int to, int wt) {
            this.to = to;
            this.wt = wt;
        }

        Pair(int to) {
            this.to = to;
            wt = -1;
        }
    }

    static int N = 2;// included N
    static int INF = Integer.MAX_VALUE;
    static ArrayList<ArrayList<Pair>> gr = new ArrayList<>(N + 1);// 2-D ArrayList needs to be initialized
    static byte[] vis = new byte[N + 1];

    static void initGr() {
        for (int i = 0; i <= N; ++i)
            gr.add(i, new ArrayList<>());
    }

    static void dfs(int v) {
        if (vis[v] == 1)
            return;
        w.print(v + " ");
        vis[v] = 1;
        for (Pair e : gr.get(v)) {
            if (vis[e.to] != 1) {
                dfs(e.to);
            }
        }
    }

    static void bfs(int v) {
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        vis[v] = 1;
        while (!q.isEmpty()) {
            v = q.poll();
            w.print(v + " ");
            for (Pair e : gr.get(v)) {
                if (vis[e.to] != 1) {
                    q.add(e.to);
                    vis[e.to] = 1;
                }
            }
        }
    }

    static void resetVis() {
        for (int i = 0; i <= N; ++i)
            vis[i] = 0;
    }

    static void utiltopSort(int v, Stack<Integer> st) {
        if (vis[v] == 1)
            return;
        vis[v] = 1;
        for (Pair e : gr.get(v)) {
            utiltopSort(e.to, st);
        }
        st.push(v);
    }

    static void topSort() {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i <= N; ++i)
            if (vis[i] == 1)
                utiltopSort(i, st);
        while (!st.isEmpty()) {
            w.print(st.peek() + " ");
            st.pop();
        }
    }

    static boolean utilcycDir(int v) {
        if (vis[v] == 1)
            return true;
        if (vis[v] == 2)
            return false;
        vis[v] = 1;
        for (Pair e : gr.get(v)) {
            if (utilcycDir(e.to))
                return true;
        }
        vis[v] = 2;
        return false;
    }

    static boolean cycDir() {
        for (int i = 0; i <= N; ++i) {
            if (vis[i] == 0 && utilcycDir(i))
                return true;
        }
        return false;
    }

    static class utilPrimCompar implements Comparator<Pair> {
        @Override
        public int compare(Pair a, Pair b) {
            if (a.to == b.to)
                return 0;
            if (a.to < b.to)
                return -1;
            return 1;
        }
    }

    static void priMst() {// Used for undire always
        int src = 0;
        ArrayList<Integer> dist = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; ++i)
            dist.add(i, INF);
        ArrayList<Integer> par = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; ++i)
            par.add(i, -1);
        // vis will be used to check whether a vertex is in MST.
        PriorityQueue<Pair> pq = new PriorityQueue<>(new utilPrimCompar());// to=weight and wt=vertex
        pq.add(new Pair(0, src));// weight of src is 0(always)
        vis[src] = 1;
        dist.set(src, 0);
        while (!pq.isEmpty()) {
            int u = pq.poll().wt;
            vis[u] = 1;
            for (Pair e : gr.get(u)) {
                int v = e.to;// weight
                int w = e.wt;// vertex(check Comment After PriorityQ declare)
                if (vis[v] == 0 && dist.get(v) > w) {
                    dist.set(v, w);
                    pq.add(new Pair(dist.get(v), v));
                    par.set(v, u);
                }
            }
        }
        for (int i = 0; i <= N; ++i)
            w.println(par.get(i) + " " + i);
    }

    static void dijkstras(int s) {// arg is src
        ArrayList<Integer> d = new ArrayList<>(N + 1), p = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; ++i)
            d.add(i, INF);
        for (int i = 0; i <= N; ++i)
            p.add(i, 0);
        d.set(s, 0);
        for (int i = 0; i <= N; ++i) {
            int v = -1;
            for (int j = 0; j <= N; ++j)
                if (vis[j] == 0 && (v == -1 || d.get(j) < d.get(v)))
                    v = j;
            if (d.get(v) == INF)
                break;
            vis[v] = 1;

            for (int j = 0; j < gr.get(v).size(); ++j) {
                int to = gr.get(v).get(j).to;
                int len = gr.get(v).get(j).wt;
                if (d.get(v) + len < d.get(to)) {
                    d.set(to, d.get(v) + len);
                    p.set(to, v);
                }
            }
        }
        for (int i = 0; i <= N; ++i)
            w.println(i + " -> " + d.get(i));
    }

    static void bellmanFord(int src) {
        ArrayList<Integer> dist = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; ++i)
            dist.add(i, INF);
        dist.set(src, 0);
        for (int u = 0; u <= N; ++u) {
            for (Pair e : gr.get(u)) {
                int v = e.to;
                int w = e.wt;
                int tmpDist = dist.get(u) + w;
                if (tmpDist < dist.get(v)) {
                    dist.set(v, tmpDist);
                }
            }
        }
        dist.set(src, 0);
        for (int i = 0; i <= N; ++i)
            w.println(i + " -> " + dist.get(i));
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        w = new PrintWriter(System.out);
        initGr();
        //Input: 0 2 1 0 1 5 1 2 3
        int from, to, wt;
        for (int i = 1; i <= 3; ++i) {
            from = in.nextInt();
            to = in.nextInt();
            wt = in.nextInt();
            gr.get(from).add(new Pair(to, wt));
            gr.get(to).add(new Pair(from, wt));
        }
        bellmanFord(0);
        w.close();
    }

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;

        public InputReader(InputStream st) {
            this.stream = st;
        }

        public int read() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
    }
}