#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int cal_len(const char * pathname)
{
	int fd = -1;			// fd: file descriptor ==> 文件描述符
	int ret = -1;
		
	// 第一步：打开一个文件
       fd = open(pathname,O_RDONLY);
	if (-1 == fd)		// 有时候也这样写：(fd < 0)
	{
		//printf("文件打开错误.\n");
		perror("open");
		return (-1);
	}
	//else
	//{
	//	printf("文件打开成功.fd=%d\n",fd);
	//}
	
	// 文件指针指向文件开头
	// 用lseek将文件指针移动到末尾，返回值为距离文件开头的偏移量，即文件长度
	ret = lseek(fd,0,SEEK_END);
	
	return ret;
}

int main(int argc,char *argv[])
{

	if (argc != 2)
	{
		printf("usage:%s filename.\n",argv[0]);
		_exit(-1);
	}

	printf("文件长度是:%d个字节.\n",cal_len(argv[1]));
	
	return 0;
}
