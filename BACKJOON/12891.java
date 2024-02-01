package hwalgo03_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_실버2_12891_DNA비밀번호 {
	static int S,P,A,C,G,T;
	static char[] password;
	static boolean[] check;
	static String arr;
	static int result;
	static void subset(int start) {
		int a = 0, c = 0, g = 0, t = 0; // 각 문자의 개수를 카운트할 변수
	    // 초기 윈도우 설정
	    for(int i = 0; i < P; i++) {
	        char ch = arr.charAt(i);
	        if(ch == 'A') a++;
	        else if(ch == 'C') c++;
	        else if(ch == 'G') g++;
	        else if(ch == 'T') t++;
	    }
	    // 초기 윈도우 검사
	    if(a >= A && c >= C && g >= G && t >= T) result++;
	    
	    // 슬라이딩 윈도우 이동
	    for(int i = P; i < S; i++) {
	        char newChar = arr.charAt(i); // 윈도우에 새로 들어오는 문자
	        char oldChar = arr.charAt(i - P); // 윈도우에서 제거되는 문자
	        
	        // 새로운 문자 추가
	        if(newChar == 'A') a++;
	        else if(newChar == 'C') c++;
	        else if(newChar == 'G') g++;
	        else if(newChar == 'T') t++;
	        
	        // 오래된 문자 제거
	        if(oldChar == 'A') a--;
	        else if(oldChar == 'C') c--;
	        else if(oldChar == 'G') g--;
	        else if(oldChar == 'T') t--;
	        
	        // 갱신된 윈도우 검사
	        if(a >= A && c >= C && g >= G && t >= T) result++;
	    }
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String []temp = in.readLine().split(" ");
		S = Integer.parseInt(temp[0]);
		P = Integer.parseInt(temp[1]);
		arr = in.readLine();
		String []tempPart = in.readLine().split(" ");
		A = Integer.parseInt(tempPart[0]);
		C = Integer.parseInt(tempPart[1]);
		G = Integer.parseInt(tempPart[2]);
		T = Integer.parseInt(tempPart[3]);
		password = new char[P];
		check = new boolean[S];
		subset(0);
		System.out.println(result);
	}
}
