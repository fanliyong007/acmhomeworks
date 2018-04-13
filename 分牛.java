public class Bull {

	public static void main(String[] args) {

		double a=0,b=0,c=0,sum=19;
		for(int i=0;i<100;i++)
		{
			a+=sum*1.0/2;
			b+=sum*1.0/4;
			c+=sum*1.0/5;
			sum=19-a-b-c;
		}
		System.out.println(a+" "+b+" "+c);
	}

}
