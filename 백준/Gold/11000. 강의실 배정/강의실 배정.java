import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        ArrayList<int[]> room = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            room.add(new int[]{start, end});
        }
        room.sort(Comparator.comparingInt(a -> a[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(room.get(0)[1]);
        for(int i = 1;i<room.size();i++){
           int nowEnd= pq.poll();
            if(nowEnd <= room.get(i)[0]) {
                pq.add(room.get(i)[1]);
            }
            else{
                pq.add(nowEnd);
                pq.add(room.get(i)[1]);
            }
        }
        System.out.println(pq.size());
    }
}