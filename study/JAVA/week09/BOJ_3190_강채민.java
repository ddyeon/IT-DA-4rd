import java.util.*;

public class 3190_뱀 {
	
	static int N;

	public static void main(String[] args) {
		
		/**
		 * 사과를 먹으면 뱀의 길이가 길어지는 것이고 
		 * 
		 * 길어진 그 길이는 변하지 않고 좌표만 움직이는 것이다!!
		 * 
		 * 그러면 Queue로 차례로 담아서 
		 * 
		 * tail은 Queue의 윗부분을
		 * head는 Queue의 마지막 부분을 차지하면 되겠다!
		 * 
		 * https://github.com/ddyeon/IT-DA-4rd/blob/main/study/JAVA/week09/BOJ_3190_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 오빠코드 참고했씁니다! (방향전환부분)
		 */
		
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		
		int K = input.nextInt(); // 사과 개수
		
		int map[][] = new int[N + 1][N + 1];
		
		for(int k = 0 ; k < K; k++) {
			
			int a = input.nextInt();
			int b = input.nextInt();
			
			map[a][b] = 1; // 사과 표시
		}
		
		int L = input.nextInt();
		
		//ArrayList<Integer> Xlist = new ArrayList<>();
		Queue<Integer> Xlist = new LinkedList<>();
		Queue<String> Clist = new LinkedList<>();
		
		/**
		 * 뱀의 좌표를 담을 디큐!
		 * 
		 * 꼬리 부분부터 위로 담아서 맨 마지막 부분이 head부분이다. 
		 */
		Deque<Integer> QX = new ArrayDeque<Integer>();
		Deque<Integer> QY = new ArrayDeque<Integer>();
		
		for(int l = 0; l < L; l++) {
			
			int X = input.nextInt();
			String C = input.next();
			
			Xlist.add(X);
			Clist.add(C);
		}
		
		int move_x[] = {0, 1, 0, -1}; // 시계방향으로: 오 아래 왼 위
		int move_y[] = {1, 0, -1, 0};
		
		int headX = 1;
		int headY = 1;
		
		QX.addFirst(headX);
		QY.addFirst(headY);
		
		map[headX][headY] = 2; // 뱀의 몸이 차지하고 있는 부분
		
		int direction = 0; // 처음에 오른쪽 가리키고있다.
		int time = 0;
		
		while(true) {
			
			time++;
			
			int goX = headX + move_x[direction];
			int goY = headY + move_y[direction];
			
			if(outOfBound(goX, goY) || map[goX][goY] == 2) { // 범위에 벗어나거나 뱀의 몸이 위치해있는 부분이라면
				break;
			}
			
			if(map[goX][goY] == 0) { // 아무것도 없다면
				
				/**
				 * 사과가 아니면 일단 뱀의 길이는 변하지 않으니까
				 * 꼬리 부분을 줄여준다.
				 * 
				 * 1. 맨 위의 꼬리 좌표를 꺼내서 (pollFirst)
				 * 2. 꺼낸 꼬리좌표의 map[][]배열을 0으로 다시 만들어준다.
				 * 3. 다음에 head부분을 Deque의 끝(addLast)에 넣어주고 
				 * 4. head부분의 map[][]을 2(뱀의 몸통부분)으로 만들어준다.
				 */
				
				int tailX = QX.pollFirst();
				int tailY = QY.pollFirst();
				map[tailX][tailY] = 0;
				
				headX = goX;
				headY = goY;
				QX.addLast(headX);
				QY.addLast(headY);
				map[headX][headY] = 2;
			}
			
			else if(map[goX][goY] == 1) { // 사과가 있다면 
				
				headX = goX;
				headY = goY;
				QX.addLast(headX);
				QY.addLast(headY);
				map[headX][headY] = 2;
			}
			
			if(!Xlist.isEmpty()) {
				
				if(time == Xlist.peek()) { // 시간이 증가되는 순으로 ArrayList에 담겨있기 때문에
					
					Xlist.poll();
					String directionS = Clist.poll();
					
					if(directionS.equals("D")) { // 오른쪽
						
						direction += 1;
						
						if(direction == 4)
							direction = 0;
					}
					
					else {
						
						direction -= 1;
						
						if(direction == -1)
							direction = 3;
					}
				}
			}
		}
		
		System.out.println(time);

	}
	
	public static boolean outOfBound(int x, int y) {
		
		if(x <= 0 || y <= 0 || x > N || y > N)
			return true;
		
		else
			return false;
	}

}
