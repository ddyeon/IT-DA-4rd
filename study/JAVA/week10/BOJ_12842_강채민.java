import java.util.*;

public class 12842_튀김소보루 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt(); // 처음에 개수
		int S = input.nextInt(); // 남은 개수
		
		int M = input.nextInt(); // 사람 수
		
		int soboru[] = new int[M+1];
		
		for(int m = 1; m <= M; m++) 
			soboru[m] = input.nextInt();
		
		int eat_soboru = N - S; // 먹은 개수 
		int count = 0;
		int time = 0;
		
		while(true) {
			
			for(int m = 1; m <= M; m++) {
				
				if(time % soboru[m] == 0)
					count++;
				
				if(eat_soboru == count) {
					
					System.out.println(m);
					return;
				}
			}
			
			time++;
		}

	}

}
