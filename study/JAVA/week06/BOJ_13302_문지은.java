
import java.util.*;

public class Main{
	
	public static int n;
	public static boolean[] no;
	public static boolean[][][] visited;
	
	public static class Location{
		int date;
		int bill;
		int coupon;
		
		Location(int date, int bill, int coupon){
			this.date = date;
			this.bill = bill;
			this.coupon = coupon;
		}
	}
	
	public static int bfs() {
		Queue <Location> q = new LinkedList<>();
		
		q.add(new Location(0, 0, 0));
		
		int min = 999999999;
		
		while (!q.isEmpty()) {
			Location l = q.poll();
		
			if (l.date > n) continue;
			
			else if (l.date == n) {
				if (min > l.bill) min = l.bill;
			}

			else {
				if (no[l.date+1]) {
					if (!visited[l.date+1][l.bill/1000][l.coupon]) {
						q.add(new Location(l.date+1, l.bill, l.coupon));
						visited[l.date+1][l.bill/1000][l.coupon] = true;
					}
	
				}
				else {
					//1일
					if (l.date+1 <= n) {
						if (!visited[l.date+1][(l.bill+10000)/1000][l.coupon]) {
							q.add(new Location(l.date+1, l.bill+10000, l.coupon));
							visited[l.date+1][(l.bill+10000)/1000][l.coupon] = true;
						}
					}
						
					//3일
					if (l.date+3 <= n) {
						if (!visited[l.date+3][(l.bill+25000)/1000][l.coupon+1]) {
							q.add(new Location(l.date+3, l.bill+25000, l.coupon+1));
							visited[l.date+3][(l.bill+25000)/1000][l.coupon+1] = true;
						}
					}
						
					//5일
					if (l.date+5 <= n) {
						if (!visited[l.date+5][(l.bill+37000)/1000][l.coupon+2]) {
							q.add(new Location(l.date+5, l.bill+37000, l.coupon+2));
							visited[l.date+5][(l.bill+37000)/1000][l.coupon+2] = true;
						}
					}
						
					//쿠폰
					if (l.date+1 <= n && l.coupon >= 3) {
						
						if (l.coupon >= 3) {
							q.add(new Location(l.date+1, l.bill, l.coupon-3));
							visited[l.date+1][(l.bill)/1000][l.coupon-3] = true;
						}
						
					}
					
					
				}
			}
				
		}
		return min;
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		no = new boolean[n+1];
		visited = new boolean[n+1][10001][50];
		
		int m = sc.nextInt();
		
		for (int i = 0; i < m; i++) {
			no[sc.nextInt()] = true;
		}
		
		System.out.println(bfs());
		
		
		
		
		
		
	}
}
