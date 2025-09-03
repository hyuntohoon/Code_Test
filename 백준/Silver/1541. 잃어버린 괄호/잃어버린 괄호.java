import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String st = br.readLine();
        String []arr = st.split("-");
        int sum = sumByPlus(arr[0]);
        for(int i = 1; i < arr.length; i++) {
            sum -= sumByPlus(arr[i]);
        }
        System.out.println(sum);
    }
    static public int sumByPlus(String temp){
        String []arr = temp.split("\\+");
        int sum = 0;
        for(int i=0;i<arr.length;i++){
            sum += Integer.parseInt(arr[i]);
        }
        return sum;
    }
}
