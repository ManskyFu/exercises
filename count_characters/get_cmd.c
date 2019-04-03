#include "count.h"
#include <stdio.h>
#include <string.h>

int get_cmd(int argc, char **argv)
{
    cmd mycmd[3] = {{"-h", 0}, {"-f", 1}, {"-i", 2}};

    if (argc == 2)
    {
        if (!strncmp(mycmd[0].cmd_name, argv[1], 3))
            return mycmd[0].cmd_num;
        else if (!strncmp(mycmd[2].cmd_name, argv[1], 3))
            return mycmd[2].cmd_num;
    }
    else if (argc == 3)
    {
        if (!strncmp(mycmd[1].cmd_name, argv[1], 3))
            return mycmd[1].cmd_num;
    }

    return WRONGCMD;
}
