/**
 * @description Revise the main routine of the longest-line program so it will correctly print the
 * length of arbitrary long input lines, and as much as possible of the text.
 * @interactive
 */

#include <stdio.h>
#include "../lib.h"

#define BUFFER_LENGTH 1000

int main()
{
    char line[BUFFER_LENGTH];
    char subline[BUFFER_LENGTH];
    char longest_line[BUFFER_LENGTH];

    int max_length = 0;
    int line_length = 0;
    int subline_length;
    int subline_id = 0;
    while ((subline_length = get_line(subline, BUFFER_LENGTH)) > 0)
    {
        subline_id++;
        line_length += subline_length;

        if (subline_id == 1)
        {
            copy_str(line, subline);
        }

        if (is_line(subline))
        {
            if (line_length > max_length)
            {
                max_length = line_length;
                copy_str(longest_line, line);
            }

            subline_id = 0;
            line_length = 0;
        }
    }

    if (max_length > 0)
    {
        printf("%s", longest_line);
    }

    return 0;
}
