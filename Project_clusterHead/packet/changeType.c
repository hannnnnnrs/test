#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "changeType.h"

int get_length(char str[])
{
	char *p = str;
	int count = 0;
	while (*p++ != '\0')
	{
		count++;
	}
	return count;
}

double changeType(char msg[])
{
    double result;
    int point = get_length(msg);

    for (int i = 0; i < sizeof(&msg); i++)
    {
        if (msg[i] == '.')
        {
            point = i;
            break;
        }
    }

    for (int i = 0; i < point; i++)
    {
        result += (msg[i] - '0') * pow(10, point - i - 1);
    }

    for (int i = point + 1; i < get_length(msg); i++)
    {
        result += (msg[i] - '0') * pow(10, (point - i));
    }

    return result;
}
