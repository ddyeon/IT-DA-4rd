import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ_2608 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String first = br.readLine();
		String second = br.readLine();

		int sum = change(first) + change(second);
		bw.write(String.valueOf(sum) + "\n");
		bw.write(reverseChange(sum));
		bw.flush();
		bw.close();
	}

	static int change(String number) {
		int sum = 0;
		for (int i = 0; i < number.length(); i++) {
			char now = number.charAt(i);
			if (now == 'I') {
				sum += 1;
				if ((i + 1) < number.length()) {
					if (number.charAt(i + 1) == 'V') {
						sum += 3;
						i++;
					} else if (number.charAt(i + 1) == 'X') {
						sum += 8;
						i++;
					}
				}
			} else if (now == 'V') {
				sum += 5;
			} else if (now == 'X') {
				sum += 10;
				if ((i + 1) != number.length()) {
					if (number.charAt(i + 1) == 'L') {
						sum += 30;
						i++;
					} else if (number.charAt(i + 1) == 'C') {
						sum += 80;
						i++;
					}
				}
			} else if (now == 'L') {
				sum += 50;
			} else if (now == 'C') {
				sum += 100;
				if ((i + 1) != number.length()) {
					if (number.charAt(i + 1) == 'D') {
						sum += 300;
						i++;
					} else if (number.charAt(i + 1) == 'M') {
						sum += 800;
						i++;
					}
				}
			} else if (now == 'D') {
				sum += 500;
			} else if (now == 'M') {
				sum += 1000;
			}
		}
		return sum;
	}

	static String reverseChange(int number) {
		StringBuilder sb = new StringBuilder();
		while (number != 0) {
			if (number >= 1000) {
				sb.append("M");
				number -= 1000;
			} else if (number >= 900) {
				sb.append("CM");
				number -= 900;
			} else if (number >= 500) {
				sb.append("D");
				number -= 500;
			} else if (number >= 400) {
				sb.append("CD");
				number -= 400;
			} else if (number >= 100) {
				sb.append("C");
				number -= 100;
			} else if (number >= 90) {
				sb.append("XC");
				number -= 90;
			} else if (number >= 50) {
				sb.append("L");
				number -= 50;
			} else if (number >= 40) {
				sb.append("XL");
				number -= 40;
			} else if (number >= 10) {
				sb.append("X");
				number -= 10;
			} else if (number >= 9) {
				sb.append("IX");
				number -= 9;
			} else if (number >= 5) {
				sb.append("V");
				number -= 5;
			} else if (number >= 4) {
				sb.append("IV");
				number -= 4;
			} else if (number >= 1) {
				sb.append("I");
				number -= 1;
			}
		}
		return sb.toString();
	}
}
