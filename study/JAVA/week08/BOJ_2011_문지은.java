package algorithm;

import java.util.*;

class Main{	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		if (s.charAt(s.length()-1) == '0' && 
				10 > Integer.parseInt(s.substring(s.length()-2, s.length())) || 26 < Integer.parseInt(s.substring(s.length()-2, s.length())))
				{
			System.out.println("0");
			return;
		}
		
		int[] dp = new int[s.length()+1];
		
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= s.length(); i++) {
			if (10 <= Integer.parseInt(s.substring(i-2, i)) && 26 >= Integer.parseInt(s.substring(i-2, i))
					&& s.charAt(i-1) != '0') {
				dp[i] = (dp[i-2]%1000000 + dp[i-1]%1000000)%1000000;
			}
			else if (10 <= Integer.parseInt(s.substring(i-2, i)) && 26 >= Integer.parseInt(s.substring(i-2, i))
					&&s.charAt(i-1) == '0') {
				dp[i] = dp[i-2]%1000000;
			}
			else {
				dp[i] = dp[i-1]%1000000;
			}
			
		}
				
		
		System.out.println(dp[s.length()]);
		
	}
}
