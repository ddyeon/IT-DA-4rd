import java.util.*;

public class 13302_리조트 {
	
	static int Resort[][];
	static int N;
	static int rest[];

	public static void main(String[] args) {
		
		/**
		 * dp와 dfs를 합해서 
		 * 
		 * https://yabmoons.tistory.com/405
		 * 참고했습니다.
		 */
		
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		int M = input.nextInt();
		
		rest = new int[N + 1];
		
		Resort = new int[N+1][N+1];
		
		//최대값으로 초기화
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= N; j++)
				Resort[i][j] = (int) 1e9;
		}
		
		//쉬는날 입력받기
		for(int m = 0; m < M; m++)
			rest[input.nextInt()] = 1;
		
		System.out.println(dfs(1, 0));
	}

	private static int dfs(int index, int coupon) {

		if(index > N)
			return 0;
		
		if(Resort[index][coupon] != (int)1e9)
			return Resort[index][coupon];
		
		//쉬는날이라면
		if(rest[index] == 1) {
			
			Resort[index][coupon] = Math.min(Resort[index][coupon], dfs(index + 1, coupon));
			
			return Resort[index][coupon];
		}
		
		//차례로 3일, 5일, 1일이다
		Resort[index][coupon] = Math.min(Resort[index][coupon], dfs(index + 3, coupon + 1) + 25000);
		Resort[index][coupon] = Math.min(Resort[index][coupon], dfs(index + 5, coupon + 2) + 37000);
		Resort[index][coupon] = Math.min(Resort[index][coupon], dfs(index + 1, coupon) + 10000);
		
		if(coupon >= 3) {
			
			Resort[index][coupon] = Math.min(Resort[index][coupon], dfs(index + 1, coupon - 3));
		}
		
		return Resort[index][coupon];
	}

}
