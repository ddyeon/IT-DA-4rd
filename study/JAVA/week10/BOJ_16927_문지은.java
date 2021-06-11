package algorithm;

import java.io.*;
import java.util.*;

public class Main{
	
	public static int[][] arr;
	
	public static void rotate(int sx, int sy, int ex, int ey) {
		int temp = arr[sx][sy];
		for (int i = sy; i < ey; i++)		//가로 위
			arr[sx][i] = arr[sx][i+1];
		for (int i = sx; i < ex; i++)
			arr[i][ey] = arr[i+1][ey];		//세로 오른쪽
		for (int i = ey; i > 0; i--)
			arr[ex][i] = arr[ex][i];		//가로 아래
		for (int i = ey; i > 0; i--)
			arr[sx][i-1] = arr[sx][i];		//세로 왼쪽
		arr[sx+1][sy] = temp;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		
		arr = new int[n][m];
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		//n/2만큼 회전 실행
		for (int i = 0; i < n/2; i++) {
			int sx = i;
			int sy = i;
			int ex = n-1-i;
			int ey = m-1-i;
			
			rotate(sx, sy, ex, ey);
			
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bw.write(arr[i][j] + " ");
			}
			bw.write("\n");
		}
		
		bw.flush();
		bw.close();
	}
}
