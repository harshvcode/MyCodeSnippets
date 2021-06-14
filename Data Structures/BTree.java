import java.io.*;
import java.util.*;

class BTree {
    static PrintWriter w;
    static InputReader in;

    static class node {
        int key;
        node left, right;

        node(int key) {
            this.key = key;
            left = right = null;
        }
    }

    static node root;

    static void insert(node root, int key) {
        if (root == null) {
            root = new node(key);
            return;
        }
        Queue<node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            node tmp = q.poll();
            if (tmp.left != null) {
                q.add(tmp.left);
            } else {
                tmp.left = new node(key);
                return;
            }
            if (tmp.right != null) {
                q.add(tmp.right);
            } else {
                tmp.right = new node(key);
                return;
            }
        }
        return;
    }

    static void inorder(node root) {
        if (root == null)
            return;
        inorder(root.left);
        w.print(root.key + " ");
        inorder(root.right);
    }

    static void preorder(node temp) {
        if (temp == null)
            return;
        w.print(temp.key + " ");
        preorder(temp.left);
        preorder(temp.right);
    }

    static ArrayList<Integer> preOrder(node root) // Iterative PreOrder, returns preOrder into a ArrayList
    {
        if (root == null)
            return new ArrayList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        Stack<node> st = new Stack<>();
        st.add(root);
        while (!st.empty()) {
            node tmp = st.peek();
            st.pop();
            ans.add(tmp.key);
            if (tmp.right != null)
                st.push(tmp.right); // Put right node in stack first
            if (tmp.left != null)
                st.push(tmp.left); // so that left be on top, and traverse left first
        }
        return ans;
    }

    static void postorder(node temp) {
        if (temp == null)
            return;
        postorder(temp.left);
        postorder(temp.right);
        w.print(temp.key + " ");
    }

    static void utildelDeepest(node root, node deletit) {
        Queue<node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            node tmp = q.poll();
            if (tmp == deletit) {
                tmp = null;
                return;
            }
            if (tmp.left != null) {
                if (tmp.left == deletit) {
                    tmp.left = null;
                    return;
                } else {
                    q.add(tmp.left);
                }
            }
            if (tmp.right != null) {
                if (tmp.right == deletit) {
                    tmp.right = null;
                    return;
                } else {
                    q.add(tmp.right);
                }
            }
        }
    }

    static void deleete(node dummy, int key) {
        if (dummy == null)
            return;
        if (dummy.left == null && dummy.right == null) {
            if (dummy.key == key)
                root = null;// changed global root;
            return;
        }
        Queue<node> q = new LinkedList<>();
        q.add(dummy);
        node lastDeep = null, keyNode = null; // lastDeep will be deleted and it's key will be the key of keyNode
        while (!q.isEmpty()) {
            lastDeep = q.poll();
            if (lastDeep.key == key) {
                keyNode = lastDeep;
            }
            if (lastDeep.left != null)
                q.add(lastDeep.left);
            if (lastDeep.right != null)
                q.add(lastDeep.right);
        }
        if (keyNode != null) {
            int lastNodeKey = lastDeep.key;
            utildelDeepest(root, lastDeep);
            keyNode.key = lastNodeKey;
        }
    }

    static int height(node root) { // height calculate recursively
        return (root != null) ? Math.max(height(root.left), height(root.right)) + 1 : 0;
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        w = new PrintWriter(System.out);
        root = new node(0);
        for (int i = 1; i <= 5; ++i)
            insert(root, i);
        w.println(height(root));
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
