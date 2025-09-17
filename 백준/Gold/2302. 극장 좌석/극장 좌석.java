import java.io.*;

public class Main {
    public static int[]dx ={0,0,1,-1};
    public static int[]dy={1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int vipCount = Integer.parseInt(br.readLine());
        boolean [] isVip = new boolean[N+1];
        for(int i = 1; i <= vipCount; i++){
            int vip = Integer.parseInt(br.readLine());
            isVip[vip] = true;
        }
        int []DP = new int[N+1];
        DP[1] = 1;
        DP[0] = 1;
        for(int i = 2; i <= N; i++){
            if(isVip[i] || isVip[i-1]){
                DP[i] = DP[i-1];
            }
            else{
                DP[i] = DP[i-1] + DP[i-2];
            }
        }

        System.out.println(DP[N]);
    }
}