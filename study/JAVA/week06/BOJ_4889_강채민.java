import java.util.*;

public class 4889_안정적인 문자열 {

	public static void main(String[] args) {
		
		/**
		 * 2504번의 괄호의 값 그 문제와 비슷하다고 생각했다.
		 * 
		 * https://imnotabear.tistory.com/259
		 * 참고.
		 */
		
		Scanner input = new Scanner(System.in);
		
		int index = 1;
		
		while(true) {
			String S = input.next();
			
			if(S.charAt(0) == '-')
				break;
			
			Stack<Character> stack = new Stack<>();
			
			stack.push(S.charAt(0));
			
			for(int i = 1; i < S.length(); i++) {
				
				if(!stack.isEmpty() && stack.peek() == '{' && S.charAt(i) == '}') {
					
					stack.pop();
					continue;
				}
				
				stack.push(S.charAt(i));
			}
			
			/**
			 * 아 그냥 짝수개니까 두개씩 꺼내면 되는거..!
			 */
			
			int count = 0;
			
			while(!stack.isEmpty()) {
				
				char A = stack.pop();
				char B = stack.pop();
				
				if(A == B)
					count += 1;
				
				else
					count += 2;
			}
			
			System.out.println(index + ". " + count);
			
			index++;
		}
		
		

	}

}
