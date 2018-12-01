import java.util.Scanner;

public class tmp { 
    public static void main(String[] args) { 
        int i = 0, sum = 0; 
        while (i <= 10) { 
            sum += i; 
            i++; 
            if (i % 2 == 0){ 
                sum += 1; 
            } 
        } 
        System.out.println(sum); 
    } 
} 