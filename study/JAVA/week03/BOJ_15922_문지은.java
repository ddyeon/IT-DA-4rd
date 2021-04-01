
import java.util.*;

public class Main {
	
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int ans = 0;
		
		int x=0, y=0;
		
		for (int i = 0; i < n; i++) {
			int tx = sc.nextInt();
			int ty = sc.nextInt();
			
			if (i == 0) {
				x = tx;
				y = ty;
				
				ans += y-x;
				continue;
			}
			
			//new Line
			if (tx > y) {
				ans += ty - tx;
				x = tx;
				y = ty;
			}
			else if (ty > y) {
				ans += ty - y;
				y = ty;
			}

		}
		
		System.out.println(ans);
		
		
	}
}
