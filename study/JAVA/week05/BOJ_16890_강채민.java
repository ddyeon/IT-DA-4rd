import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		/**
		 * 시간초과..
		 * 
		 * https://yeeybook.tistory.com/136
		 * 참고.
		 * 
		 * 근데 시간초과가 남 
		 * 아직 모르겠음
		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String S1 = br.readLine();
		String S2 = br.readLine();
		
		char s1 [] = S1.toCharArray();
		char s2 [] = S2.toCharArray();
		
		Arrays.sort(s1);
		Arrays.sort(s2);
		
		System.out.println(String.valueOf(s2));
		
		int length1 = (s1.length + 1) / 2;
		int length2 = s2.length / 2;
		
		Queue<Character> Q1 = new LinkedList<>();
		Queue<Character> Q2 = new LinkedList<>();
		
		for(int i = 0; i < length1; i++)
			Q1.add(s1[i]);
		
		for(int i = 0,k = (s2.length - 1); i < length2; i++,k--)
			Q2.add(s2[k]);
		
		
		System.out.println("Q1 " + Q1);
		System.out.println("Q2 " + Q2);
		
		
		char answer[] = new char[S1.length()];
		int left = 0;
		int right = answer.length - 1;
		
		for(int i = 0; i < answer.length; i++) {
			
			if(i % 2 == 0) { // 구사과 차례
				
				if(Q2.isEmpty() || (Q1.peek() < Q2.peek())) { // 구사과 글자가 큐브러버 글자보다 사전순으로 앞서다면
					answer[left] = Q1.poll(); // 정답의 맨 앞에 칸에다가 넣는다.
					left++; // 자리수 늘려주기 
				}
				
				else { // 구사과 글자가 사전순으로 더 뒤면은 뒤로 배치해야한다.
					answer[right] = Q1.poll();
					right--;
				}
			}
			
			else { // 큐브러버 차례
				
				if(Q1.isEmpty() || (Q1.peek() < Q2.peek())) { // 큐브러버의 글자가 훨씬 뒤라면
					answer[left] = Q2.poll();
					left++;
				}
				
				else {
					answer[right] = Q2.poll();
					right--;
				}
			}
			
			//System.out.println(Arrays.toString(answer));
			
		}
		
		System.out.println(String.valueOf(answer));
	}

}
