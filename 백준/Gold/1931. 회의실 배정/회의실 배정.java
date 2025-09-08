import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        ArrayList<int[]> al = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            al.add(new int[]{a, b});
        }
        al.sort((x,y) -> x[1] == y[1] ? x[0] - y[0] : x[1] -y[1]);
        int end = Integer.MIN_VALUE;
        int sum = 0;
        for(int i = 0; i < al.size(); i++) {
            int x = al.get(i)[0];
            int y = al.get(i)[1];
            if(x >= end){
                end = y;
                sum++;
            }
        }
        System.out.println(sum);
    }
}