#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int n;int f[20];
	char s1[20]; char s2[20];
	stack<char> s;
	/*n为火车数量,f为标记表示in还是out,s1就是进来的顺序，s2出去的顺序 */	
	while(cin>>n)
	{	
		cin>>s1;
		cin>>s2;
		int i=0,j=0,k=0;
		while(i<=n)  
        {  
            if(s.empty())  
            {  
                s.push(s1[i]);  
                f[k] = 0;  
                i++;k++;      
            }  
            /*如果是空的栈，那么把元素压入栈，更改标记为in*/ 
            if(!s.empty()&&s.top()!=s2[j]) 
            {  
                s.push(s1[i]);  
                f[k] = 0;  
                i++;k++;
            } 
			/*如果栈顶元素与出站顺序当前位置的火车编号不一样 那么压入元素 更改标记*/ 
            if(!s.empty()&&s.top()==s2[j])  
            {  
                s.pop();  
                f[k] = 1;  
                j++;k++;
            } 
			/*如果栈顶元素与出站顺序当前位置的火车编号一样 那么删除元素 更改标记*/                              
        }      
        if(s.empty())//如果栈是空的说明火车走完了 应该是yes 
        {
        	cout<<"Yes."<<endl;
        	for(i=0;i<n*2;i++)
        	{
	        	if(f[i]!=1) cout<<"in"<<endl; //判断标记 是0就是in，是1就是out 
	        		else cout<<"out"<<endl;
	        }        
        }
		else //否则是no 
		{
			cout<<"No."<<endl;
		}
		cout<<"FINISH"<<endl;
		while(!s.empty())	s.pop();
	}
	return 0;
}