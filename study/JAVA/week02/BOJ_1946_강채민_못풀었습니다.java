import java.util.*;

public class 16397_탈출 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int T = input.nextInt();
		int G = input.nextInt();
		
		Queue<Integer> NQ = new LinkedList<>();
		Queue<Integer> CQ = new LinkedList<>();
		
		NQ.add(N);
		CQ.add(0);
		
		int arr_pow[] = {1, 2};
		int arr_plus[] = {1, 0};
		
		while(!NQ.isEmpty()) {
			
			int now_n = NQ.poll();
			int count = CQ.poll();
			
			if(count > T)
				break;
			
			for(int i = 0; i < 2; i++) {
				
				int go_n = (int) Math.pow(now_n, arr_pow[i]);
				
				go_n = go_n + arr_plus[i];
				
				if(count+1 > T)
					break;
				
				if(i == 1) {
					
					String S = Integer.toString(go_n);
					
					int change_n = S.charAt(0) - '0';
					
					go_n = Integer.parseInt(Integer.toString(change_n-1) + S.substring(1));
				}
				
				if(go_n <= 0 || go_n >= 99999)
					continue;
				
				if(go_n == G) {
					System.out.println(count+1);
					return;
				}
				
				System.out.println(go_n + " " + (count+1));
				
				NQ.add(go_n);
				CQ.add(count+1);
			}
		}
		
		System.out.println("ANG");

	}

}
