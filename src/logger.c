#include "logger.h"

void logger(char text[])
{
    char prefix[] = "[Minesweeper]";
    printf("%s %s\n", prefix, text);
}