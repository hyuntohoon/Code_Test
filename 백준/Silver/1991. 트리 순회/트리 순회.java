import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        int left, right;
        Node(int l, int r){ left = l; right = r; }
    }

    static Node[] tree;

    static void pre(int u){
        if (u == -1) return;
        System.out.print((char)('A' + u));
        pre(tree[u].left);
        pre(tree[u].right);
    }
    static void ino(int u){
        if (u == -1) return;
        ino(tree[u].left);
        System.out.print((char)('A' + u));
        ino(tree[u].right);
    }
    static void post(int u){
        if (u == -1) return;
        post(tree[u].left);
        post(tree[u].right);
        System.out.print((char)('A' + u));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        tree = new Node[26];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int root = st.nextToken().charAt(0) - 'A';
            char lc = st.nextToken().charAt(0);
            char rc = st.nextToken().charAt(0);
            int left = (lc == '.') ? -1 : (lc - 'A');
            int right = (rc == '.') ? -1 : (rc - 'A');
            tree[root] = new Node(left, right);
        }

        pre(0); System.out.println();
        ino(0); System.out.println();
        post(0); System.out.println();
    }
}