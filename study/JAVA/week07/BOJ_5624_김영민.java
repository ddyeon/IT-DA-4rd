import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class BOJ_5624 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		int[] arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int answer = 0;
		Set<Integer> set = new HashSet<>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (set.contains(arr[i] - arr[j])) {
					answer++;
					break;
				}
			}
			for (int j = 0; j <= i; j++) {
				set.add(arr[i] + arr[j]);
			}
		}
		System.out.print(answer);
	}
}
