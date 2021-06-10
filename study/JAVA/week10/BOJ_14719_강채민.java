import java.util.*;

public class 14719_빗물 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int H = input.nextInt();
		int W = input.nextInt();
		
		int map[] = new int[W];
		
		for(int w = 0; w < W; w++) 
			map[w] = input.nextInt();
		
		int answer = 0;
		
		for(int i = 1; i < W-1; i++) {
			
			int left_max = 0;
			int right_max = 0;
			
			for(int l = 0; l < i; l++)
				left_max = Math.max(left_max, map[l]);
			
			for(int r = i+1; r < W; r++)
				right_max = Math.max(right_max, map[r]);
			
			int two_min = Math.min(left_max, right_max);
			
			answer += Math.max(0,  two_min - map[i]);
		}
		
		System.out.println(answer);

	}

}
