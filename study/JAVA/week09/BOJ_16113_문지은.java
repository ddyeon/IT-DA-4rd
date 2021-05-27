package algorithm;

import java.util.*;

public class Main{
	
	public static void main(String[] args) {
		
		String z = "####.##.##.####";
		String o = ".#..#..#..#..#.";
		String t = "###..#####..###";
		String th = "###..####..####";
		String f = "#.##.####..#..#";
		String fi = "####..###..####";
		String six = "####..####.####";
		String seven = "###..#..#..#..#";
		String ei = "####.#####.####";
		String ni = "####.####..####";
		
		String[] nums = {z, o, t, th, f, fi, six, seven, ei, ni};

		Scanner sc = new Scanner(System.in);
		
		int l = sc.nextInt();
		int r = l/5;
		
		String []map = new String[5]; 
		String s = sc.next();
		map[0] = s.substring(0, r);
		map[1] = s.substring(r, 2*r);
		map[2] = s.substring(2*r, 3*r);
		map[3] = s.substring(3*r, 4*r);
		map[4] = s.substring(4*r, 5*r);
		
		String ans = "";
		
		for (int i = 0; i < r-2; i++) {
			String tmps = "";
			for (int j = 0; j < 5; j++) {
				tmps += map[j].substring(i, i+3);
			}
			
			for (int k = 0; k < 10; k++) {
				if (tmps.equals(nums[k]))
					ans += Integer.toString(k);
			}
			
		}
		System.out.println(ans);
		
		
		
		
		
	}
}
