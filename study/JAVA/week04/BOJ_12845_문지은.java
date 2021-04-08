import java.util.*;

public class Main {

    public static int n;
    public static ArrayList<Integer> arr = new ArrayList<Integer>();
    public static int max, maxInd;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        max = 0;
        maxInd = 0;
        for (int i = 0; i < n; i++){
            int l = sc.nextInt();
            arr.add(l);
            if (l > max) {
                max = l;
                maxInd = i;
            }
        }

        int ans = 0;
        int ind = maxInd;

        //max부터 왼쪽끝까지 합성
        while (ind < arr.size()-1){
            ans += arr.get(ind)+arr.get(ind+1);
            if (arr.get(ind) > arr.get(ind+1)){
                arr.remove(ind+1);
            }
            else{
                arr.remove(ind);
            }
        }

        //max부터 오른쪽끝까지 합성
        while (ind > 0){
            ans += arr.get(ind)+arr.get(ind-1);
            if (arr.get(ind) > arr.get(ind-1)){
                arr.remove(ind-1);
            }
            else{
                arr.remove(ind);
            }
            ind--;
        }


        System.out.println(ans);

    }
}
