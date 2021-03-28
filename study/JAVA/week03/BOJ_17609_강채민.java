import java.util.*;

public class 17609_회문 {
	
	static String check_S = "";

	public static void main(String[] args) {
		
		/**
		 * 시간초과로 인해 
		 * 
		 * https://newdeal123.tistory.com/13
		 * 참고했습니다.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int T = input.nextInt();
		
		for(int t = 0; t < T; t++) {
			
			String S = input.next();
			
			if(isPalin(S) == 1) { // 회문이면
				System.out.println(0);
				continue;
			}
			
			check_S = S;
			
			//if(isSimilarPalin(S) == 1) {
			if(isSimilarPalin(0, check_S.length()-1, true) == 1) { // 유사 회문이면
				System.out.println(1);
				//continue;
			}
			
			else { // 회문&유사회문도 아니면
				System.out.println(2);
			}
		}

	}
	
	/**
	 * 백준 1747 소수&팰린드롬 문제에서 가져왔습니다.
	 */
	
	public static int isPalin(String S) { // 회문 확인 함수
		
		StringBuilder sb = new StringBuilder();
		
		sb.append(S);
		
		if(sb.toString().equals(sb.reverse().toString()))
			return 1;
		
		else
			return 0;
	}
	/**
	 * 시간초과로 인해 할 수가 없다.
	 * 문자열을 하나하나 비교하면 시간초과가 나는데 밑에 방법이랑 비슷하지 않나 싶은데.. 잘 모르겠다.
	 */
	/*
	public static int isSimilarPalin(String S) {
		
		for(int i = 0; i < S.length(); i++) {
			
			String check_S = S.substring(0, i) + S.substring(i + 1);
			
			StringBuilder sb = new StringBuilder();
			
			sb.append(check_S);
			
			if(sb.toString().equals(sb.reverse().toString())) {
				return 1;
			}
		}
		
		return 0;
	}
	*/
	
	public static int isSimilarPalin(int left, int right, boolean skip) {
		
		if(left > right)
			return 1;
		
		else if(check_S.charAt(left) == check_S.charAt(right)) { // 문자열이 같으면 
			return isSimilarPalin(left+1, right-1, skip); // 다시 탐색
		}
		
		else if(skip) { // 한개의 문자열을 빼지 않은 상태라면 
			return Math.max(isSimilarPalin(left+1, right, false), 
					isSimilarPalin(left, right-1, false)); // 왼쪽, 오른쪽 둘중 하나의 문자열을 빼서 하나라도 성공하면 유사회문으로 친다.
		}
		
		else
			return 0;
	}

}
