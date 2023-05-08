#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Auth: ADEGBOLE ADEBISI
 * Desc: THIS FILE CONTAIN ALL THE INCLUDE GUILDED PROTOTYPE FOR THIS PROJECT, IT IS AN HEADER FILE.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
#endif /* MAIN_H */
