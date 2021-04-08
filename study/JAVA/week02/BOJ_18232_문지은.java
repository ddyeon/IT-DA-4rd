package algorithm;

import java.util.*;

public class Main {
	
	public static int n;
	public static int s, e;
	public static int map[];
	public static boolean visited[];
	public static Vector<Vector<Integer>> v;
	
	public static class Location {
		int ind;
		int time;
		
		Location(int ind, int time) {
			this.ind = ind;
			this.time = time;
		}
	}
	
	public static int bfs() {
	
		Queue <Location> q = new LinkedList<>();
		
		q.add(new Location(s, 0));
		visited[s] = true;
		
		while (!q.isEmpty()) {
			Location l = q.poll();
			int cInd = l.ind;
			int cTime = l.time;
			
			if (cInd == e)
				return cTime;
			
			int nInd;
			nInd = cInd + 1;
			if (nInd > 0 && nInd <=n) {
				if (!visited[nInd]) {
					visited[nInd] = true;
					q.add(new Location(nInd, cTime+1));
				}
			}
			
			nInd = cInd - 1;
			if (nInd > 0 && nInd <=n) {
				if (!visited[nInd]) {
					visited[nInd] = true;
					q.add(new Location(nInd, cTime+1));
				}
			}
			
			for (int i = 0; i< v.elementAt(cInd).size(); i++) {
				//System.out.println("cInd"+cInd);
				//System.out.println("size"+v.elementAt(cInd).size());
				nInd = v.elementAt(cInd).elementAt(i);
				//System.out.println(nInd);
				
				if (nInd > 0 && nInd <=n) {
					if (!visited[nInd]) {
						visited[nInd] = true;
						q.add(new Location(nInd, cTime+1));
					}
				}
				
			}
			
		}
		return -1;
		
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int num;
		
		n = sc.nextInt();
		
		map = new int[n+1];
		visited = new boolean[n+1];
		v = new Vector<Vector<Integer>>(n+1);
		for (int i = 0; i < n+2; i++)
			v.add(new Vector<Integer>());
		
		num = sc.nextInt();
		
		s = sc.nextInt();
		e = sc.nextInt();
		
		for (int i = 0; i < num; i++) {
			int n1, n2;
			n1 = sc.nextInt();
			n2 = sc.nextInt();

			v.elementAt(n1).add(n2);
			v.elementAt(n2).add(n1);
		}
		
		System.out.println(bfs());
		
		
	}
}
