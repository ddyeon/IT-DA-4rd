import java.util.*;

public class 2608_로마숫자 {
	
	/**
	 * 아직 못품 ㅜㅜ
	 */

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		String S1 = input.next();
		String S2 = input.next();
		
		HashMap<String,Integer> map = new HashMap<String,Integer>(){{//초기값 지정
		    put("I", 1);
		    put("V", 5);
		    put("X", 10);
		    put("L", 50);
		    put("C", 100);
		    put("D", 500);
		    put("M", 1000);
		}};
		
		int beforeInt = map.get(Character.toString(S1.charAt(0)));
		
		int sum1 = beforeInt;
		
		for(int i = 1; i < S1.length(); i++) {
			
			String nowS = Character.toString(S1.charAt(i));
			int nowInt = map.get(nowS);
			
			if(beforeInt < nowInt) 
				sum1 += nowInt - beforeInt;
			
			else {
				sum1 += beforeInt;
				beforeInt = nowInt;
			}
			
		}
		
		//마지막수 더해주기?
		sum1 += map.get(Character.toString(S1.charAt(S1.length() - 1)));
		
		System.out.println(sum1);

	}

}
