import java.util.*;

public class 10476_좁은미술전사관 {
	
	static int Art_Exhi[][];
	static int N;
	static int K;
	
	static int tmp_art[][];
	
	static int allValue = 0;
	
	static int moveX[] = {1, -1, 0, 0};
	static int moveY[] = {0, 0, 1, -1};
	
	static ArrayList<Integer> answer = new ArrayList<>();

	public static void main(String[] args) {
		
		/**
		 * 벽을 세우는 모든 경우의 수를 dfs로 찾은다음에
		 * 해당 경우가 출구로 통과가 가능한지 -> 가능하면 그것의 가치는 얼마인지
		 * 
		 * 답이 가능한 가치의 합들을 ArrayList에 저장해서 그것의 최대값을 출력하도록 할려고 했지만
		 * 안되네요 
		 */
		
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		K = input.nextInt();
		
		Art_Exhi = new int[N][2];
		tmp_art = new int[N][2];

		/**
		 * 미술전시관 입력받기
		 */
		
		
		for(int n = 0; n < N; n++) {
			for(int n2 = 0; n2 < 2; n2++) {
				Art_Exhi[n][n2] = input.nextInt();
				
				allValue += Art_Exhi[n][n2];
			}
				
		}
		
		/**
		 * ??
		 */
		int zero1 = input.nextInt();
		int zero2 = input.nextInt();
		
		/**
		 * 1. dfs로 가치 넣기?
		 */
		dfs(0, 0);
		
		System.out.println(Collections.max(answer));
	}
	
	public static void dfs(int count, int closeValue) {
		
		if(count == K) {
			
			/**
			 * tmp배열에다가 현재 미술전시관 상태 복사하기
			 */
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < 2; j++)
					tmp_art[i][j] = Art_Exhi[i][j];
			}
			
			System.out.println("closeValue " + closeValue);
			int sumValue = allValue - closeValue;
			bfs(sumValue);
			return;
		}
		
		/**
		 * 방을 하나씩 닫기
		 */
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 2; j++) {
				
				int tmp = Art_Exhi[i][j];
				Art_Exhi[i][j] = -1; // 닫아버리기
				
				count += 1;
				closeValue += tmp;
				
				dfs(count, closeValue);
				
				Art_Exhi[i][j] = tmp; // 다시 가치 넣기
				
				count -= 1; // 다시 전상태로 복귀
				closeValue -= tmp;
			}
		}
	}
	
	public static void bfs(int sumValue) {
		
		/**
		 * 입구를 다 큐에 넣어준다.
		 */
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		
		int check_bfs[][] = new int[N][2];
		
		for(int i = 0; i < 2; i++) {
			
			if(tmp_art[0][i] != -1) {
				
				QX.add(0);
				QY.add(i);
				
				check_bfs[0][i] = 1;
				
				break;
			}
		}
		
		while(!QX.isEmpty()) {
			
			int X = QX.poll();
			int Y = QY.poll();
			
			if(X == N-1)
				break;
			
			for(int mx = 0; mx < moveX.length; mx++) {
				
				int goX = X + moveX[mx];
				int goY = Y + moveY[mx];
				
				//범위 벗어나면
				if(goX < 0 || goY < 0 || goX >= N || goY >= 2)
					continue;
				
				//벽이라면, 갔던곳이라면
				if(tmp_art[goX][goY] == -1 || check_bfs[goX][goY] == 1)
					continue;
				
				QX.add(goX);
				QY.add(goY);
				check_bfs[goX][goY] = 1;
			}
		}
		
		/*
		if(check_bfs[N-1][0] != 1 && check_bfs[N-1][1] != 1) 
			return;
		
		
		else {
			answer.add(sumValue);
			return;
		}
		*/
		
		if(check_bfs[N-1][0] == 1 || check_bfs[N-1][1] == 1) 	
			answer.add(sumValue);
	}

}
