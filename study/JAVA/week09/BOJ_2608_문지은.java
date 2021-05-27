package algorithm;

import java.util.*;

public class Main{
	
	public static int cal(String s) {
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'I') {
				if (i != s.length()-1) {
					if (s.charAt(i+1) == 'V') {
						sum += 4;
						i++;
					}
					else if (s.charAt(i+1) == 'X') {
						sum += 9;
						i++;
					}
					else {
						sum += 1;
					}
				}
				else {
					sum += 1;
				}
			}
			else if (s.charAt(i) == 'V') {
				sum += 5;
			}
			else if (s.charAt(i) == 'X') {
				if (i != s.length()-1) {
					if (s.charAt(i+1) == 'L') {
						sum += 40;
						i++;
					}	
					else if (s.charAt(i+1) == 'C') {
						sum += 90;
						i++;
					}
					else {
						sum += 10;
					}
				}
				else {
					sum += 10;
				}
			}
			else if (s.charAt(i) == 'L') {
				sum += 50;
			}
			else if (s.charAt(i) == 'C') {
				if (i != s.length()-1) {
					if (s.charAt(i+1) == 'D') {
						sum += 400;
						i++;
					}
					else if (s.charAt(i+1) == 'M') {
						sum += 900;
						i++;
					}
					else {
						sum += 100;
					}
				}
				else {
					sum += 100;
				}
				
			}
			else if (s.charAt(i) == 'D') {
				sum += 500;
			}
			else if (s.charAt(i) == 'M') {
				sum += 1000;
			}
		}
		return sum;
	}
	
	public static String cal2(int n) {
		String s = "";
		boolean v = true;
		boolean l = true;
		boolean d = true;
		
		boolean iv = true;
		boolean ix = true;
		boolean xl = true;
		boolean xc = true;
		boolean cd = true;
		boolean cm = true;
		
		while (n > 0) {
			int sl = s.length();
			if (n-1000 > 0) {
				if (sl>=4) {
					if (s.charAt(sl-1) == 'M' && s.charAt(sl-2) == 'M' && s.charAt(sl-3) == 'M')
						continue;
				}
				s += "M";
				n -= 1000;
			}
			else if (n-900 > 0 && cm && cd) {
				s += "CM";
				cm = false;
				cd = false;
				n -= 900;
			}
			else if (n-500 > 0 && d) {
				s += "D";
				d = false;
				n -= 500;
			}
			else if (n-400 > 0 && d && cm && cd) {
				s += "CD";
				cd = false;
				cm = false;
				d = false;
				n -= 400;
			}
			else if (n-100 > 0) {
				if (sl>=4) {
					if (s.charAt(sl-1) == 'C' && s.charAt(sl-2) == 'C' && s.charAt(sl-3) == 'C')
						continue;
				}
				s += "C";
				n -= 100;
			}
			else if (n-90 > 0 && xl && xc) {
				s += "XC";
				xl = false;
				xc = false;
				n -= 90;
			}
			else if (n-50 > 0 && l) {
				s += "L";
				l = false;
				n -= 50;
			}
			else if (n-40 > 0 && l && xl && xc) {
				s += "XL";
				l = false;
				xl = false;
				xc = false;
				n -= 40;
			}
			else if (n-10 > 0) {
				if (sl>=4) {
					if (s.charAt(sl-1) == 'X' && s.charAt(sl-2) == 'X' && s.charAt(sl-3) == 'X')
						continue;
				}
				s += "X";
				n -= 10;
			}
			else if (n-9 > 0 && iv && ix) {
				s += "IX";
				iv = false;
				ix = false;
				n -= 9;
			}
			else if (n-5 > 0 && v) {
				s += "V";
				v = false;
				n -= 5;
			}
			else if (n-4 > 0 && v && iv && ix) {
				s += "IV";
				iv = false;
				ix = false;
				v = false;
				n -= 4;
			}
			else {
				if (sl>=4) {
					if (s.charAt(sl-1) == 'I' && s.charAt(sl-2) == 'I' && s.charAt(sl-3) == 'I')
						continue;
				}
				s += "I";
				n--;
			}
		}
		
		return s;
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String s1 = sc.next();
		String s2 = sc.next();
		
		int n1 = cal(s1);
		int n2 = cal(s2);

		System.out.println(n1+n2);
		System.out.println(cal2(n1+n2));
		
		
	}
}
