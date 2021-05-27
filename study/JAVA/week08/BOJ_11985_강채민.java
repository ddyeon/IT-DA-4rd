import java.util.Scanner;

public class 11985_오렌지출하 {
	
	public static void main(String[] args) {
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week08/BOJ_11985_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 참고했습니다 
		 * 
		 * dp는 역시 복잡하다 ㅜㅜ
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		int K = input.nextInt();
		
		long orange[] = new long[N + 1];
		long dp[] = new long[N + 1];
		
		/**
		 * 오렌지 입력받기
		 */
		for(int i = 1; i <= N; i++) {
			
			orange[i] = input.nextInt();
			
			//포장의 최대값은 오렌지를 모두 개별포장하는 방법이다.
			dp[i] = K * i;
		}
		
		for(int i = 2; i <= N; i++) {
			
			long min = orange[i];
			long max = orange[i];
			
			for(int j = 1; j <= M && i - j >= 0; j++) {
				
				min = Math.min(min, orange[i - j + 1]);
				max = Math.max(max, orange[i - j + 1]);
				
				dp[i] = Math.min(dp[i], dp[i - j] + K + j * (max - min));
			}
		}
		
		System.out.println(dp[N]);

	}

}
