#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int fd = -1;			// fd: file descriptor ==> 文件描述符
	char buf[100] = {0};	// 文件读取缓冲区
	char wrbuf[20] = "I LOVE LINUX!";
	int ret = -1;
	
	// 第一步：打开一个文件
	// fd = open("a.txt",O_RDWR | O_APPEND | O_TRUNC);
	// fd = open("a.txt",O_RDWR | O_CREAT);
	// fd = open("a.txt",O_RDWR | O_CREAT | O_EXCL,0666);
	fd = open("a.txt",O_RDONLY);
	if (-1 == fd)		// 有时候也这样写：(fd < 0)
	{
		printf("文件打开错误.\n");
		perror("open");
		_exit(-1);
	}
	else
	{
		printf("文件打开成功.fd=%d\n",fd);
	}
	
#if 1	
	// 第二步：读写文件
	// 写文件
	ret = write(fd,wrbuf,strlen(wrbuf));
	
	if (-1 == ret)
	{
		printf("写入失败.\n");
		perror("write");
		// 	return -1;
		_exit(-1);
	}
	else
	{
		printf("写入成功,写入了%d个字符\n",ret);
	}
#endif

#if 0	
	close(fd);
	open("a.txt",O_WRONLY);
	// 读文件
	ret = -1;
	ret = read(fd, buf, 13);
	
	if (-1 == ret)
	{
		printf("文件读取失败.\n");
		
		// 	return -1;
		_exit(-1);
	}
	else
	{
		printf("实际读取了%d字节\n",ret);
		printf("文件内容是[%s].\n",buf);
	}
#endif
	
	// 第三步：关闭文件	
	close(fd);
	
	// 	return 0;
	_exit(0);
}
























