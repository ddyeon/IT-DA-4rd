import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_17392 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int answer = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			int H = Integer.parseInt(st.nextToken());
			M -= (H + 1);
		}

		if (M <= 0) {
			System.out.print("0");
			return;
		}

		int q = M / (N + 1);
		int r = M % (N + 1);
		answer += (((q + 1) * (q + 1 + 1) * (2 * q + 2 + 1)) / 6) * r;
		answer += ((q * (q + 1) * (2 * q + 1)) / 6) * (N + 1 - r);
		System.out.print(answer);
	}
}