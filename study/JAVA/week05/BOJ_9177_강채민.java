import java.util.*;

public class 9177_단어섞기 {
	
	public static void main(String[] args) {
		
		/**
		 * 놓쳐버린 visited...
		 */
		
		//int check[][] = new int[201][201];
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		for(int n = 1; n <= N; n++) {
			
			int check[][] = new int[201][201];
			
			String S1 = input.next();
			String S2 = input.next();
			String S3 = input.next();
			
			int length1 = S1.length();
			int length2 = S2.length();
			int length3 = S3.length();
			
			if(length1 + length2 != length3) {
				System.out.println("Data set " + n + ": no");
				continue;
			}
			
			Queue<INDEX> IndexQ = new LinkedList<INDEX>();
			
			//처음을 가리키도록 한다
			IndexQ.add(new INDEX(0, 0, 0));
			check[0][0] = 1;
			
			int flag = 0;
			
			while(!IndexQ.isEmpty()) {
				
				INDEX pollindex = IndexQ.poll();
				
				int index1 = pollindex.index1;
				int index2 = pollindex.index2;
				int index3 = pollindex.index3;
				
				if(index3 == length3 && index1 == length1 && index2 == length2) {
					
					flag = 1;
					break;
						
				}
				
				/**
				 * 원래 했던 방식 == 모든 경우의 수를 쪼개서...
				 */
				
				/*
				if(S1.charAt(index1) == S3.charAt(index3) &&
						S2.charAt(index2) == S3.charAt(index3)) {
					
					IndexQ.add(new INDEX(index1+1, index2, index3+1));
					IndexQ.add(new INDEX(index1, index2+1, index3+1));
				}
				
				else if(S1.charAt(index1) != S3.charAt(index3) &&
						S2.charAt(index2) == S3.charAt(index3)) {

					IndexQ.add(new INDEX(index1, index2+1, index3+1));
				}
				
				else if(S1.charAt(index1) == S3.charAt(index3) &&
						S2.charAt(index2) != S3.charAt(index3)) {
					
					IndexQ.add(new INDEX(index1+1, index2, index3+1));
				}
				
				else
				*/
				
				if(index1 != length1 && S1.charAt(index1) == S3.charAt(index3) && check[index1 + 1][index2] != 1) {
					
					IndexQ.add(new INDEX(index1 + 1, index2, index3 + 1));
					check[index1 + 1][index2] = 1;
				}
					
				
				if(index2 != length2 && S2.charAt(index2) == S3.charAt(index3) && check[index1][index2 + 1] != 1) {
					
					IndexQ.add(new INDEX(index1, index2 + 1, index3 + 1));
					check[index1][index2 + 1] = 1; 
				}
					
			}
			
			if(flag == 0)
				System.out.println("Data set " + n + ": no");
			
			else
				System.out.println("Data set " + n + ": yes");
		}
		
		

	}
	
	public static class INDEX {
		
		int index1;
		int index2;
		int index3;
		
		public INDEX(int a, int b, int c) {
			index1 = a;
			index2 = b;
			index3 = c;
		}
	}

}
