package hwalgo05_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_D3_1228_암호문1_박지훈 {
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		for(int t=1;t<11;t++) {
			int N = Integer.parseInt(in.readLine());
			ArrayList<String> list = new ArrayList<>();
			StringTokenizer st = new StringTokenizer(in.readLine());
			for(int j=0;j<N;j++) {
				list.add(st.nextToken());
			}
			int M = Integer.parseInt(in.readLine());
			st = new StringTokenizer(in.readLine());
			for(int j=0;j<M;j++) {
				st.nextToken();
				int x = Integer.parseInt(st.nextToken());	
				int y = Integer.parseInt(st.nextToken());	
				for(int i=0;i<y;i++) {
					list.add(x++, st.nextToken());
				}
			}

			sb.append("#"+t+" ");
			for(int i=0;i<10;i++) {
				sb.append(list.get(i)+" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

}
