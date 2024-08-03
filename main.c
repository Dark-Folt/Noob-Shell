#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define RED_COLOR   "\033[1;31m"
#define RESET_COLOR  "\033[0m"
#define BUFFER_SIZE 1024

/**
 * @brief 
 * Only display a prompt
 * 
 */
void display_prompt()
{
    printf("$ ");
}

/**
 * @brief 
 * Print error in red color and works like printf
 * 
 * @param format 
 * @param ... 
 */
void print_error(const char *format, ...) {
    // error message prefix
    fprintf(stderr, "%s[error] ", RED_COLOR);

    // handle mutiple args 
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    // reset initial color and add new line
    fprintf(stderr, "%s\n", RESET_COLOR);
}

/**
 * @brief 
 * Read line of 1024 bytes from stdin
 * 
 * @return char* buffer that contains the readed line
 */
char* read_command()
{
    char* buffer = NULL;

    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (NULL == buffer) {
        print_error("malloc buffer");
        exit(EXIT_FAILURE);
    }
    
    char* res = NULL;
    res = fgets(buffer, BUFFER_SIZE, stdin);
    if (NULL == res) {
        print_error("Can not read stdin");
    } 

    return buffer;
}

int main(int argc, const char *argv[])
{
    char* cmd = NULL;

    while(1) {
        display_prompt();
        cmd = read_command();

        free(cmd);
    }

    return 0;
}
