import java.util.Scanner;

public class 5624_좋은수 {
	
	public static void main(String[] args) {
		
		/**
		 * https://jaimemin.tistory.com/876
		 * 참고했습니다.
		 * 
		 * DP인거같으면서 DP같지 않은 문제..?
		 * 
		 * 배열[i] - 배열[j]까지는 생각했지만 그 이후는 조금 어려웠던..
		 * 2번을 구현할 생각을 하지 못했다.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		int seyoul[] = new int[N];
		
		/**
		 * 수열 A의 각 숫자가 공백으로 구분되어 주어진다. (-100,000 ≤ Ai ≤ 100,000)
		 * 마이너스 숫자가 나올 수 있기 때문에 범위를 400,000으로 해줘야한다.
		 */
		int dp[] = new int[400001];
		
		for(int n = 0; n < N; n++)
			seyoul[n] = input.nextInt();
		
		int answer = 0;
		
		for(int i = 0; i < N; i++) {
			
			//1. 탐색하기
			for(int j = 0; j < i; j++) {
				
				if(dp[seyoul[i] - seyoul[j] + 200000] == 1) {
					
					answer++;
					
					break;
				}
			}
			
			//2. 더해주기
			for(int j = 0; j <= i; j++)
				dp[seyoul[i] + seyoul[j] + 200000] = 1;
		}
		
		System.out.println(answer);

	}

}
