import java.util.Scanner;

public class 2806_DNA발견 {
	
	public static void main(String[] args) {
		
		/**
		 * 문제 이해에 조금 오래걸렸다
		 * https://boomrabbit.tistory.com/91
		 * 참고했습니다.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		String S = input.next();
		
		int dp[][] = new int[2][N];
		
		/**
		 * 아 dp를 모두 최대값으로 초기화시켜줘야한다...
		 */
		for(int d = 0; d < N; d++) {
			dp[0][d] = Integer.MAX_VALUE;
			dp[1][d] = Integer.MAX_VALUE;
		}
		
		/**
		 * dp[0]이 A로 만드는 경우이고 dp[1]은 B로 만드는 경우이다.
		 * 
		 * 따라서 첫글자가 A인경우 한글자 바꿔 B로 될 수 있기 때문에 dp[0][1]에 1을 넣어준다.
		 * 마찬가지로 B의 경우도 dp[0][0]이 1이 된다.
		 */
		if(S.charAt(0) == 'A') {
			dp[0][0] = 0;
			dp[1][0] = 1;
		}
			
		
		else {
			dp[0][0] = 1;
			dp[1][0] = 0;
		}
			
		
		/**
		 * i번째 글자가 A일 경우
		 * 
		 * 1. A를 A로 만드는 경우
		 * 2. A를 B로 바꾸는 경우
		 * 
		 * 두가지가 있게된다.
		 */
		
		for(int i = 1; i < N; i++) {
			
			if(S.charAt(i) == 'A') {
				
				//1. A to A
				dp[0][i] = Math.min(dp[1][i - 1] + 1, dp[0][i - 1]); 
				
				//2. A to B
				dp[1][i] = Math.min(dp[1][i - 1] + 1, dp[0][i - 1] + 1);
			}
			
			else {
				
				//1. B to B
				dp[1][i] = Math.min(dp[1][i - 1], dp[0][i - 1] + 1);
				
				//2. B to A
				dp[0][i] = Math.min(dp[1][i - 1] + 1, dp[0][i - 1] + 1);
			}
		}
		
		/**
		 * A의 경우와 B의 경우에서 반전되는 경우 중 최소값
		 */
		System.out.println(Math.min(dp[0][N - 1], dp[1][N - 1] + 1));

	}

}
