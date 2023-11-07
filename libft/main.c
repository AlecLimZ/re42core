/*******************************************************

* Program : main.c

* Creation Date : Fri Nov  3 13:40:21 2023

* Author : Alec Lim

* Last Modified : Tue Nov  7 17:17:35 2023

* Created By : Alec Lim

*******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
	char lol[10] = "okok";
	printf("=====ft_strlen====\n");
	strlen("") == ft_strlen("") ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen(""), ft_strlen(""));
	strlen("-asd123") == ft_strlen("-asd123") ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen("-asd123"), ft_strlen("-asd123"));
	strlen("\n\t") == ft_strlen("\n\t") ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen("\n\t"), ft_strlen("\n\t"));
	strlen("hi\n") == ft_strlen("hi\n") ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen("hi\n"), ft_strlen("hi\n"));
	strlen(&lol[0]) == ft_strlen(&lol[0]) ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen(&lol[0]), ft_strlen(&lol[0]));
	strlen(&lol[2]) == ft_strlen(&lol[2]) ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen(&lol[2]), ft_strlen(&lol[2]));
	strlen(lol + 1) == ft_strlen(lol + 1) ? printf("OK\n") : printf("S:%ld - L:%ld\n", strlen(lol + 1), ft_strlen(lol + 1));

	printf("====ft_isalpha====\n");
	char cs = 'G';
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));
	cs = 'i';
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));
	cs = '@';
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));
	cs = '7';
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));
	cs = 255;
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));
	cs = '\0';
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));
	cs = 0;
	isalpha(cs) == ft_isalpha(cs) ? printf("Ok\n") : printf("KO %c - S:%d - L:%d\n", cs, isalpha(cs), ft_isalpha(cs));

	printf("====ft_isdigit====\n");
	cs = '0';
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));

	printf("====ft_isalnum====\n");
	printf("====ft_isascii====\n");
	printf("====ft_isprint====\n");
	printf("====ft_memset====\n");
	printf("====ft_bzero====\n");
	printf("====ft_memcpy====\n");
	printf("====ft_memove====\n");
	printf("====ft_strlcpy====\n");
	printf("====ft_strlcat====\n");
	printf("====ft_toupper====\n");
	printf("====ft_tolower====\n");
	printf("====ft_strchr====\n");
	printf("====ft_strrchr====\n");
	printf("====ft_strncmp====\n");
	printf("====ft_memchr====\n");
	printf("====ft_memcmp====\n");
	printf("====ft_strnstr====\n");
	printf("====ft_atoi====\n");

	return (0);
}
