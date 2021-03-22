import java.util.*;

public class 1303_전쟁- {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		/**
		 * 가로가 N이고 세로가 M이였다 ㅎ..
		 * 문제를 잘 읽자 ㅎ...
		 */
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		/*
		String map[][] = new String[N][M];
		int check[][] = new int[N][M];
		*/
		String map[][] = new String[M][N];
		int check[][] = new int[M][N];
		
		for(int m = 0; m < M; m++) {
			
			String S = input.next();
			
			map[m] = S.split("");
		}
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		
		int AnswerW = 0;
		int AnswerB = 0;
		
		//int Wcount = 0;
		//int Bcount = 0;
		
		int move_x[] = {0, 0, 1, -1};
		int move_y[] = {1, -1, 0, 0};
		
		for(int i = 0; i < M; i++) {
			
			for(int j = 0; j < N; j++) {
				
				if(check[i][j] == 1)
					continue;
				
				QX.add(i);
				QY.add(j);
				check[i][j] = 1;
				
				int Wcount = 0;
				int Bcount = 0;
				
				if(map[i][j].equals("W"))
					Wcount++;
				
				else
					Bcount++;
				
				while(!QX.isEmpty()) {
					
					int X = QX.poll();
					int Y = QY.poll();
					
					for(int mx = 0; mx < move_x.length; mx++) {
						
						int go_x = X + move_x[mx];
						int go_y = Y + move_y[mx];
						
						if(go_x < 0 || go_y < 0 || go_x >= M || go_y >= N)
							continue;
						
						if(check[go_x][go_y] == 1 || !map[X][Y].equals(map[go_x][go_y]))
							continue;
						
						QX.add(go_x);
						QY.add(go_y);
						check[go_x][go_y] = 1;
						
						if(map[go_x][go_y].equals("W"))
							Wcount++;
						
						else
							Bcount++;
					}
				}
				
				if(map[i][j].equals("W"))
					AnswerW = (int) (AnswerW + Math.pow(Wcount, 2));
				
				else
					AnswerB = (int) (AnswerB + Math.pow(Bcount, 2));
			}
		}
		
		System.out.println(AnswerW + " " + AnswerB);

	}

}
