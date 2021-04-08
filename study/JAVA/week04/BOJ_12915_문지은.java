import java.util.*;

public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int[] arr = new int[5];
        int min = 100000;
        for (int i = 0; i < 5; i++){
            arr[i] = sc.nextInt();
            if (i%2==0){
                if (min > arr[i]) min = arr[i];
            }
        }
        
        int ans = min;
        arr[0] -= min;
        arr[2] -= min;
        arr[4] -= min;

        while (arr[0]+arr[1] != 0 && arr[1]+arr[2]+arr[3] != 0 && arr[3]+arr[4] != 0) {
            
            if (arr[0] == 0) arr[1]--;
            else arr[0]--;

            if (arr[2] == 0){
                if (arr[1] > arr[3])
                    arr[1]--;
                else
                    arr[3]--;
            }
            else arr[2]--;

            if (arr[4] == 0) arr[3]--; 
            else arr[4]--;
            ans++;
        }

        System.out.println(ans);
    }
}
