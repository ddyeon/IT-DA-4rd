import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		/**
		 * 어떻게 생각해내지..?
		 * 
		 * 아직 미완성입니다..
		 */
		
		Scanner input = new Scanner(System.in);
		
		String S = input.next();
		
		int dp[] = new int[S.length() + 1];
		
		String pass [] = S.split("");
		
		dp[0] = 1;
		dp[1] = 1;
		
		for(int i = 2; i <= S.length(); i++) {
			
			int back_num = Integer.parseInt(pass[i - 1]);
			
			if(back_num >= 1 && back_num <= 9)
				dp[i] = dp[i - 1] % 1000000;
			
			int back_2_num = Integer.parseInt(pass[i - 2]);
			
			int check_num = back_2_num * 10 + back_num;
			
			if(check_num >= 1 && check_num <= 26)
				dp[i] = dp[i] + dp[i - 2] % 1000000;
			
			
		}
		
		System.out.println(dp[S.length()]);

	}

}
