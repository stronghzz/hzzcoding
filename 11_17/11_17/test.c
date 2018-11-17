#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
enum { SIZE = 5 };
int main()
{
	double a[SIZE] = { 1.0,2.0,3.0,4.0,5.0 };
	double b[SIZE] = { 1.0 };
	size_t ret_code = 0;
	FILE *fp = fopen("text.bin", "wb");
	fwrite(a, sizeof(*a), SIZE, fp);
	fclose(fp);
	fp = fopen("text.bin", "rb");
	ret_code = fread(b, sizeof *b, SIZE, fp);
	if (ret_code == SIZE)
	{
		puts("Array read successfully,contents:");
		for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
		putchar('\n');
	}
	else
	{
		if (feof(fp))
		{
			printf("Error ending test.bin: unexpected end of file\n");
		}
		else if (ferror(fp))
		{
			perror("Error reading test.bin");
		}

	}
	fclose(fp);
	//FILE *pFile;
	//pFile = fopen("../text.txt", "w");
	//if (pFile != NULL)
	//{
	//	fputs("fopen example", pFile);
	//	fclose(pFile);
	//}


	//int a = 10000;
	//FILE *pf = fopen("../test.txt", "w");
	//fwrite(&a, 4, 1, pf);
	//fclose(pf);
	//pf = NULL;

	system("pause");
	return 0;
}