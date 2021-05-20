import java.util.Scanner;

public class 1965_상자넣기 {
	
	public static void main(String[] args) {
		
		/**
		 * 가장 증가하는 부분수열 문제에서 가져왔습니다.
		 * 
		 * 백준 14002번 참조.
		 * 
		 * LIS관련 참조 : https://mygumi.tistory.com/69
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		int Box[] = new int[N];
		int dp[] = new int[N];
		
		int max_box = 0;
		
		for(int i = 0; i < N; i++) {
			
			Box[i] = input.nextInt();
			
			dp[i] = 1; // 길이는 1로 시작
			
			//i보다 작은수까지 탐색
			for(int j = 0; j < i; j++) {
				
				//1. 기본적으로 Box[j]값이 Box[i]값보다 작아야하고
				//2. dp[i]번째가 작은수로 갱신되는것을 막고자 조건문 추가.
				if(Box[j] < Box[i] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
				
				max_box = Math.max(max_box, dp[i]);
			}
		}
		
		System.out.println(max_box);

	}

}
