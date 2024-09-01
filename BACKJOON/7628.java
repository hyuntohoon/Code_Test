import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static String arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            arr = br.readLine();
            if(arr.equals("end")) break;
            int XTic = countTic('X');
            int OTic = countTic('O');

            int XCount = countChar('X');
            int OCount = countChar('O');
            //int dotCount = countChar('.');

            if(XTic == 1 && OTic == 0 && XCount == OCount+1){
                System.out.println("valid");
                continue;
            }
            if(XTic == 0 && OTic == 1 && XCount == OCount){
                System.out.println("valid");
                continue;
            }

            if(XTic == 0 && OTic == 0 && XCount == 5 && OCount == 4){
                System.out.println("valid");
                continue;
            }
            System.out.println("invalid");
        }
    }
    static int countTic(char c) {
        // 가로 확인
        for (int i = 0; i < 7; i += 3) {
            if (arr.charAt(i) == c && arr.charAt(i + 1) == c && arr.charAt(i + 2) == c) {
                return 1;
            }
        }

        // 세로 확인
        for (int i = 0; i < 3; i++) {
            if (arr.charAt(i) == c && arr.charAt(i + 3) == c && arr.charAt(i + 6) == c) {
                return 1;
            }
        }

        // 대각선 확인
        if ((arr.charAt(0) == c && arr.charAt(4) == c && arr.charAt(8) == c) ||
                (arr.charAt(2) == c && arr.charAt(4) == c && arr.charAt(6) == c)) {
            return 1;
        }

        return 0;
    }

    static int countChar(char c){
        int count = 0;
        for(int i=0;i<arr.length();i++){
            if(arr.charAt(i) == c){
                count++;
            }
        }
        return count;
    }
}
