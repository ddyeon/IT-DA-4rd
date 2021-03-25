import java.util.*;

public class BFS_16197_두코인 {
	
	static int N;
	static int M;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		M = input.nextInt();
		
		String map[][] = new String[N][M];
		
		
		Queue<Integer> OneX = new LinkedList<>();
		Queue<Integer> OneY = new LinkedList<>();
		
		Queue<Integer> TwoX = new LinkedList<>();
		Queue<Integer> TwoY = new LinkedList<>();
		
		Queue<Integer> Count = new LinkedList<>();
		
		//처음 스타트 위치를 넣어줄 ArrayList
		ArrayList<Integer> CoinLocation = new ArrayList<>();
		
		for(int n = 0; n < N; n++) {
			
			String S = input.next();
			
			map[n] = S.split("");
			
			for(int m = 0; m < M; m++) {
				
				if(map[n][m].equals("o")) {
					
					CoinLocation.add(n);
					CoinLocation.add(m);
					
					map[n][m] = "."; // 동전의 위치를 갈 수 있는 곳으로 바꿔준다.
				}
			}
		}
		
		OneX.add(CoinLocation.get(0));
		OneY.add(CoinLocation.get(1));
		
		TwoX.add(CoinLocation.get(2));
		TwoY.add(CoinLocation.get(3));
		
		Count.add(0);
		
		int move_x[] = {0, 0, 1, -1};
		int move_y[] = {1, -1, 0, 0};
		
		//int answer = 0;
		
		while(!OneX.isEmpty()) {
			
			int one_x = OneX.poll();
			int one_y = OneY.poll();
			
			int two_x = TwoX.poll();
			int two_y = TwoY.poll();
			
			int count = Count.poll();
			
			if(count > 10)
				break;
			
			//동전이 겹칠 경우 어차피 안되니까 continue??
			if(one_x == two_x && one_y == two_y)
				continue;
			
			for(int mx = 0; mx < move_x.length; mx++) {
				
				int go_one_x = one_x + move_x[mx];
				int go_one_y = one_y + move_y[mx];
				
				int go_two_x = two_x + move_x[mx];
				int go_two_y = two_y + move_y[mx];
				
				/**
				 * 이 조건문을 추가 안해주면 60%에서 틀렸습니다 가 나온다..
				 */
				if(count+1 > 10)
					break;
				
				
				//두 동전 다 떨어지는 경우
				if(check_range(go_one_x, go_one_y) == 1 &&
						check_range(go_two_x, go_two_y) == 1) 
					continue;
				
				/**
				 * 두 동전 중 1개만 떨어지는 경우
				 */
				else if(check_range(go_one_x, go_one_y) == 0 &&
						check_range(go_two_x, go_two_y) == 1) {
					
					System.out.println(count+1);
					return;
				}
					
				else if(check_range(go_one_x, go_one_y) == 1 &&
						check_range(go_two_x, go_two_y) == 0) {
					
					System.out.println(count+1);
					return;
					
				}
				
				//두개 다 벽일 경우
				if(map[go_one_x][go_one_y].equals("#") &&
						map[go_two_x][go_two_y].equals("#"))
					continue;
				
				//하나만 벽일 경우
				if(map[go_one_x][go_one_y].equals("#")) {
					go_one_x = one_x; // 기존 경로
					go_one_y = one_y;
				}
				
				if(map[go_two_x][go_two_y].equals("#")) {
					go_two_x = two_x;
					go_two_y = two_y;
				}
				
				OneX.add(go_one_x);
				OneY.add(go_one_y);
				
				TwoX.add(go_two_x);
				TwoY.add(go_two_y);
				
				Count.add(count+1);
			}
		}
		
		System.out.println(-1);

	}
	
	/**
	 * 범위 체크 함수
	 */
	static int check_range(int x, int y) {
		
		if(x < 0 || y < 0 || x >= N || y >= M)
			return 1; // 범위 벗어나면 1
		
		else
			return 0;
	}

}
