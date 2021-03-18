import java.util.*;

public class 9466_텀프로젝트 {

	static int N;
	static int pick[];
	static int check[];
	static int cycle[];
	static int count;

	public static void main(String[] args) {
		
		/**
		 * https://jaimemin.tistory.com/674
		 * 
		 * DFS일거 같았는데 시간초과가 날거같아서 좀 헤맸다..
		 * 배열을 하나 더 만든다는게 신기하다.. (cycle을 찾는 배열)
		 */
		
		Scanner input = new Scanner(System.in);
		
		int T = input.nextInt();
		
		for(int t = 0; t < T; t++) {
			
			N = input.nextInt();
			
			pick = new int[N+1];
			check = new int[N+1];
			cycle = new int[N+1];
			
			count = 0; // count 개수 초기화
			
			/**
			 * 번호순서대로 짝궁 선택한거 넣어주기.
			 */
			for(int n = 1; n <= N; n++)
				pick[n] = input.nextInt();
			
			/**
			 * 1번부터 차례대로 dfs 돌기.
			 */
			for(int i = 1; i <= N; i++) {
				
				if(check[i] != 1)
					dfs(i);
			}
			
			System.out.println(N - count);
		}

	}
	
	public static void dfs(int node) {
		
		check[node] = 1;
		
		int next = pick[node];
		
		if(check[next] != 1) 
			dfs(next);
		
		else if(cycle[next] != 1) {
			
			for(int i = next; i != node; i = pick[i]) 
				count++;
			
			count++;
		}
		
		cycle[node] = 1;
	}

}
