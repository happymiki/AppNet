#include <stdio.h>		// standard input and output
#include <stdlib.h>
#include <string.h>

#define FILENAME "1.txt"

int main(void)
{
	FILE *fp = NULL;
	size_t len = -1;
	int a[10] = {1,2,3,4,5};
	
	
	fp = fopen(FILENAME,"w+");
	
	if (NULL == fp)
	{
		perror("fopen");
		exit(-1);
	}
	
	printf("fopen success %d.\n",fp);
	
	
	// 在这里去读写文件
	// len = fwrite("asdf",1,4,fp);
	
	len = fwrite(a,sizeof(int),(sizeof(a)/sizeof(a[0])),fp);
	
	printf("len = %d.\n",len);
	
	fclose(fp);
	
	return 0;
	
}

