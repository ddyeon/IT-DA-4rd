
import java.util.*;

class Main{
	
	public static void main(String[] args) {
		
		int[][][] dp = new int[101][101][101];
		
		Scanner sc = new Scanner(System.in);
		
		int ri, rj, rk;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				for (int k = 0; k <= 100; k++) {
					ri = i - 50;
					rj = j - 50;
					rk = k - 50;
					
					if (ri <= 0 || rj <= 0 || rk <= 0) {
						dp[i][j][k] = 1;
						continue;
					}
					if (ri > 20 || rj > 20 || rk > 20) {
						dp[i][j][k] = dp[70][70][70];
						continue;
					}
					if (ri < rj && rj < rk) {
						dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
						continue;
					}
					dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
				}
			}
		}
		
		int a, b, c;
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		while (true) {
			if (a == -1 && b == -1 && c == -1) return;
			
			System.out.println("w("+a+", "+b+", "+c+") = "+dp[a+50][b+50][c+50]);		
			
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
		}
		
		
	}
}
