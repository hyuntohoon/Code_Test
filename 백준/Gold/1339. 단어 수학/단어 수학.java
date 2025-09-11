import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class gird implements Comparable<gird>{
        double sum;
        char alp;
        public gird(double sum, char alp){
            this.sum = sum;
            this.alp = alp;
        }


        @Override
        public int compareTo(gird o) {
            return (int)this.sum - (int)o.sum;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        //PriorityQueue <gird> pq = new PriorityQueue<>();
        Map<Character, Integer> map = new HashMap<>();
        Set<Character> pq = new HashSet<>();
        String []arr = new String[N];
        for (int i = 0; i < N; i++) {
            String temp = br.readLine();
            arr[i] = temp;
            for(int j = 0; j < temp.length(); j++){
                map.put(temp.charAt(j), map.getOrDefault(temp.charAt(j), 0) + (int)Math.pow(10,temp.length()-1-j));
                //System.out.print(map.get(temp.charAt(j)) + " ");
                pq.add(temp.charAt(j));
            }
        }
        int now = 9;
        PriorityQueue<gird> pqq = new PriorityQueue<>(Comparator.reverseOrder());
        for(char c : pq){
            map.get(c);
            pqq.add(new gird(map.get(c), c));
        }
        Map<Character, Integer> map2 = new HashMap<>();
        while(!pqq.isEmpty()){
            gird p = pqq.poll();
            map2.put(p.alp, now);
            //System.out.println(p.alp + " " + now);
            now--;
        }
        int sum = 0;
        for(int i =0;i<N;i++){
            String nowTemp =arr[i];
            int start = (int)Math.pow(10,nowTemp.length()-1);
           // System.out.println(start);
            for(int j =0;j<nowTemp.length();j++){
                char nowChar = nowTemp.charAt(j);
                sum+= map2.get(nowChar) * start;
                start/=10;
            }
        }
        System.out.println(sum);
    }
}