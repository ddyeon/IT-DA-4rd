import java.util.Scanner;

public class 20365_블로그2 {

	public static void main(String[] args) {
		
		/**
		 * 전체를 칠하고 작은거 칠하는게 최소값!
		 * 
		 * 생각해보면 참 단순하구나..
		 * 
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week05/BOJ_20365_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 참고했습니다!!
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		String S = input.next();
		
		char blog[] = S.toCharArray();
		
		int blue = 0;
		int red = 0;
		
		if(blog[0] == 'B')
			blue++;
		
		else
			red++;
		
		for(int i = 1; i < N; i++) {
			
			if(blog[i] == 'R' && blog[i - 1] == 'B') // B -> R
				red++;
			
			else if(blog[i] == 'B' && blog[i - 1] == 'R')
				blue++;
		}
		
		if(blue < red)
			System.out.println(blue + 1);
		
		else
			System.out.println(red + 1);

	}
}
