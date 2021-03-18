import java.util.Scanner;
import java.util.Stack;

public class Main {
	
	static int[] arr;
	static boolean[] visited;
	static boolean[] team;
	
	static int stu;
	static int ans;
	
	public static void dfs(int start) {
		Stack st = new Stack();
		Stack t = new Stack();
		st.push(start);
		t.push(start);
		visited[start] = true;
		
		while (!st.empty()) {
			int cur = (int) st.pop();
			int next = arr[cur];
			
			if (next == start) {
				
				while (!t.empty()) {
					ans++;
					team[(int)t.pop()] = true;
				}
				
				return;
			}
			
			if (visited[next] == false) {
				visited[next] = true;
				st.push(next);
				t.push(next);
			}
			
		}
		
	}
	
	public static void main(String[] args) {	
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		while (num-- > 0) {
			stu = sc.nextInt();
			
			arr = new int[stu+1];
			team = new boolean[stu+1];
			
			for (int j = 1; j <= stu; j++) {
				arr[j] = sc.nextInt();
			}
			
			ans = 0;
			for	(int j = 1; j<= stu; j++) {
				visited = new boolean[stu+1];
				if (team[j] == false) dfs(j);
			}
			
			System.out.println(stu - ans);
		}
		
	}

}
