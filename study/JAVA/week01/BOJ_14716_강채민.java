import java.util.*;

public class BFS_14716_현수막 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int M = input.nextInt();
		int N = input.nextInt();
		
		int map[][] = new int[M][N];
		int check[][] = new int[M][N];
		
		for(int m = 0; m < M; m++)
			for(int n = 0; n < N; n++)
				map[m][n] = input.nextInt();
		
		Queue<Integer> BannerX = new LinkedList<>();
		Queue<Integer> BannerY = new LinkedList<>();
		int count = 0;
		
		int move_x[] = {1, -1, 0, 0, -1, -1, 1, 1};
		int move_y[] = {0, 0, 1, -1, -1, 1, -1, 1};
		
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < N; j++) {
				
				if(map[i][j] == 0 || check[i][j] == 1)
					continue;
				
				BannerX.add(i);
				BannerY.add(j);
				check[i][j] = 1;
				count++;
				
				while(!BannerX.isEmpty()) {
					
					int X = BannerX.poll();
					int Y = BannerY.poll();
					
					for(int mx = 0; mx < move_x.length; mx++) {
						
						int go_x = X + move_x[mx];
						int go_y = Y + move_y[mx];
						
						if(go_x < 0 || go_y < 0 || go_x >= M || go_y >= N)
							continue;
						
						if(map[go_x][go_y] == 0 || check[go_x][go_y] == 1)
							continue;
						
						BannerX.add(go_x);
						BannerY.add(go_y);
						check[go_x][go_y] = 1;
					}
				}
			}
		}
		
		System.out.println(count);

	}
}
