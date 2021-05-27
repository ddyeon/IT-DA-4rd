import java.util.*;

public class 10836_여왕벌 {

	public static void main(String[] args) {
		
		/**
		 * 시간초과납니다.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int M = input.nextInt();
		
		int N = input.nextInt();
		
		int bee[][] = new int[M][M];
		
		int top_bee[] = new int[2*M - 1];
		
		//Arrays.fill(top_bee, 1);
		
		for(int n = 0; n < N; n++) {
			
			int zero = input.nextInt();
			int one = input.nextInt();
			int two = input.nextInt();
			
			for(int i = zero; i < zero + one; i++)
				top_bee[i] += 1;
			
			for(int i = zero + one ; i < (2 * M - 1); i++)
				top_bee[i] += 2;
		}
		
		/**
		 * 채워넣기
		 */
		for(int i = 0; i < M; i++) {
			
			for(int j = 0; j < M; j++) {
				
				if(j == 0)
					bee[i][j] = top_bee[M - i - 1]; // 90도 회전
				
				else {
					
					if(i == 0)
						bee[i][j] = top_bee[M + j - 1];
					
					else {
						int max = Math.max(bee[i][j - 1], Math.max(bee[i - 1][j - 1], bee[i - 1][j]));
						
						bee[i][j] = Math.max(max, bee[i][j]);
					}
						
				}
				
				System.out.print(bee[i][j] + 1 + " ");
			}
			
			System.out.println();
		}
		
		/*
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < M; j++) 
				System.out.print(bee[i][j] + 1 + " ");
			System.out.println();
		}
		*/
		
	}

}
