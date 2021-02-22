
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd;
    size_t size;
    char name[]= "aaa.fifo";

    umask(0);
    if(mknod(name, S_IFIFO | 0666, 0) < 0)
    {
        printf("Can\'t create FIFO\n");
    }

    if ((fd = open(name, O_WRONLY)) < 0)
    {
        printf("Can\'t open FIFO for writing\n");
        exit(-1);
    }

    size = write(fd, "Hello, world!", 14);

    if (size != 14)
    {
        printf("Can\'t write all string to FIFO\n");
        exit(-1);
    }
    if (close(fd) < 0) {
        printf("Can\'t close FIFO\n");
        exit(-1);
    }
    return 0;
}
