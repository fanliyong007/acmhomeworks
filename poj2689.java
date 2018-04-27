
import java.util.Arrays;
import java.util.Scanner;
public class POJ2689
{

	public static void main(String[] args)
	{
		final int MAX=50000;//int最大20亿左右，开根号约5万，求出5万内的素数
		final int LEN=1000005;//区间最大距离
		int[] prime=new int[MAX];//存储的都是素数，递增的
		boolean[] isp=new boolean[MAX];//是否是素数的倍数，默认不是
		int count=0;//用来计数当前找到第几个素数了，素数的总个数
		
		for(int i=2;i<MAX;i++)//从2到Max一个一个筛选
		{
			if(isp[i]==false)//如果i不是素数的倍数（是素数）
			{
				prime[count]=i;//prime存储找到第count个素数
				count++;
			}
			
			//针对当前的i，用已经找到的count个素数去做筛选
			for(int j=0;j<count&& i*prime[j]<MAX;j++)
			{
				isp[i*prime[j]]=true;
				if(i%prime[j]==0)//如果i能整除这个素数就退出
				{
					break;
				}
			}
		}
		//System.out.println("共有"+count+"个素数");
		
		////////////////------欧拉方式打表完成--华丽的分割线----//////////////////////////////////////
		int L=0,U=0;//两个区间段
		int[] region=new int[LEN];//从L到U标记是否是素数，L是第0个数 相对位置
		Scanner s=new Scanner(System.in);
		while(s.hasNext())
		{
			L=s.nextInt();
			U=s.nextInt();
			Arrays.fill(region, 0);//每一轮测试都归0
			if(L==1)L=2;//隐藏很深的bug
			
			for(int i=0;i<count;i++)//用50000以内的素数一个一个去筛选L到U
			{
				int low=(L-1)/prime[i]+1;//L到U里有多少个prime[i] 最少
				int high=U/prime[i];//最多有多少个prime[i]
				for(int j=low;j<=high;j++)
				{
					if(j>1)
                    {
						region[j*prime[i]-L]=1;//区域里所有prime[i]的整数倍都是 合数 -L是相对L距离
                    }
				}
			}
			
			//所有合数标记出来后就是所有的素数了
			int maxDis=-1,minDis=999999999;
			int flag=-1,dis=0,m1=0,m2=0;
			//枚举相邻素数的距离用max和min分别记录下来
			for(int i=0;i<=U-L;i++)//UL的距离并非全是1000000，以实际距离为准
			{
				if(region[i]==0)//数组1是合数，0是素数
				{
					if(flag!=-1)//不是第一次
					{
						dis=i-flag;//当前2个素数的距离
						if(dis>maxDis)
						{
							maxDis=dis;//当前找到的最大距离
							m1=i+L;//当前位置的这个数 这个数-间距就是前面的那个素数
						}
						if(dis<minDis)
						{
							minDis=dis;
							m2=i+L;//当前位置的这个数 这个数-间距就是前面的那个素数
						}
					}
					if(i+L!=1)flag=i;//第一次只做flag=i
					
				}
			}
			if(maxDis==-1)System.out.println("There are no adjacent primes.");
			else System.out.printf("%d,%d are closest, %d,%d are most distant.\n",m2-minDis,m2,m1-maxDis,m1); 
			
		}
		
	}

}