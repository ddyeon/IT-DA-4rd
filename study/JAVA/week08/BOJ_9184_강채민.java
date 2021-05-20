import java.util.*;

public class 9184_신나는함수실행 {
	
	static int dp[][][];

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		dp = new int[101][101][101];
		
		while(true) {
			
			int a = input.nextInt();
			int b = input.nextInt();
			int c = input.nextInt();
			
			if(a == -1 && b == -1 && c == -1)
				break;
			
			System.out.println("w(" + a + ", " + b + ", " + c + ") = " + 
								w(a, b, c));
		}
		

	}
	
	public static int w(int a, int b, int c) {
		
		if(a <= 0 || b <= 0 || c <= 0)
			return 1;
		
		if(a > 20 || b > 20 || c > 20)
			return w(20, 20, 20);
		
		if(dp[a][b][c] != 0)
			return dp[a][b][c];
		
		if(a < b && b < c)
			return (dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1)
									- w(a, b-1, c));
		
		else
			return (dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1,c) 
								+ w(a-1, b, c-1) - w(a-1, b-1, c-1));
	}

}
