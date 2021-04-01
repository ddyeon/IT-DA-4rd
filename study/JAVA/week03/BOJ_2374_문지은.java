
import java.util.*;

public class Main {
	
	public static int[] arr;
	public static int num;
	public static int ans;
	
	public static boolean plus(int i) {
		int td = i-1;
		int tu = i+1;
		
		if (td != -1) {
			while (arr[td] == arr[i] ) {
				arr[td]++;
				td--;
				if (td == -1) break;
			}
		}
		
		if (tu != num) {
			while (arr[tu] == arr[i]) {
				arr[tu]++;
				tu++;
				if (tu == num) break;
			}
		}
		
		if (td == -1 && tu == num) {
			return true;
		}
		arr[i]++;
		return false;
	}
	
	public static void count(int count) {
		for (int i = 0; i < num; i++) {
			if (plus(i)) {
				ans = count;
				return;
			}
			count(count+1);
		}
		
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		num = sc.nextInt();
		arr = new int[num];
		
		for	(int i = 0; i < num; i++) {
			arr[i] = sc.nextInt();
		}
		
		count(0);
		
	}
}
