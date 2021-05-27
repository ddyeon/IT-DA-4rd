package algorithm;

import java.util.*;

public class Main{
	
	public static class Location{
		int value;
		int grow;
		
		Location(int value, int grow){
			this.value = value;
			this.grow = grow;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		Location[][] map = new Location [m][m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = new Location(1, 0);
			}
		}		
		
		int z, o, t;
		for (int i = 0; i < n; i++) {
			z = sc.nextInt();
			o = sc.nextInt();
			t = sc.nextInt();
			
			int sx, sy;
			sx = m-1;
			sy = 0;
			
			while (z > 0 && sx >= 0) {
				map[sx][sy].value = map[sx][sy].value;
				map[sx][sy].grow = 0;
				z--;
				sx--;
			}
			while (o > 0 && sx >= 0) {
				map[sx][sy].value += 1;
				map[sx][sy].grow = 1;
				o--;
				sx--;
			}
			while (t > 0 && sx >= 0) {
				map[sx][sy].value += 2;
				map[sx][sy].grow = 2;
				t--;
				sx--;
			}
			
			
			sx = 0;
			sy = 1;
			while (z > 0 && sy < m) {
				map[sx][sy].value = map[sx][sy].value;
				map[sx][sy].grow = 0;
				z--;
				sy++;
			}
			while (o > 0 && sy < m) {
				map[sx][sy].value += 1;
				map[sx][sy].grow = 1;
				o--;
				sy++;
			}
			while (t > 0 && sy < m) {
				map[sx][sy].value += 2;
				map[sx][sy].grow = 2;
				t--;
				sy++;
			}
			
			for (int j = 1; j < m; j++) {
				for (int k = 1; k < m; k++) {
					map[j][k].grow = Math.max(map[j-1][k-1].grow, Math.max(map[j][k-1].grow, map[j-1][k].grow));
					map[j][k].value += map[j][k].grow;
				}
			}
		}
		
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < m; b++) {
				System.out.print(map[a][b].value + " ");
			}
			System.out.println("");
		}
	}
}
