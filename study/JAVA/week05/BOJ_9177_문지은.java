import java.util.*;

public class Main {
	
	public static class Location {
		int s1;
		int s2;
		int s3;
		
		Location (int s1, int s2, int s3){
			this.s1 = s1;
			this.s2 = s2;
			this.s3 = s3;
		}
	}
	
	public static boolean bfs(String s1, String s2, String s3) {
		
		Queue<Location> q = new LinkedList<>();
		boolean [][][] visited = new boolean[s1.length()+1][s2.length()+1][s3.length()+1];
		
		q.add(new Location(0, 0, 0));
		visited[0][0][0] = true;
		while (!q.isEmpty()) {
			Location l = q.poll();
			
			int c1 = l.s1;
			int c2 = l.s2;
			int c3 = l.s3;
			
			int n1, n2, n3;
			
			if (s3.length() == c3)
				return true;
			
			n1 = c1+1;
			n2 = c2;
			n3 = c3+1;
			if (n1 <= s1.length() && n3 <= s3.length()) {
				if (s1.charAt(n1-1) == s3.charAt(n3-1) && !visited[n1][n2][n3]) {
					q.add(new Location(n1, n2, n3));
					visited[n1][n2][n3] = true;
				}
			}
			
			n1 = c1;
			n2 = c2+1;
			n3 = c3+1;
			if (n2 <= s2.length() && n3 <= s3.length()) {
				if (s2.charAt(n2-1) == s3.charAt(n3-1) && !visited[n1][n2][n3] ) {
					q.add(new Location(n1, n2, n3));
					visited[n1][n2][n3] = true;
				}	
			}
		}
		return false;
		
	}

    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            
            String s1 = sc.next();
            String s2 = sc.next();
            String s3 = sc.next();
            
            if (bfs(s1, s2, s3)) System.out.println("Data set "+(i+1)+": yes");
            else System.out.println("Data set "+(i+1)+": no");
            
            
        }
        
        
        

        
        
    }
    
}
