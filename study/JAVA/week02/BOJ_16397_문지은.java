import java.util.*;

public class Main {
	
	public static int n, t, g;
	public static int[] map;
	public static boolean[] visited;
	
	public static class Location {
		int ind;
		int cnt;
		
		Location (int ind, int cnt) {
			this.ind = ind;
			this.cnt = cnt;
		}
	}
	
	public static int bfs(int s) {
		Queue <Location> q = new LinkedList<>();
		
		q.add(new Location(s, 0));
		
		while (!q.isEmpty()) {
			Location l = q.poll();
			int cInd = l.ind;
			int cCnt = l.cnt;
			
			int nInd;
			
			if (cCnt > t) {
				return -1;
			}
			
			if (cInd == g) {
				return cCnt;
			}
			
			nInd = cInd + 1;
			if (nInd <= 99999 && !visited[nInd]) {
				visited[nInd] = true;
				q.add(new Location(nInd, cCnt+1));				
			}
			
			
			nInd = cInd*2;
			if (nInd <= 99999) {
				int temp = nInd;
				int digit = 0;
				while (temp > 0) {
					temp /= 10;
					digit++;
				}
				
				if (visited[nInd - (int)Math.pow(10, digit-1)] == false)
				{
					visited[nInd - (int)Math.pow(10, digit-1)] = true;
					q.add(new Location(nInd - (int)Math.pow(10, digit-1), cCnt+1));
				}
			}
			
		}
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		t = sc.nextInt();
		g = sc.nextInt();
		
		map = new int[100000];
		visited = new boolean[100000];
		
		int ans = bfs(n);
		if (ans == -1)
			System.out.println("ANG");
		else
			System.out.println(ans);
		
	}
}
