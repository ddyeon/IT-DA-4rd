import java.util.*;

class Main{
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n, m, k;
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		
		int[] a = new int[n+1];
		int[] dp = new int[n+1];
		
		for (int i = 1; i <= n; i++) {
			a[i] = sc.nextInt();
			
			dp[i] = k*i;
		}
		
		for (int i = 0; i < n; i++) {
			int min, max;
			
			min = a[i+1];
			max = a[i+1];
			 for (int j = 1; j <= m && i+j <= n; j++) {
				 min = Math.min(min, a[i+j]);
				 max = Math.max(max, a[i+j]);
				 
				 dp[i+j] = Math.min(dp[i+j], dp[i]+k+j*(max - min));
			 }
		}
		System.out.println(dp[n]);
		
	}
}
