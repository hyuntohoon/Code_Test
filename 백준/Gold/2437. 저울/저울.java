import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> al = new ArrayList<>();
        for(int i = 0;i<N;i++){
            al.add(Integer.parseInt(st.nextToken()));
        }
        int nowCheck = 1;
        al.sort(Comparator.comparingInt(a -> a));
        for(int i = 0;i<N;i++){
            if(nowCheck < al.get(i)) break;
            nowCheck += al.get(i);
        }
        System.out.println(nowCheck);

    }
}