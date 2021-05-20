import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_2011 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] arr = br.readLine().toCharArray();

		if (arr[0] == '0') {
			System.out.print(0);
			return;
		}

		int[] dp = new int[arr.length + 1];
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= arr.length; i++) {
			int num = Character.getNumericValue(arr[i - 1]);
			if (1 <= num && num <= 9) {
				dp[i] = dp[i - 1] % 1000000;
			}
			num = Character.getNumericValue(arr[i - 2]) * 10 + Character.getNumericValue(arr[i - 1]);
			if (10 <= num && num <= 26) {
				dp[i] = (dp[i - 2] + dp[i]) % 1000000;
			}
		}
		System.out.print(dp[dp.length - 1]);
	}
}
