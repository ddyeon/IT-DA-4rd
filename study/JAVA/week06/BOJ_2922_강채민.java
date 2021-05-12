import java.util.Scanner;

public class 2922_즐거운단어 {
	
	/**
	 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week06/BOJ_2922_%EA%B9%80%EC%98%81%EB%AF%BC.java
	 * 팀장님 코드 참고했씁니다
	 * 
	 * dfs로 탐색
	 */
	
	static char word[];

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		String S = input.next();
		
		word = S.toCharArray();
		
		//index, 모음, 자음, l의 여부
		long answer = dfs(0, 0, 0, false);
		
		System.out.println(answer);

	}

	private static long dfs(int index, int mo, int ja, boolean check_L) {
		
		long result = 0;
		
		//1. 모음이랑 자음 개수가 3개 이상인지 보기
		if(mo >= 3 || ja >= 3)
			return 0;
		
		/**
		 * 아하
		 */
		if(index == word.length) {
			
			if(check_L)
				return 1;
			
			else
				return 0;
		}
		
		if(word[index] == '_') {
			
			//자음 넣기
			result += 5 * (dfs(index + 1, mo + 1, 0, check_L));
			result += 20 * (dfs(index + 1, 0, ja + 1, check_L));
			result += dfs(index + 1, 0, ja + 1, true);
		}
		
		else {
			
			//모음(A,E,I,O,U)
			if(word[index] == 'A' || word[index] == 'E' || word[index] == 'I'
					|| word[index] == 'O' || word[index] == 'U')
				result = dfs(index + 1, mo + 1, 0, check_L);
			
			//자음
			else {
				
				//L이 포함되어있는지 
				if(word[index] == 'L')
					result = dfs(index + 1, 0, ja + 1, true);
				
				else
					result = dfs(index + 1, 0, ja + 1, check_L);
			}
		}
		
		return result;
		
	}

}
