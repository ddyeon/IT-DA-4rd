import java.util.*;
import java.util.stream.IntStream;

public class 12845_모두의마블 {
	
	public static void main(String[] args) {
		
		/**
		 * https://checkwhoiam.tistory.com/43 
		 * 참고.
		 * 
		 * 10 20 30 40 이렇게 주어지면 합칠 수 있는 경우의 수를 다 파악해 보니
		 * 결국 큰거 순서대로 합쳐주는게 제일 높았다. (생각해보면 그러는게 당연한건가?..)
		 * 
		 * 큰 level이 더해지는거니까 그럴 수 있겠다.. 
		 * 흠 머리가 좋지 않아 생각을 못했다............
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		//Integer level[] = new Integer[N];
		int level[] = new int[N];
		
		for(int n = 0; n < N; n++)
			level[n] = input.nextInt();
		
		/**
		 * 큰 숫자대로 묶어줘야해서 reverseOrder를 사용하려 Integer 배열을 쓸려고 했지만
		 * 합치는 함수가 따로 없어서 그냥 귀찮아서 int 배열로 하고
		 * 
		 * int배열은 따로 내림차순 정렬이 없기 때문에 그냥 내장되어있는 오름차순으로 정렬 후
		 * 가장 큰 숫자를 더해주도록 하였다.
		 * 
		 * 생각해보니 그냥 max값이랑 더해줘도 되는군..
		 */
		
		/**
		 * 1. 오름차순 정렬 후 계산
		 */
		//Arrays.sort(level, Collections.reverseOrder());
		Arrays.sort(level); // 오름차순 정렬이 되어있음
		
		int answer = (level[N-1] * (N - 2)) + IntStream.of(level).sum();
		
		/**
		 * 2. 정렬을 따로 하지 않고 배열에서 가장 큰값을 뽑아서 계산.
		 * (정렬을 하는게 시간은 더 단축된다.)
		 */
		int answer = (Arrays.stream(level).max().getAsInt() * (N - 2)) + IntStream.of(level).sum();
		
		System.out.println(answer);

	}
}
