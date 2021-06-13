import java.util.*;

public class 16927_2 {

	public static void main(String[] args) {
		
		/**
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week10/BOJ_16927_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		int R = input.nextInt();
		
		int arr[][] = new int[N][M];
		
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++)
				arr[n][m] = input.nextInt();
		}
		
		ArrayList<Integer> Circle_Box = new ArrayList<>();
		
		int rotate_circle = Math.min(N, M) / 2; // 회전해야하는 circle이 몇개인지
		
		for(int r = 0; r < rotate_circle; r++) {
			
			//한 circle에 얼만큼의 box가 있는지 count해준다.
			// 한바퀴당 2개씩 줄어든다. 
			int one_circle_box_count = 2 * (N - (2 * r)) + 2 * (M - (2 * r)) - 4;
			
			Circle_Box.add(one_circle_box_count);
		}
		
		//list의 길이만큼 돈다
		for(int i = 0; i < Circle_Box.size(); i++) {
			
			//몇번 전진해야하는지
			for(int j = 0; j < R % Circle_Box.get(i); j++) {
				
				/**
				 *    ←1번
				 *    #### 
				 * ↓  #### ↑2번
				 * 4번 ####
				 *    ####
				 *    →3번
				 * 
				 * 이렇게 회전할 것이다. 따라서 처음 바퀴의 시작을 temp에 넣어주고 시작한다.
				 */
				
				int tmp = arr[i][i];
				
				//1번
				for(int k = i + 1; k < M - i; k++) 
					arr[i][k - 1] = arr[i][k];
				
				//2번
				for(int k = i + 1; k < N - i; k++)
					arr[k - 1][M - i - 1] = arr[k][M - i - 1];
				
				//3번
				for(int k = M - i - 1; k > i; k--)
					arr[N - i - 1][k] = arr[N - i - 1][k - 1];
				
				//4번
				for(int k = N - i - 1; k > i; k--)
					arr[k][i] = arr[k - 1][i];
				
				arr[i + 1][i] = tmp;
			}
		}
		
		//출력하기
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++)
				System.out.print(arr[n][m] + " ");
			System.out.println();
		}

	}

}
