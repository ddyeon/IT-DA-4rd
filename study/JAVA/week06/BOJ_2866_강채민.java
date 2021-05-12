import java.util.*;

public class 2866_문자열잘라내기 {

	public static void main(String[] args) {
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week06/BOJ_2866_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 
		 * 팀장님 코드 참고했습니다.
		 * 
		 * 중복이 발견될경우 그 밑에 행은 볼 필요가 없으니까 이분탐색으로 줄여간다는 아이디어.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int R = input.nextInt();
		int C = input.nextInt();
		
		char map[][] = new char[R][C];

		/**
		 * 1. 입력받기
		 */
		for(int r = 0; r < R; r++) {
			
			String S = input.next();
			
			map[r] = S.toCharArray();
		}
		
		/**
		 * 2. list에 열방향으로 넣기
		 */
		
		ArrayList<String> maplist = new ArrayList<>();
		
		for(int i = 0; i < C; i++) {
			
			String putS = "";
			
			for(int j = 0; j < R; j++)
				putS += map[j][i];
			
			maplist.add(putS);
		}
		
		/**
		 * 3. 찾기
		 */
		int count = 0;
		int start = 0;
		int end = R;
		
		HashSet<String> checkSet = new HashSet<String>();
		
		while(start <= end) {
			
			int mid = (start + end) / 2;
			
			//hashset 초기화 시켜주기
			checkSet.clear();
			
			//arraylist에 있는거만큼 돌려준다
			for(int i = 0; i < maplist.size(); i++) {
				
				String checkS = maplist.get(i);
				
				//mid부터 잘라준다.
				checkS = checkS.substring(mid);
				
				//hashset에 넣어서 중복을 확인해준다.
				checkSet.add(checkS);
			}
			
			//중복문자열이 있으면 checkSet에 있는 개수가 열의 개수만큼이 아닐 것
			if(checkSet.size() != C) 
				end = mid - 1;
			
			else {
				
				start = mid + 1;
				count = mid;
			}
				
		}
		
		System.out.println(count);
	}

}
