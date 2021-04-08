import java.util.*;

public class Main {
	
	static int n, m;
	static char[][] map;
	static boolean[][] visited;
	
	static int dx[] = {1, -1, 0, 0};
	static int dy[] = {0, 0, 1, -1};
	
	static int we, en;
	
	public static class Location {
		int x;
		int y;
		
		
		public Location(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static int bfs(int x, int y) {
		
		int num = 0;
		Queue <Location> q = new LinkedList<>();
		
		q.add(new Location(x, y));
		num++;
		visited[x][y] = true;
		
		while (!q.isEmpty()) {
			Location cur = q.poll();
			
			int cx = cur.x;
			int cy = cur.y;
			
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				
				if (nx >= 1 && nx <= m && ny >= 0 && ny < n) {
					if (!visited[nx][ny] && map[nx][ny] == map[cx][cy]) {
						visited[nx][ny] = true;
						q.add(new Location(nx, ny));
						num++;
					}
				}
			}
		}
		
		return num*num;
	}
	


	public static void main(String[] args) {
		
		Scanner sc = new Scanner (System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		map = new char[m+1][n+1];
		visited = new boolean[m+1][n+1];
		
		for (int i = 1; i <= m; i++ ) {
			String s = sc.next();
			map[i] = s.toCharArray();
		}
		
		we = 0;
		en = 0;
		
		for	(int i = 1; i <= m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					if (map[i][j] == 'W')
						we += bfs(i, j);
					else
						en += bfs(i, j);
				}
			}
		}
		
		System.out.println(we + " " + en);
		
		
		
		
		
		
		
	}
}
