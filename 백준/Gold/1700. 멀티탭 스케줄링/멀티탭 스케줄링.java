import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        ArrayList<Integer> hole = new ArrayList<>();
        int []plug = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            plug[i] = Integer.parseInt(st.nextToken());
        }
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            if(hole.contains(plug[i])) continue;
            if(hole.size() < N){ // 구멍 있으면
                hole.add(plug[i]);
            }
            else { // 구멍 없으면
                int target = -1;      // 뽑을 기기 값
                int latest = -1;      // 가장 나중에 다시 쓰이는 위치

                // 현재 멀티탭에 꽂혀 있는 기기들 중 하나를 선택
                for (int d : hole) {
                    int nextIdx = findNext(plug, d, i + 1); // 현재 위치 다음부터 탐색
                    // 앞으로 다시 안 쓰이면 바로 그 기기를 뽑는다
                    if (nextIdx == Integer.MAX_VALUE) {
                        target = d;
                        break;
                    }
                    // 가장 나중에 다시 쓰이는 기기를 후보로
                    if (nextIdx > latest) {
                        latest = nextIdx;
                        target = d;
                    }
                }

                // 선택된 기기를 제거하고 새 기기를 꽂는다
                hole.remove((Integer) target);
                cnt++;
                hole.add(plug[i]);
            }
        }
        System.out.println(cnt);
    }

    private static int findNext(int[] plug, int nowDevice, int start) {
        for(int i =start;i<plug.length;i++){
            if(plug[i] == nowDevice){
                return i;
            }
        }
        return Integer.MAX_VALUE;
    }



    }