/*******************************************************

* Program : test.c

* Creation Date : Tue Nov 28 11:49:52 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 11:50:42 2023

* Created By : Alec Lim

*******************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    if (isdigit('1'))
        printf("1\n");

    if (isascii('1'))
        printf("2\n");
}
