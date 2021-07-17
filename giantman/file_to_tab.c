/*
** EPITECH PROJECT, 2020
** file_to_tab.c
** File description:
** create a tab with all the ch of the file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

off_t get_file_size(char const *path)
{
    struct stat data;

    if (stat(path, &data) == -1)
        return (-1);
    return (data.st_size);
}

char *reading_map(char const *path, int *len)
{
    int fd = open(path, O_RDONLY);
    char *buf;
    off_t size;

    if (fd == -1) {
        write(2, "wrong path", 10);
        return (NULL);
    }
    size = get_file_size(path);
    *len = size;
    if (size == -1)
        return (NULL);
    buf = malloc(sizeof(char) * (1 + size));
    if (read(fd, buf, size) != size || size == 0) {
        return (NULL);
    }
    close(fd);
    buf[size] = '\0';
    return (buf);
}
