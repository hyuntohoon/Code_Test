package daily22;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import daily22.PrimPQTest.Vertex;

public class solution {
	static class Vertex implements Comparable<Vertex> {
		int no;
		long weight;
		Vertex next;

		public Vertex(int no, long weight, Vertex next) {
			super();
			this.no = no;
			this.weight = weight;
			this.next = next;
		}

		@Override
		public int compareTo(Vertex o) {
			return Long.compare(this.weight, o.weight);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(br.readLine());
			Vertex[] adjList = new Vertex[N];
			boolean[] visited = new boolean[N];
			long[] minEdge = new long[N];
			long[][] arr = new long[1001][2];
			double tax;
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				arr[i][0] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				arr[i][1] = Integer.parseInt(st.nextToken());
			}
			tax = Double.parseDouble(br.readLine());
			for (int i = 0; i < N - 1; i++) {
				for (int j = 1; j < N; j++) {
					int from = i;
					int to = j;
					long A = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]);
					double B = (Math.abs(arr[i][1] - arr[j][1]) * Math.abs(arr[i][1] - arr[j][1]));
					long weight = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])
							+ (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]);
					adjList[from] = new Vertex(to, weight, adjList[from]);
					adjList[to] = new Vertex(from, weight, adjList[to]);
				}
			}
			PriorityQueue<Vertex> pq = new PriorityQueue<>();
			Arrays.fill(minEdge, Long.MAX_VALUE);
			minEdge[0] = 0;

			pq.offer(new Vertex(0, 0, null));

			long result = 0;
			int c = 0;
			while (!pq.isEmpty()) {
				Vertex minVertex = pq.poll();
				if (visited[minVertex.no])
					continue;

				result += minVertex.weight;
				visited[minVertex.no] = true;
				if (++c == N)
					break;

				for (Vertex temp = adjList[minVertex.no]; temp != null; temp = temp.next) {
					if (!visited[temp.no] && temp.weight < minEdge[temp.no]) {
						minEdge[temp.no] = temp.weight;
						pq.offer(new Vertex(temp.no, minEdge[temp.no], null));
					}
				}
			}
			System.out.printf("#%d %.0f\n", t, result * tax);

		}
	}
}
