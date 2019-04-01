#include "choice.h"
#include <stdio.h>
#include <string.h>

int cmd_line(char *argv, int cmd_num)
{
    int m;
    CMD all_cmd_lines[3] = {{"-e", 1}, {"-d", 2}, {"-h", 3}};

    for (m = 0; m < cmd_num; ++m)
    {
        if (!strncmp(argv, all_cmd_lines[m].cmd_name, 3))
        {
            return all_cmd_lines[m].cmd_num;
        }
    }

    return NONCMD;
}
