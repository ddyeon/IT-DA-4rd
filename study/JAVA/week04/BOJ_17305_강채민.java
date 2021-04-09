import java.util.*;

public class 17305_사탕배달 {
	
	public static void main(String[] args) {
		
		/**
		 * 팀장님 코드 참고했습니다
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week04/BOJ_17305_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 
		 * 영민님은 천재가 아닐까...
		 * 
		 * 무게가 3인거를 모아서 내림차순 정렬하고
		 * 그거를 배열에 차례대로 누적합을 넣어준다.
		 * ex) 무게가 3인 당도가 10 20 30 이라면
		 * 내림차순을 했을 경우 30 20 10이 될것이고 
		 * 
		 * 그거를 배열에 누적 합을 하게 된다면 30 50 60 이렇게 될것이다.
		 * 
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int W = input.nextInt();
		
		ArrayList<Integer> Candy_Sugar[] = new ArrayList[2];
		
		for(int cs = 0; cs < 2; cs++)
			Candy_Sugar[cs] = new ArrayList();
		
		for(int n = 0; n < N; n++) {
			
			int T = input.nextInt(); // 사탕의 그램
			int S = input.nextInt(); // 사탕의 당도
			
			if(T == 3)
				Candy_Sugar[0].add(S);
			
			else
				Candy_Sugar[1].add(S);
		}
		
		/**
		 * 무게가 3이고 5인 사탕들을 내림차순 정렬해준다.
		 */
		Candy_Sugar[0].sort(Comparator.reverseOrder());
		Candy_Sugar[1].sort(Comparator.reverseOrder());
		
		
		/**
		 * three_sum배열에는 무게가 3인 당도들의 내림차순들의 누적합을 계속 넣어줄 것이다.
		 * 
		 * ex) Candy_Sugar[0] = 30 20 10이라면
		 * three_sum[0] 번째에는 아무것도 안넣었을때이기 때문에 [0]이고
		 * three_sum[1] 번째에는 제일 높은 1개를 넣었을때인 [30]
		 * three_sum[2] 번째에는 30+20인 [50] 이 들어간다 
		 * three_sum[3] 번째에는 30+20+10인 [60] 이 들어간다 
		 * 
		 * 따라서 three_sum의 배열의 크기는 Candy_Sugar[0].size() + 1이다. 
		 */
		
		long three_sum [] = new long[Candy_Sugar[0].size() + 1];
		long five_sum [] = new long[Candy_Sugar[1].size() + 1];
		
		for(int i = 1; i < three_sum.length; i++) 
			three_sum[i] = three_sum[i - 1] + Candy_Sugar[0].get(i - 1);
		
		for(int i = 1; i < five_sum.length; i++)
			five_sum[i] = five_sum[i - 1] + Candy_Sugar[1].get(i - 1);
		
		/**
		 * 먼저 무게가 5인거를 넣어주는게 좋기 때문에 5무게 위주로 넣어주고 남는 무게에 3을 넣어주는게 맞다.
		 * 
		 * 만일 W가 11이고 무게가 5가 0개일때는
		 * W / 5가 2가 되더라고 무게가 5인게 없기 때문에 
		 * 둘중에 min값을 넣어줘야한다.
		 */
		int five_count = Math.min(W / 5, Candy_Sugar[1].size());
		
		long answer = 0;
		
		for(int i = 0; i <= five_count; i++) {
			
			long sum = five_sum[i];
			
			/**
			 * 5무게를 담고 나서 남는 거에 3무게를 넣어주는데 
			 * 위와 마찬가지로 무게가 3인 개수가 0개일 수 있기 때문에 Candy_Sugar[0].size()와 비교해서 최소값을  .
			 */
			int three_count = (W - (i * 5)) / 3;
			three_count = Math.min(three_count, Candy_Sugar[0].size());
			
			sum += three_sum[three_count];
			
			answer = Math.max(answer, sum);
		}
		
		System.out.println(answer);
		
	}

}
