
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException{
    	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    	String s1 = bf.readLine();
    	String s2 = bf.readLine();
    	
    	StringBuffer sb1 = new StringBuffer(s1);
    	StringBuffer sb2 = new StringBuffer(s2);
    	
    	StringBuffer ans = new StringBuffer();
    	
    	int l = sb1.length();   	
    	
    	for (int i = 0; i < l/2 + 1; i++) {
    		char min = sb1.charAt(0);
    		int minInd = 0;
        	char max = sb2.charAt(0);
        	int maxInd = 0;
        	for (int j = 0; j < sb1.length(); j++) {
        		if ((int)min > (int)sb1.charAt(j)) {
        			min = sb1.charAt(j);
        			minInd = j;
        		}
        		
        		if ((int)max < (int)sb2.charAt(j)) {
        			max = sb2.charAt(j);
        			maxInd = j;
        		}
        	}
        	
        	if (i == l/2) {
        		ans.append(min);
        	}
        	else {
        		ans.append(min);
        		ans.append(max);
  
            	sb1.deleteCharAt(minInd);
            	sb2.deleteCharAt(maxInd);
        	}
    	}
    	


        System.out.println(ans);
        
        

        
        
    }
    
}
