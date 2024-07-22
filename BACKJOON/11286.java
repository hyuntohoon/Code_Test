package daily08;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue; 

import javax.rmi.CORBA.StubDelegate;

public class Main_11286 {
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		PriorityQueue<absHeap> PQ = new PriorityQueue<>();
		for(int i=0;i<N;i++) {
			long temp = Integer.parseInt(in.readLine());
			if(temp != 0) {
				PQ.offer(new absHeap(temp));
			}
			else {
				if(PQ.isEmpty()) {
					System.out.println(0);
				}
				else {
					System.out.println(PQ.poll().val);
				}
			}
		}
	}
	public static class absHeap implements Comparable<absHeap>{
		public long val;
		public long absVal;
		public absHeap(long val) {
			super();
			this.val = val;
			this.absVal = Math.abs(val);
		}
		
		@Override
		public int compareTo(absHeap a) {
			if(this.absVal == a.absVal) {
				return (int)(this.val - a.val);
			}
			return (int)(this.absVal - a.absVal);
		}
	}
}
