#include "get_next_line.h" 
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("map.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // '\n' 포함되어 출력됨
        free(line);
    }

    close(fd);
    get_next_line(-2); // 내부 버퍼 해제용

    return 0;
}
