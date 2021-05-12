import java.util.Scanner;

public class 11057_오르막수 {

	public static void main(String[] args) {
		
		/**
		 * 예전 기수에서 풀었던 문제!
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		int Ascending [][] = new int [N + 1][10];
		
		for(int i = 0; i < 10; i++)
			Ascending[1][i] = 1;
		
		for(int i = 2; i <= N; i++) {
			
			for(int j = 0; j <= 9; j++) {
				
				for(int k = 0; k <= j; k++)
					Ascending[i][j] = Ascending[i][j] + Ascending[i-1][k];
				
				Ascending[i][j] = Ascending[i][j] % 1007;
			}
		}
		
		int sum = 0;
		
		for(int a = 0; a <= 9; a++)
			sum = sum + Ascending[N][a];
		
		System.out.println(sum % 10007);
	}

}
