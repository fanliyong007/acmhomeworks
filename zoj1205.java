import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Test
{
    public static void main(String args[])
    {
       Scanner read=new Scanner(System.in);
       while(read.hasNext())
       {
           String num1=read.next();
           String num2=read.next();
           BigInteger a=new BigInteger(num1,20);
           BigInteger b=new BigInteger(num2,20);
           System.out.println(a.add(b).toString(20));
       }
    }
}
