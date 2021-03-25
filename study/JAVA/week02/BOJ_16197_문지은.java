import java.util.*;

public class Main {
	
	public static int n, m;
	public static int coin;
	public static char map[][];
	public static boolean visited[][][][];
	
	public static int dx[] = {1, -1, 0, 0};
	public static int dy[] = {0, 0, 1, -1};
	
	public static class Location {
		int x1, y1;
		int x2, y2;
		int num;
		
		public Location(int x1, int y1, int x2, int y2, int num) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			this.num = num;
		}
	}
	
	public static boolean drop(int x, int y) {
		if (x >= 0 && x <n && y >= 0 && y <m)
			return true;
		return false;
	}
	
	public static int bfs(int x1, int y1, int x2, int y2) {
		Queue <Location> q = new LinkedList<>();
		
		q.add(new Location(x1, y1, x2, y2, 0));
		visited[x1][y1][x2][y2] = true;
		
		while (!q.isEmpty()) {
			Location l = q.poll();
			int cx1 = l.x1;
			int cy1 = l.y1;
			int cx2 = l.x2;
			int cy2 = l.y2;
			int num = l.num;
			
			//System.out.println(cx1+" "+cy1+" "+cx2 +" "+cy2+" "+num);
			
			for (int i = 0; i<4; i++) {
				int nx1 = cx1+dx[i];
				int ny1 = cy1+dy[i];
				int nx2 = cx2+dx[i];
				int ny2 = cy2+dy[i];
				int Nnum = num+1;
				
				if (Nnum > 10) {
					//System.out.println(cx1+" "+cy1+" "+cx2 +" "+cy2+" "+num);
					break;
				}
				
				if (drop(nx1, ny1) && drop(nx2, ny2)) {
					if (map[nx1][ny1] != '#' && map[nx2][ny2] != '#' && !visited[nx1][ny1][nx2][ny2]) {
						visited[nx1][ny1][nx2][ny2] = true;
						q.add(new Location(nx1, ny1, nx2, ny2, Nnum));
					}
						
					else if (map[nx1][ny1] != '#' && map[nx2][ny2] == '#' && !visited[nx1][ny1][cx2][cy2]) {
						visited[nx1][ny1][cx2][cy2] = true;
						q.add(new Location(nx1, ny1, cx2, cy2, Nnum));
					}
						
					else if (map[nx1][ny1] == '#' && map[nx2][ny2] != '#' && !visited[cx1][cy1][nx2][ny2]) {
						visited[cx1][cy1][nx2][ny2] = true;
						q.add(new Location(cx1, cy1, nx2, ny2, Nnum));
					}
						
					else if (map[nx1][ny1] == '#' && map[nx2][ny2] == '#' && !visited[cx1][cy1][cx2][cy2]) {
						visited[cx1][cy1][cx2][cy2] = true;
						q.add(new Location(cx1, cy1, cx2, cy2, Nnum));
					}
						
				}
				else if ((drop(nx1, ny1) && !drop(nx2, ny2)) || (!drop(nx1, ny1) && drop(nx2, ny2))) {
					return Nnum;
				}
				
			}
			
		}
		return -1;		
		
	}
	
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		map = new char[n][m];
		visited = new boolean[n][m][n][m];
		
		int x1=0, y1=0, x2=0, y2=0;
		boolean c = true;
		
		for (int i = 0; i<n; i++) {
			String s = sc.next();
			map[i] = s.toCharArray();
			for (int j = 0; j <s.length();j++){
				if (map[i][j] == 'o' && c) {
					x1 = i;
					y1 = j;
					c = false;
				}
				else if (map[i][j] == 'o' && !c) {
					x2 = i;
					y2 = j;
				}
			}
		}
		
		//System.out.println(x1 + " "+y1 + " "+x2 + " "+y2);
		
		System.out.println(bfs(x1, y1, x2, y2));
		

		
	}
}
