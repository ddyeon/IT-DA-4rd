package algorithm;

import java.util.*;

public class Main {

    public static void main(String[] args){
        int n;
        String s;
        
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        s = sc.next();
        
        
        int r = 0;
        int b = 0;
        
        for (int i = 0; i < s.length(); i++){
        	 if (i != 0){
                 if (s.charAt(i) != s.charAt(i-1)) {
                	 if (s.charAt(i) == 'R') r++;
                	 else b++;
                 }
             }
        	 
        	 else {
        		 if (s.charAt(i) == 'R') r++;
            	 else b++;
        	 }
        }
        
        if (r > b) System.out.println(b+1);
        else System.out.println(r+1);
        
        
        

        
        
    }
    
}
