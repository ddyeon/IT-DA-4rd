import java.util.*;

public class 17305_사탕배달 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int W = input.nextInt();
		
		int dp[] = new int[1250001];
		
		/*
		for(int n = 0; n < N; n++) {
			
			int T = input.nextInt(); // 사탕의 그램
			int S = input.nextInt(); // 사탕의 당도
			
			for(int i = W; i >= T; i--) 
				dp[i] = Math.max(dp[i], dp[i - T] + S);
			
		}
		
		System.out.println(dp[W]);
		*/
		
		ArrayList<Integer> Candy_Sugar[] = new ArrayList[2];
		
		for(int cs = 0; cs < 2; cs++)
			Candy_Sugar[cs] = new ArrayList();
		
		for(int n = 0; n < N; n++) {
			
			int T = input.nextInt(); // 사탕의 그램
			int S = input.nextInt(); // 사탕의 당도
			
			if(T == 3)
				Candy_Sugar[0].add(S);
			
			else
				Candy_Sugar[1].add(S);
		}
		
		Collections.sort(Candy_Sugar[0]);
		Collections.sort(Candy_Sugar[1]);
		
		Candy_Sugar[0].sort(Comparator.naturalOrder());
		
		for(int i = 0; i < 2; i++) {
			
			//for(int j = )
		}

	}

}
