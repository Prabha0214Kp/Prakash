#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *anagram(char *str);
int main()
{
	char str[20],str2[20],*p,*q;
	int l1,l2;

	printf("enter the str:");
	gets(str);

	printf("enter the str2:");
	gets(str2);

	l1=strlen(str);
	l2=strlen(str2);

	anagram(str);
	anagram(str2);

	if(l1!=l2)
	{
		printf("not anagram\n");
	}
	else
	{
		if(strcmp(str,str2)==0)
		{
			printf("anagram\n");
		}
		else
		{
			printf("not anagram\n");
		}
	}
}

void *anagram(char *str)
{
	int i,j;
	char temp;

	for(i=0;str[i];i++)
	{
		for(j=i+1;str[j];j++)
		{
			if(str[i]<str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	return str;
}




















