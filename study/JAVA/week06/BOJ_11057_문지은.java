import java.util.*;

public class Main{
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[][] dp = new int[n+1][11];
		
		for (int i = 0; i <= 9; i++) {
			dp[1][i] = 1;		//일의 자리수는 1개씩
		}
		
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = j; k <= 9; k++) {
					//dp[i][k] i 자리수, 제일 높은 자리수가 9-k
					dp[i][k] += dp[i-1][j];
					dp[i][k] %= 10007;
				}
				
			}
		}
		
		int sum = 0;
		for (int i = 0; i <= 9; i++) {
			sum += dp[n][i];
		}
		System.out.println(sum%10007);
		
		
		
		
		
	}
}
