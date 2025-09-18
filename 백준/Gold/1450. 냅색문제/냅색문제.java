import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static int N,C;
    static int ans;
    static int temp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        DFS(0,N/2,0,arr, left);
        DFS(N/2,N,0,arr, right);

        left.sort(Comparator.naturalOrder());
        right.sort(Comparator.naturalOrder());

        int ans = 0;
        for(int i : left){
            int maxRightIndex = bi(C-i,right);
           // System.out.println(maxRightIndex);
            ans += maxRightIndex;
        }
        System.out.println(ans);
    }

    private static int bi(int target, ArrayList<Integer> right) {
        int start = 0;
        int end = right.size();
        //System.out.println("nowTarget" + target);
        while(start < end){
            int mid = start + (end - start) / 2;
            if(target<right.get(mid)){ // 타겟이 더 작으면

                end = mid;
            }
            else{
               start =mid +1;
            }
        }
        return start;
    }

    static void DFS(int now, int end, int nowValue, int[]arr,ArrayList<Integer> nowList){
        if(nowValue > C) return;
        if(now == end){
            nowList.add(nowValue);
            return;
        }
        DFS(now+1, end, nowValue+arr[now], arr, nowList);
        DFS(now+1, end, nowValue, arr, nowList);
    }
}
/*
7 10
6 2 3 4 5 1 4
 */