package algorithm;

import java.util.*;

public class Main{
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int temp = m;
		for (int i = 0; i < n; i++) {
			int h = sc.nextInt();
			temp -= (h+1);
		}
		
		if (temp <= 0) {
			System.out.println(0);
			return;
		}
		
		int num = temp/(n+1);
		int remain = temp%(n+1);
		
		int ans = 0;
		for (int i = 0; i < remain; i++) {
			for (int j = 1; j <= num+1;j++) 
				ans += j*j;
		}
		for (int i = 0; i < n+1-remain; i++) {
			for (int j = 1; j <= num;j++) 
				ans += j*j;
		}
		
		System.out.println(ans);
		
		
	}
}
