#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int main()
{
		int t =0;
        scanf("%d",&t);
		while (t-- > 0) 
        {
            int n;
			scanf("%d",&n);
			int nums[n];		
			for (int i = 0; i <n; i++) {
				scanf("%d",&nums[i]);
			}			
			int cou = 1;
			int pos = 0;
			if (nums[1] == nums[0]) {
				cou++;
				pos = 1;
			}
			for (int i = 2; i < n; i++) 
            {
				for (int j = pos; j < i; j++) 
                {
					if (nums[i] == nums[j]) 
                    {
						pos = i;
						cou++;
					}
				}
			}
			
			printf("%d\n",cou);
		}
	
    return 0;
}
