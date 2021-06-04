import java.util.*;

public class 2608_ {
	
	/**
	 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week09/BOJ_2608_%EA%B9%80%EC%98%81%EB%AF%BC.java
	 * 팀장님 코드랑 팀원들 코드 보면서 참고했습니다
	 * 
	 * 엄청나게 복잡할것처럼 보였는데... 그냥 구현하면 되는거였다니..?
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
		
		int sum1 = 0;
		
		for(int i = 0; i < S1.length(); i++) {
			
			String nowS = Character.toString(S1.charAt(i));
			int nowInt = map.get(nowS);
			
			if(i + 1 >= S1.length()) {
				
				sum1 += nowInt;
				continue;
			}
			
			String nextS = Character.toString(S1.charAt(i + 1));
			int nextInt = map.get(nextS);
			
			if(nowInt < nextInt) {
				
				sum1 += nextInt - nowInt;
				i++;
			}
		
			else 
				sum1 += nowInt;
			
		}
		
		int sum2 = 0;
		
		for(int i = 0; i < S2.length(); i++) {
			
			String nowS = Character.toString(S2.charAt(i));
			int nowInt = map.get(nowS);
			
			if(i + 1 >= S2.length()) {
				
				sum2 += nowInt;
				continue;
			}
			
			String nextS = Character.toString(S2.charAt(i + 1));
			int nextInt = map.get(nextS);
			
			if(nowInt < nextInt) {
				
				sum2 += nextInt - nowInt;
				i++;
			}
		
			else 
				sum2 += nowInt;
			
		}
		
		System.out.println(sum1 + sum2);
		
		String answer = "";
		int num = sum1 + sum2;
		
		/**
		 * 여기서부터가 약간 ..
		 * 
		 * while(num >= 0)을 하면 안된다
		 */
		
		while(num != 0) {
			
			if(num >= 1000) {
				answer += "M";
				num -= 1000;
			}
			
			else if(num >= 900) {
				answer += "CM";
				num -= 900;
			}
			
			else if(num >= 500) {
				answer += "D";
				num -= 500;
			}
			
			else if(num >= 400) {
				answer += "CD";
				num -= 400;
			}
			
			else if(num >= 100) {
				answer += "C";
				num -= 100;
			}
			
			else if(num >= 90) {
				answer += "XC";
				num -= 90;
			}
			
			else if(num >= 50) {
				answer += "L";
				num -= 50;
			}
			
			else if(num >= 40) {
				answer += "XL";
				num -= 40;
			}
			
			else if(num >= 10) {
				answer += "X";
				num -= 10;
			}
			
			else if(num >= 9) {
				answer += "IX";
				num -= 9;
			}
			
			else if(num >= 5) {
				answer += "V";
				num -= 5;
			}
			
			else if(num >= 4) {
				answer += "IV";
				num -= 4;
			}
			
			else if(num >= 1) {
				answer += "I";
				num -= 1;
			}
			
		}
		
		System.out.println(answer);
		

	}

}
