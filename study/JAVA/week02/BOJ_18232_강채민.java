import java.io.*;
import java.util.*;

public class 18232_텔레포트정거장 {
	
	public static void main(String[] args) throws Exception {
		
		/**
		 * 처음에 메모리 초과가 나서 BufferedReader를 안써서 그런줄 알고 고쳤지만
		 * 
		 * 결국 check배열을 써주지 않아서 ㅎ...
		 */
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int S = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer> Teleport[] = new ArrayList[N+1];
		
		/**
		 * check..?
		 */
		int check[] = new int[N+1];
		
		for(int n = 0; n <= N; n++) 
			Teleport[n] = new ArrayList();
		
		
		for(int m = 0; m < M; m++) {
			
			st = new StringTokenizer(br.readLine());
			
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			Teleport[x].add(y);
			Teleport[y].add(x);
		}
		
		Queue<Integer> Station = new LinkedList<>();
		Queue<Integer> Count = new LinkedList<>();
		
		Station.add(S);
		Count.add(0);
		
		check[S] = 1;
		
		while(!Station.isEmpty()) {
			
			int station = Station.poll();
			int count = Count.poll();
			
			if(station == E) {
				System.out.println(count);
				return;
			}
			
			if(station > 1 && check[station-1] == 0) {
				
				Station.add(station-1);
				Count.add(count+1);
				check[station-1] = 1;
			}
			
			if(station < N && check[station+1] == 0) {
				
				Station.add(station+1);
				Count.add(count+1);
				check[station+1] = 1;
			}
			
			for(int j = 0; j < Teleport[station].size(); j++) {
				
				if(check[Teleport[station].get(j)] == 0) {
					
					Station.add(Teleport[station].get(j));
					Count.add(count+1);
					check[Teleport[station].get(j)] = 1;
				}
			}
			
		}
		
		System.out.println(-1);
	}

}
