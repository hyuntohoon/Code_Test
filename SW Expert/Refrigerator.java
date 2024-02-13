package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import greedy.MeetingRoomTest.Meeting;

public class Refrigerator {
	static class Ref implements Comparable<Ref> {
		int start;
		int end;

		public Ref(int start, int end) {
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Ref other) {
			return this.end - other.end;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		ArrayList<Ref> ref = new ArrayList<>();
		for(int i = 0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			ref.add(new Ref(start,end));
		}
		Collections.sort(ref);
		int count = 1;
		int end = ref.get(0).end;
		for(int i = 1; i < N; i++) {
			// 현재 회의의 시작 시간이 이전에 선택된 회의의 종료 시간보다 크거나 같다면 회의를 선택합니다.
			if(ref.get(i).start > end) {
				end = ref.get(i).end;
				count++;
			}
		}

		System.out.println(count);
	}
}
