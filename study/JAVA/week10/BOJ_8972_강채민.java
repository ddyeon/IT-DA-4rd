import java.util.*;

public class 8972_Crazy_Arduino {
	
	static int IX = 0;
	static int IY = 0;
	
	// 9방향 움직임
	static int move_x[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
	static int move_y[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
	
	static int result = 0;
	
	static char map[][];

	public static void main(String[] args) {
		
		/**
		 * 아니 5일때는 자기 자리에만 그대로 있으니까 답을 증가안하는거 아니야..?
		 * 아무튼 이거때문에 오래걸렸네...
		 * 
		 * 폭탄 터트리기는 영민오빠 코드 참고했습니다 
		 * 감사합니다.
		 */
		Scanner input = new Scanner(System.in);
		
		int R = input.nextInt();
		int C = input.nextInt();
		
		map = new char[R][C];
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		
		/**
		 * 1. 일단 R의 좌표는 Queue에다가 다 넣고
		 * I좌표는 static변수에다가 넣기  
		 */
		
		for(int r = 0; r < R; r++) {
			
			String S = input.next();
			
			map[r] = S.toCharArray();
			
			for(int c = 0; c < C; c++) {
				
				if(map[r][c] == 'I') {
					
					IX = r;
					IY = c;
				}
				
				else if(map[r][c] == 'R') {
					
					QX.add(r);
					QY.add(c);
				}
			}
		}
		
		//I의 움직임 받기
		String S = input.next();
		
		for(int i = 0; i < S.length(); i++) {
			
			int mx = S.charAt(i) - '0';
			
			if(!move(mx)) {
				System.out.println("kraj " + result);
				return;
			}
			
			/*
			 * 5일때도 count해줘야한다고 함 문제에서 설명이 부족했었든듯
			if(mx != 5) {
				
				if(!move(mx)) {
					System.out.println("kraj " + result);
					return;
				}
			}
			*/
			
			int Qsize = QX.size();
			
			//폭파 R담을 배열
			int count[][] = new int[R][C];
			
			for(int q = 0; q < Qsize; q++) {
				
				int X = QX.poll();
				int Y = QY.poll();
				map[X][Y] = '.'; // R의자리 미리 .으로 바꿔줘야한다!
				
				int close_direction = 0;
				int close_distance = Integer.MAX_VALUE;
				
				//8방향으로 움직여야해
				for(int n = 1; n <= 9; n++) {
					
					//이걸 안하면 걸리나?
					if(n == 5)
						continue;
					
					int go_Rx = X + move_x[n];
					int go_Ry = Y + move_y[n];
					
					/**
					 * 일단 8방향중에 제일 가까운걸 찾아야한다.
					 */
					
					if(go_Rx >= 0 && go_Ry >= 0 && go_Rx < R && go_Ry < C) {
						
						int go_distance = Math.abs(IX - go_Rx) + Math.abs(IY - go_Ry);
						
						//거리가 더 짧다면 최소 거리를 수정해주고
						// 방향을 해당 방향으로 바꿔주기
						if(go_distance < close_distance) {
							
							close_distance = go_distance;
							close_direction = n;
						}
					}
					
				}
				
				
				/**
				 * 8방향이 다 끝난 다음에 움직이기.
				 */
				
				int next_x = X + move_x[close_direction];
				int next_y = Y + move_y[close_direction];
				
				/**
				 * 1. 최소거리로 움직이는 곳에 I가 있는지 확인
				 */
				if(map[next_x][next_y] == 'I') {
					
					System.out.println("kraj " + result);
					return;
				}
				
				/**
				 * 2. count배열에다가 R의 개수 늘려주기!
				 */
				else
					count[next_x][next_y]++;
				
				
				
			}
			
			/**
			 * 한바퀴의 Queue가 끝나고 나면
			 * count배열을 탐색하면서 개수가 1인거만 Queue에 다시 담으면 된다
			 */
			for(int r = 0; r < R; r++) {
				
				for(int c = 0; c < C; c++) {
					
					if(count[r][c] == 1) {
						
						QX.add(r);
						QY.add(c);
						map[r][c] = 'R';
					}
				}
			}
		}
		
		/**
		 * 상태를.. 출력하기?
		 * 
		 * 하 아니 map[i][j] + " "이렇게 출력해서 틀렸었음 
		 * 너무 화가남 호호
		 * 
		 */
		
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) 
				System.out.print(map[i][j]);
			System.out.println();
		}

	}
	
	static boolean move(int direction) {
		
		result++;
		
		map[IX][IY] = '.';
		
		IX += move_x[direction];
		IY += move_y[direction];
		
		if(map[IX][IY] == 'R')
			return false;
		
		map[IX][IY] = 'I';
		
		return true;
	}

}
