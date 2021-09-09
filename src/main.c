#include <stdio.h>
#include <stdlib.h>
#include "include/input.h"
#include "include/templates.h"
#if defined(unix) || defined(__unix__) || defined(__unix)
#include <sys/stat.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#endif

int main(int argc, char const *argv[])
{
    char name[50];
    FILE *main;
    FILE *make;
    printf("Project-name:\n");
    get_string(name, 50);
#if defined(unix) || defined(__unix__) || defined(__unix)
    if (mkdir("bin", S_IRWXU) != 0)
    {
        printf("Unable to create ./bin\n");
    }
    if (mkdir("obj", S_IRWXU) != 0)
    {
        printf("Unable to create ./obj\n");
    }
    if (mkdir("src", S_IRWXU) != 0)
    {
        printf("Unable to create ./src\n");
    }
    if (mkdir("src/include", S_IRWXU) != 0)
    {
        printf("Unable to create ./src/include\n");
    }
#elif defined(_WIN32) || defined(_WIN64)
    if (mkdir("bin") != 0)
    {
        printf("Unable to create ./bin\n");
    }
    if (mkdir("obj") != 0)
    {
        printf("Unable to create ./obj\n");
    }
    if (mkdir("src") != 0)
    {
        printf("Unable to create ./src\n");
    }
    if (mkdir("src\\include") != 0)
    {
        printf("Unable to create ./src/include\n");
    }
#endif
    main = fopen("src/main.c", "w");
    make = fopen("Makefile", "w");
    fprintf(main, MAIN);
    fprintf(make, MAKE, name);
    fclose(main);
    fclose(make);
    return 0;
}
