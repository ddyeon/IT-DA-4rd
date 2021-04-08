import java.util.*;

public class 17392_채민 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		for(int n = 0; n < N; n++) {
			
			int H = input.nextInt();
			
			M -= H + 1;
		}
		
		int sad = 0;
		
		/*
		if(M > 0) {
			
			int q = M / (N+1);
			int r = M % (N+1);
			
			for(int i = 0; i < r; i++) {
				sad += Math.pow(q+1, 2);
			}
			
			for(int j = 0; j < (N+1) - r; j++) {
				sad += Math.pow(q, 2);
			}
		}
		
		System.out.println(sad);
		*/
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/abd953cc630e1f79ed4076d0c7a7b8f6955769f9/study/Python/week03/BOJ_17392_%EA%B0%95%EC%9D%98%ED%98%84.py
		 * 참고했습니다!
		 */
		
		if(M > 0) {
			
			int q = M / (N+1);
			int r = M % (N+1);
			
			for(int i = 0; i < r; i++) {
				sad += Math.pow(q+1, 2);
			}
			
			for(int j = 0; j < q; j++) {
				sad += Math.pow(j+1, 2) * (N+1);
			}
		}
		
		System.out.println(sad);

	}

}
