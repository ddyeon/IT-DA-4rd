import java.util.*;

public class 8972_Crazy_Arduino {
	
	static int IX = 0;
	static int IY = 0;
	
	//
	static int move_x[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
	static int move_y[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int R = input.nextInt();
		int C = input.nextInt();
		
		char map[][] = new char[R][C];
		
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
			
			int go_x = IX + move_x[mx];
			int go_y = IY + move_y[mx];
			
			if(map[go_x][go_y] == 'R') {
				
				System.out.println("kraj " + i);
				return;
			}
			
			int Qsize = QX.size();
			
			for(int q = 0; q < Qsize; q++) {
				
				int X = QX.poll();
				int Y = QY.poll();
				
				//폭파해서 그 자리가 .이라면 continue 해줘야한다(?)
				//폭파한걸 어떻게 처리해주지?
				if(map[X][Y] != 'R')
					continue;
				
				int close_direction = 0;
				int close_distance = 0;
				
				//8방향으로 움직여야해
				for(int n = 1; n <= 8; n++) {
					
					int go_gx = X + move_x[n];
					int go_gy = Y + move_y[n];
					
					/**
					 * 일단 8방향중에 제일 가까운걸 찾아야한다.
					 */
					
					if(go_gx < 0 || go_gy < 0 || go_gx >= R || go_gy >= C)
						continue;
					
					int go_distance = Math.abs(X - go_gx) + Math.abs(Y - go_gy);
					
					//거리가 더 짧다면 최소 거리를 수정해주고
					// 방향을 해당 방향으로 바꿔주기
					if(go_distance < close_distance) {
						
						close_distance = go_distance;
						close_direction = n;
					}
					
					
				}
				
				/**
				 * 8방향이 다 끝난 다음에 움직이기.
				 */
				
				int next_x = X + move_x[close_direction];
				int next_y = Y + move_y[close_direction];
				
				/**
				 * 1. 최소거리로 움직이는 곳에 I가 있는지 확인
				 * 2. 이미 R이 있다면 폭파하기..
				 */
				if(map[next_x][next_y] == 'I') {
					
					System.out.println("kraj " + i);
					return;
				}
				
				if(map[next_x][next_y] == 'R')
					continue;
				
				QX.add(next_x);
				QY.add(next_y);
			}
		}
		
		/**
		 * 상태를.. 출력하기?
		 * 
		 */
		
		for(int i = 0; i < R; i++) {
			
			for(int j = 0; j < C; j++) 
				map[i][j] = '.';
		}
		
		map[IX][IY] = 'I';
		
		while(!QX.isEmpty()) {
			
			int X = QX.poll();
			int Y = QY.poll();
			
			map[X][Y] = 'R';
		}
		
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) 
				System.out.print(map[i][j] + " ");
			System.out.println();
		}
		
		/**
		 * 처음에 R의 좌표를 다 arraylist에 저장을 할까 
		 * 
		 * 그러면 while(true)이렇게 해놓고 시간이 흘러가면서 
		 * 
		 * I의 좌표를 계산하고 
		 * 
		 * R의 좌표를 arraylist에 넣어두자. 
		 */

	}

}
