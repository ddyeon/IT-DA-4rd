import java.awt.Point;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static int m, n;
	static int[][] map;
	static int[][] visited;
	
	static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	public static void bfs(int x, int y) {
		
		Queue<Point> q = new LinkedList<Point> ();
		q.offer(new Point(x, y));
		visited[x][y] = 1;
		
		while (!q.isEmpty()) {
			Point p = q.poll();
			
			for (int i = 0; i<8; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				
				if (nx > 0 && nx <= m && ny > 0 && ny <= n) {
					if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
						visited[nx][ny] = 1;
						q.add(new Point(nx, ny));
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {	
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		
		map = new int[m+1][n+1];
		visited = new int[m+1][n+1];
		
		for (int i = 1; i <= m ; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = sc.nextInt();
			}	
		}
		
		int ans = 0;
		for (int i = 1; i <= m ; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {
					ans++;
					bfs(i, j);
				} 
			}	
		}
		
		System.out.println(ans);
		
	}

}
