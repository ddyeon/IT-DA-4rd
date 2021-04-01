import java.util.*;

public class 15922_아우으 {

	public static void main(String[] args) {
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/165b1f3eb6810480140f2dccba74d07b819b69e9/study/Python/week03/BOJ_15922_%EA%B9%80%EB%AF%BC%EC%84%A0.py
		 * 참고했습니다. (파이썬팀원분 정말 감사합니다...)
		 * 
		 * https://kimcodingvv.github.io/BOJ-15922/
		 * 참고.
		 * 
		 * 문제 이해하는데 시간이 꽤 오래걸렸다.. 아직도 잘 모르겠음..
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		int answer = 0;
		int Aw_x = Integer.MIN_VALUE;
		int Aw_y = Integer.MIN_VALUE;
		
		for(int n = 0; n < N; n++) {
			
			int x = input.nextInt();
			int y = input.nextInt();
			
			if(x > Aw_y) {
				answer = answer + (Aw_y - Aw_x);
				Aw_x = x;
				Aw_y = y;
			}
			
			else {
				//Aw_x = Math.min(Aw_x, x);
				//입력이 어차피 x좌표가 작은순서대로 입력이 되기 때문에 이건 고려해야할 필요가 없다.
				Aw_y = Math.max(Aw_y, y);
			}
		}
		
		//
		answer = answer + (Aw_y - Aw_x);
		
		System.out.println(answer);

	}

}
