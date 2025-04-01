import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double maxValue = -1;
        int idx = 0;
        
        for(int i = 0; i < 3; i++) {
            int price = sc.nextInt();
            int weight = sc.nextInt();
            
            double value;
            if(price >= 500) {
                value = (double)(weight * 10) / (price * 10 - 500);
            } else {
                value = (double)(weight * 10) / (price * 10);
            }
            
            if(value > maxValue) {
                maxValue = value;
                idx = i;
            }
        }
        
        System.out.println(idx == 0 ? 'S' : (idx == 1 ? 'N' : 'U'));
    }
}