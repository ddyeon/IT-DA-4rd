import java.util.*;

public class Main{

    public static int n;
    public static int w;
    public static ArrayList<Integer> small = new ArrayList<Integer>();
    public static ArrayList<Integer> big = new ArrayList<Integer>();

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        w = sc.nextInt();

        for (int i = 0; i < n; i++){
            int t = sc.nextInt();
            int s = sc.nextInt();
            if (t == 3) small.add(s);
            else big.add(s);
        }

        Collections.reverse(small);
        Collections.reverse(big);

        int[] smallArr = new int[small.size()+1];
        int[] bigArr = new int[big.size()+1];

        for (int i = 1; i <= small.size();i++){
            smallArr[i] = smallArr[i-1]+small.get(i-1);
        }
        for (int i = 1; i<= big.size(); i++){
            bigArr[i] = bigArr[i-1]+big.get(i-1);
        }

        int max = 0;
        for (int i = 0; i <= big.size(); i++){
            int remain = (w - i*5)/3;
            if (remain < 0 || remain > small.size()) continue;
            int temp = bigArr[i]+smallArr[remain];
            if (temp > max) max = temp;
        }

        System.out.println(max);

    }
}
