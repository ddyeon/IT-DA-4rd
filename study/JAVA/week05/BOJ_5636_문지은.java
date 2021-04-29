import java.io.*;
import java.util.*;

public class Main {
	
	public static boolean isPrime(int n) {
		
		for (int i = 2; i < n; i++) {
			if (n%i == 0) return false;		//not prime
		}
		return true;		//prime
	}

    public static void main(String[] args) throws IOException{
    	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    	
    	String s = bf.readLine();
    	while (!s.equals("0")) {
    		
    		int max = 0;
    		
    		for (int i = 0; i < s.length(); i++) {
    			for (int j = i; j < s.length(); j++) {
    				if (j > i+4) continue;
    				int n = Integer.parseInt(s.substring(i, j+1));
    				if (isPrime(n) && n > max) max = n;
    			}
    		}
    		
    		System.out.println(max);
    		
    		s = bf.readLine();
    	}

    }
    
}
