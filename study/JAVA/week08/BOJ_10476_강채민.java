import java.util.*;

public class 10476_좁은미술전시관 {

	public static void main(String[] args) {
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week08/BOJ_10476_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 영민님 설명이 없었으면 못풀었을겁니다...
		 * 감사합니다.. 천재가 확실합니다. 영민님은.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int K = input.nextInt();
		
		//
		int Art[][] = new int[N + 1][2];
		
		/**
		 * 1열부터 시작한다고 가정해서 N + 1
		 * K개까지 닫을 수 있어서 K + 1 (0개 ~ K개)
		 * 0: 왼쪽 닫기
		 * 1: 오른쪽 닫기
		 * 2: 오른쪽 왼쪽 둘다 열기
		 * 
		 * 예시: dp[1][1][0]: 1열에서 1개를 닫을건데 0(왼쪽)을 닫기
		 */
		
		int dp[][][] = new int[N + 1][K + 1][3];
		
		int total_art_sum = 0;
		
		for(int i = 1; i <= N; i++) {
			
			for(int j = 0; j < 2; j++) {
				
				Art[i][j] = input.nextInt();
				
				total_art_sum += Art[i][j];
			}
		}
		
		int zero1 = input.nextInt();
		int zero2 = input.nextInt();
		
		/**
		 * 만약에 닫아야 하는 개수 K가 0개이면 바로 total_art_sum 출력하고 끝내기
		 */
		if(K == 0) {
			System.out.println(total_art_sum);
			return;
		}
		
		/**
		 * 일단 1열에서 오른쪽닫고, 왼쪽닫고, 둘다 안닫는 경우를 초기화 시켜주기
		 */
		//1. 1열의 1개를 닫는데 왼쪽을 닫기 -> 이건 오른쪽방의 가치가 들어감
		dp[1][1][0] = Art[1][1];
		//2. 1열의 1개를 닫는데 오른쪽을 닫기 -> 이건 왼쪽 방의 가치가 들어감
		dp[1][1][1] = Art[1][0];
		//3. 1열의 (아무것도 닫지 않아야함) 그래야 두 방을 다 열 수 있어 -> 오른쪽, 왼쪽 방의 합
		dp[1][0][2] = Art[1][1] + Art[1][0];
		
		/**
		 * 2열부터 시작된다.
		 */
		for(int i = 2; i <= N; i++) {
			
			//일단 i번째열까지 아무것도 닫지 않았을때가 가치가 최대값이다. 
			dp[i][0][2] = dp[i - 1][0][2] + Art[i][0] + Art[i][1];
			
			/**
			 * j = 닫을 방의 개수. 
			 * j <= i는 i번째열까지 왔을때 i번째보다 더 많이 닫을 필요가 없기 때문
			 * i개보다 더 많이 닫을경우 출구로 나가지 못함..
			 */
			for(int j = 1; j <= K && j <= i; j++) {
				
				//1. i열의 j개를 닫는데 왼쪽을 닫을 경우
				dp[i][j][0] = Math.max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + Art[i][1];
				//2. i열의 j개를 닫는데 오른쪽을 닫을 경우
				dp[i][j][1] = Math.max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + Art[i][0];
				
				//i랑 j가 같게 된다면  j개만큼 닫는데 i번째열의 방 2개가 살아있을 수 없다.
				if(i != j) {
					// i-1번째 열에서 왼쪽닫기, 오른쪽 닫기, 둘다 열기 중에서 최대값을 골라
					// 그걸 i번째 열의 두 방과 합쳐준다.
					dp[i][j][2] = Math.max(dp[i - 1][j][0], Math.max(dp[i-1][j][1], dp[i-1][j][2]))
									+ Art[i][0] + Art[i][1];
				}
				
			}
		}
		
		//왼쪽, 오른쪽, 둘다 여는거 중에서 제일 최대값을 출력한다.
		System.out.println(Math.max(dp[N][K][0], Math.max(dp[N][K][1], dp[N][K][2])));

	}

}
