import java.util.*;

public class 2866_문자열자르기 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);

		int R = input.nextInt();
		int C = input.nextInt();
		
		char map[][] = new char[R][C];
		
		/**
		 * 1. 입력하기
		 */
		for(int r = 0; r < R; r++) {
			
			String S = input.next();
			
			map[r] = S.toCharArray();
		}
		
		int count = 0;
		
		while(true) {
			
			HashSet<String> setS = new HashSet<>();
			
			for(int i = count; i < C; i++) {
				
				String tmpS = "";
				
				for(int j = 0; j < R; j++)
					tmpS += map[j][i];
				
				setS.add(tmpS);
			}
			
			if(setS.size() == C)
				count++;
			
			else
				break;
		}
		
		System.out.println(count - 1);
	}

}
