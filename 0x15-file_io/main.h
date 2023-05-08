#ifndef FILE_MAIN
#define FILE_MAIN

/* Standar LIberarys */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/* main functions */
ssize_t read_textfile(const char *filename, size_t letters);


#endif