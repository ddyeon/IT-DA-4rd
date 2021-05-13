import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_13302 {

	static int N;
	static int[][] dp;
	static boolean[][] visited;
	static boolean[] impossible;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		dp = new int[N + 1][61];
		visited = new boolean[N + 1][61];
		impossible = new boolean[N + 1];

		if (M != 0) {
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++) {
				impossible[Integer.parseInt(st.nextToken())] = true;
			}
		}

		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < 61; j++) {
				dp[i][j] = Integer.MAX_VALUE;
			}
		}

		System.out.print(dfs(1, 0));
	}

	static int dfs(int day, int coupon) {
		if (day > N) {
			return 0;
		}
		if (visited[day][coupon]) {
			return dp[day][coupon];
		}
		if (impossible[day]) {
			dp[day][coupon] = dfs(day + 1, coupon);
			return dp[day][coupon];
		}
		if (coupon >= 3) {
			dp[day][coupon] = Math.min(dp[day][coupon], dfs(day + 1, coupon - 3));
		}
		dp[day][coupon] = Math.min(dp[day][coupon], dfs(day + 1, coupon) + 10000);
		dp[day][coupon] = Math.min(dp[day][coupon], dfs(day + 3, coupon + 1) + 25000);
		dp[day][coupon] = Math.min(dp[day][coupon], dfs(day + 5, coupon + 2) + 37000);
		visited[day][coupon] = true;
		return dp[day][coupon];
	}
}
