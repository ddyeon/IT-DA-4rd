import java.util.*;

public class 12915_대회개최 {

	public static void main(String[] args) {
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week04/BOJ_12915_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 구글링을 해봐도 팀장님 코드가 젤로 쉬운거같아요!
		 */
		
		Scanner input = new Scanner(System.in);
		
		int E = input.nextInt();
		int EM = input.nextInt();
		int M = input.nextInt();
		int MH = input.nextInt();
		int H = input.nextInt();
		
		int answer = 0;
		
		while(true) {
			
			if(E <= 0) {
				if(EM > 0) {
					EM--;
					E++;
				}
			}
			
			if(H <= 0) {
				if(MH > 0) {
					MH--;
					H++;
				}
			}
			
			if(M <= 0) {
				
				if(EM >= MH) {
					if(EM > 0) {
						EM--;
						M++;
					}
				}
				
				else {
					if(MH > 0) {
						MH--;
						M++;
					}
				}
			}
			
			if(E > 0 && M > 0 && H > 0) {
				
				answer++;
				
				E--;
				M--;
				H--;
			}
			
			else
				break;
		}
		
		System.out.println(answer);
	}

}
