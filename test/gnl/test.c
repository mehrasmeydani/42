#include "get_next_line.h"

int main(void)
{
	int fd = open("file.txt", O_RDONLY, O_CREAT);
	printf("%s", get_next_line(fd));
}