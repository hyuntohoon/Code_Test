package hwalgo13_부울경_04_박지훈;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main_골드5_1759_암호만들기 {
	static int L;
	static int C;
	static ArrayList<Character> list;
	static ArrayList<Character> code;
	static boolean isGood() {
		int mo = 0;
		int ja = 0;
		for(int i =0;i<L;i++) {
			int nowAl = code.get(i);
			if(nowAl == 97 || nowAl == 101 || nowAl == 105 || nowAl == 111 || nowAl == 117) mo++;
			else ja++;
		}
		if(mo>0 && ja >1) return true;
		return false;
	}
	static void DFS(int cnt, int start) {
		if(cnt == L) {
			if(isGood()) {
				for(Character c : code) System.out.print(c);
				System.out.println();
			}
			return;
		}
		
		for(int i=start;i<C;i++) {
			code.add(list.get(i));
			DFS(cnt+1, i+1);
			code.remove(cnt);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		list = new ArrayList<>();
		code = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < C; i++) {
			char temp = st.nextToken().charAt(0);
			list.add(temp);
		}
		Collections.sort(list);
		DFS(0,0);
	}
}
