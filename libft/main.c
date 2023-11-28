/*******************************************************

* Program : main.c

* Creation Date : Fri Nov  3 13:40:21 2023

* Author : Alec Lim

* Last Modified : Tue Nov 28 14:19:37 2023

* Created By : Alec Lim

*******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	char	lol[10];

	strcpy(lol, "okok");
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
    cs ='O';
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));
    cs = 'a';
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));
    cs = '\n';
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));
    cs = '\0';
	isdigit(cs) == ft_isdigit(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isdigit(cs), ft_isdigit(cs));

	printf("====ft_isalnum====\n");
	cs = '0';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	cs = '\n';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	cs = '\0';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	cs = 'O';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	cs = '7';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	cs = '@';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	cs = 'a';
	isalnum(cs) == ft_isalnum(cs) ? printf("Ok\n") : printf("KO [%c] - S:%d - L:%d\n", cs, isalnum(cs), ft_isalnum(cs));
	
    printf("====ft_isascii====\n");
    for (int i = -3; i < 258; i++) {
	    isascii(i) == ft_isascii(i) ? printf("Ok\n") : printf("KO [%d] - S:%d - L:%d\n", i, isascii(i), ft_isascii(i));
    }
        
	printf("====ft_isprint====\n");
    for (int i = 0; i < 258; i++) {
        isprint(i) == ft_isprint(i) ? printf("Ok\n") : printf("KO [%d] - S:%d - L:%d\n", i, isprint(i), ft_isprint(i));
    }
	printf("====ft_memset====\n");
    char str1[10] = "hihi";
    char str2[10] = "hihi";
    strcmp(str1, str2) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
    memset(str1, 0, 10);
    ft_memset(str2, 0, 10);
    strcmp(str1, str2) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
    printf("L:%s\n", (char*)memset(str1, '1', 9));
    printf("S:%s\n", (char*)ft_memset(str2, '1', 9));
    strcmp(str1, str2) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
    memset(str1, 'a', 3);
    ft_memset(str2, 'a', 3);
    strcmp(str1, str2) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
   // memset(str1, 'b', 0);
    ft_memset(str2, 'b', 0);
    //strcmp(str1, str2) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
	printf("====ft_bzero====\n");
    bzero(str1, 3);
    ft_bzero(str2, 3);
    strncmp(str1, str2, 10) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
    bzero(str1, 10);
    ft_bzero(str2, 10);
    strncmp(str1, str2, 10) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
	printf("====ft_memcpy====\n");
    printf("L: %s\n", (char*)memcpy(str1, "abcdef12345", 10));
    printf("S: %s\n", (char*)ft_memcpy(str2, "abcdef12345", 10));
    strncmp(str1, str2, 10) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
    printf("L: %s\n", (char*)memcpy(str1, "@@@@@", 3));
    printf("S: %s\n", (char*)ft_memcpy(str2, "@@@@@", 3));
    strncmp(str1, str2, 10) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
    printf("L: %s\n", (char*)memcpy(str1, "!!!!", 1));
    printf("S: %s\n", (char*)ft_memcpy(str2, "!!!!", 1));
    strncmp(str1, str2, 10) == 0 ? printf("Ok\n") : printf("KO S:%s - L:%s\n", str1, str2);
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
