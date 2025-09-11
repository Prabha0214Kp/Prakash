#include<stdio.h>
#include<string.h>

void fun(char *str);
int main()
{

	char str[]="aabbbcddd";
	fun(str);
	return 0;
}
void fun(char *str)
{
	int count=1;
	int len=strlen(str);

	for(int i=1;i<=len;i++)
	{
		if(str[i]==str[i-1])
		{
			count++;
		}
		else
		{
			printf("%d%c",count,str[i-1]);
			count=1;
		}
	}
	printf("\n");
}



