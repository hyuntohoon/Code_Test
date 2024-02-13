package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Sugar {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int Five = N/5;
		int temp = N-(Five*5);
		int Three = 0;
		while(true) {
			if(temp == 0) {
				System.out.println(Five+Three);
				break;
			}
			else {
				Five--;
				if(Five >=0) {
					temp+=5;
				}
				Three = temp/3;
				temp = temp-(Three*3);
			}
			//System.out.println(temp%3);
			if(Five<0 && temp%3 > 0) {
				System.out.println(-1);
				break;
			}
		}
	}
}
