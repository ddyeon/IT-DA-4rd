import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		while(true) {
			
			String S = input.next();
			
			if(S.equals("0"))
				return;
			
			ArrayList<Long> answer = new ArrayList<>();
			
			for(int step = 1; step <= 5; step++) {
				
				for(int i = 0; i < (S.length() - step) + 1; i++) {
					
					String checkS = S.substring(i, i + step);
					long checkI = Long.parseLong(checkS);
					
					if(isPrime(checkI)) 
						answer.add(checkI);
					
				}
				
			}
			
			if(answer.size() < 1)
				System.out.println(0);
			
			else
				System.out.println(Collections.max(answer));
		}

	}
	
	public static boolean isPrime(long ip) {
		
		if(ip < 2 || ip > 100000)
			return false;
		
		for(int i = 2; i*i <= ip; i++) {
			
			if(ip % i == 0)
				return false;
		}
		
		return true;
	}

}
