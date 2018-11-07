
#include <stdio.h>   
//#include<stdlib.h>
#include<assert.h>

const char* strstr(const char *src, const char *dst)
{
	//入口参数检查
	assert(NULL != src && NULL != dst);
#if 0
	if (src == NULL || dst == NULL)
	{
		printf("usage: input error parameter\n");
		exit(1);
	}
#endif       
	while (NULL != src)
	{
		const char *temp1 = src;
		const char *temp2 = dst;
		const char *res = NULL;
		if (*temp1 == *temp2)
		{
			res = temp1;
			while (*temp1 && *temp2 && *temp1++ == *temp2++)
				;

			if (*temp2 == '\0')
			{
				return res;
			}
		}
		src++;
	}
	return NULL;
}


int main()
{
	const char *str1 = "helloworld";
	const char *str2 = "world";
	const char *res = strstr(str1, str2);

	if (res != NULL)
	{
		printf("%s\n", res);
	}
	else
	{
		printf("no child str\n");
	}

	return 0;
}