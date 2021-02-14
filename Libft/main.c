/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:59:09 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/02/13 14:36:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//input: gccm *.c libft.h -lbsd && ./a.out

#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
//#include <bsd/string.h>

int	main(void)
{
	int		i;
	char	ft_src[100];
	char	c_src[100];
	char	**allocated;
	char	*ft_allocated;
	char	c_var[30] = "testing functions ...";
	char	temp[50];
	char	*t;

	printf("\n--------------------------------------------------------- Testing libc functions---------------------------------------------------------\n");

	printf("\nTesting ft_memset(str + 8, '$', 13):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", memset(temp + 8, '$', 13), temp);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_memset(temp + 8, '$', 13), temp);
	
	printf("\nTesting ft_bzero(str + 7, 1):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	bzero(temp + 7, 1);
	printf("\tc:   %s\t\t after \'\\0\': %s\n", temp, &temp[8]);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	ft_bzero(temp + 7, 1);
	printf("\tft:  %s\t\t after \'\\0\': %s\n", temp, &temp[8]);
	
	printf("\nTesting ft_memcpy(str + 8, \"THIS: IS A TEST!\", 6)\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", memcpy(temp + 8, "THIS: IS A TEST!", 6), temp);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_memcpy(temp + 8, "THIS: IS A TEST!", 6), temp);
	
	printf("\nTesting ft_memccpy(str + 8, \"THIS: IS A TEST!\", \':\', 6)\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", memccpy(temp + 8, "THIS: IS A TEST!", ':', 6), temp);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_memccpy(temp + 8, "THIS: IS A TEST!", ':', 6), temp);
	
	printf("\nTesting ft_memmove(str + 8, \"THIS: IS A TEST!\", 6):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", memmove(temp + 8, "THIS: IS A TEST!", 6), temp);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_memmove(temp + 8, "THIS: IS A TEST!", 6), temp);
	
	printf("\nTesting ft_memchr(str, \'f\', 20):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	t = memchr(temp, 'f', 20);
	printf("\tc:   %p\tstr: %s\n", memchr(temp, 'f', 20), t);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	t = ft_memchr(temp, 'f', 20);
	printf("\tft:  %p\tstr: %s\n", ft_memchr(temp, 'f', 20), t);
	
	printf("\nTesting ft_memcmp(str, \"testing ...\", 10 and 6):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %d\t\t\tstr: %d\n", memcmp(temp, "testing ...", 10), memcmp(temp, "testing ...", 6));
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %d\t\t\tstr: %d\n", ft_memcmp(temp, "testing ...", 10), memcmp(temp, "testing ...", 6));

	printf("\nTesting ft_strlen(\"HelloWorld!\") and (\"-123abc123\"):\n");
	printf("\tstr: %s\tstr: %s\n\n", "HelloWorld!", "-123abc123");
	printf("\tc:   %zu\t\t\tc:   %zu\n", strlen("HelloWorld!"), strlen("-123abc123"));
	printf("\tft:  %lu\t\t\tft:  %lu\n", ft_strlen("HelloWorld!"), ft_strlen("-123abc123"));

	printf("\nTesting ft_strlcpy(str, \"HelloWorld!\", 6):\n");
	printf("\tptr: %p\tstr: (null)\n\n", c_src);
	printf("\tc:  %zut\t\t\tstr: %s\n", strlcpy(c_src, "HelloWorld!", 6), c_src);
	printf("\tft: %lut\t\t\tstr: %s\n", ft_strlcpy(ft_src, "HelloWorld!", 6), ft_src);

	printf("\nTesting ft_strlcat(c_src, \"HelloWorld!\", 14):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_src, c_src);
	printf("\tc:  %zu\t\t\tstr: %s\n", strlcat(c_src, "HelloWorld!", 14), c_src);
	printf("\tft: %lu\t\t\tstr: %s\n", ft_strlcat(ft_src, "HelloWorld!", 14), ft_src);
	
	printf("\nTesting ft_strchr(str + 2, \'t\'):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", strchr(temp + 2, 't'), strchr(temp + 2, 't'));
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_strchr(temp + 2, 't'), ft_strchr(temp + 2, 't'));
	
	printf("\nTesting ft_strrchr(str, \'t\'):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", strrchr(temp, 't'), strrchr(temp, 't'));
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_strrchr(temp, 't'), ft_strrchr(temp, 't'));
	
	printf("\nTesting ft_strnstr(str, \"fu\", 10):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %p\tstr: %s\n", strnstr(temp, "fu", 10), strnstr(temp, "fu", 10));
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %p\tstr: %s\n", ft_strnstr(temp, "fu", 10), ft_strnstr(temp, "fu", 10));

	printf("\nTesting ft_strncmp(str, \"testing ...\", 10 and 6):\n");
	printf("\tptr: %p\tstr: %s\n\n", c_var, c_var);
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tc:   %d\t\t\tstr: %d\n", strncmp(temp, "testing ...", 10), strncmp(temp, "testing ...", 6));
	ft_strlcpy(temp, c_var, sizeof(c_var));
	printf("\tft:  %d\t\t\tstr: %d\n", ft_strncmp(temp, "testing ...", 10), strncmp(temp, "testing ...", 6));

	printf("\nTesting ft_atoi(\"-123abc123\"):\n");
	printf("\n");
	printf("\tchar c:   %ld\t\tint c:   %d\n", sizeof(atoi("	-123abc123")), atoi("	-123abc123"));
	printf("\tchar ft:  %ld\t\tint ft:  %d\n", sizeof(ft_atoi("	-123abc123")), ft_atoi("	-123abc123"));

	printf("\nTesting ft_isalpha(\'h\' and \'1\'):\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", isalpha('H'), isalpha('1'));
	printf("\tft: %d\t\t\tft: %d\n", ft_isalpha('H'), ft_isalpha('1'));

	printf("\nTesting ft_isdigit(\'h\' and \'1\'):\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", isdigit('H'), isdigit('1'));
	printf("\tft: %d\t\t\tft: %d\n", ft_isdigit('H'), ft_isdigit('1'));

	printf("\nTesting ft_isalnum(\'h\' and \'1\'):\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", isalnum('H'), isalnum('1'));
	printf("\tft: %d\t\t\tft: %d\n", ft_isalnum('H'), ft_isalnum('1'));

	printf("\nTesting ft_isascii(\'h\' and 0x80):\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", isascii('H'), isascii(0x80));
	printf("\tft: %d\t\t\tft: %d\n", ft_isascii('H'), ft_isascii(0x80));

	printf("\nTesting ft_isprint(\'h\' and 31):\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", isprint('H'), isprint(31));
	printf("\tft: %d\t\t\tft: %d\n", ft_isprint('H'), ft_isprint(31));

	printf("\nTesting ft_toupper:\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", toupper('H'), toupper('1'));
	printf("\tft: %d\t\t\tft: %d\n", ft_toupper('H'), ft_toupper('1'));

	printf("\nTesting ft_tolower(\'h\' and \'1\'):\n");
	printf("\n");
	printf("\tc:  %d\t\t\tc:  %d\n", tolower('H'), tolower('1'));
	printf("\tft: %d\t\t\tft: %d\n", ft_tolower('H'), ft_tolower('1'));

	printf("\nTesting ft_strdup(\"HelloWorld!\"):\n");
	printf("\tstr: %s\n\n", "HelloWorld!");
	ft_allocated = strdup("HelloWorld!");
	printf("\tc:  %s\t\tc:  %p\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = ft_strdup("HelloWorld!");
	printf("\tft: %s\t\tft: %p\n", ft_allocated, ft_allocated);
	free(ft_allocated);

	printf("\nTesting ft_calloc(11, sizeof(char)):\n");
	printf("\tstr: %s\n\n", "HelloWorld!");
	ft_allocated = calloc(11, sizeof(char));
	ft_strlcpy(ft_allocated, "HelloWorld!", 11);
	printf("\tc:  %p\tc:  %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = calloc(11, sizeof(char));
	ft_strlcpy(ft_allocated, "HelloWorld!", 11);
	printf("\tft: %p\tft: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	
	printf("\n-------------------------------------------------------Testing aditional functions-------------------------------------------------------\n");
	
	printf("\nTesting ft_substr(\"Programer\", 4, 3)\n\tft_substr(\"Programer\", 0, 7):\n\n");
	ft_strlcpy(temp, "Programmer", 11);
	printf("\tptr: %p\tstr: %s\n\n", temp, temp);
	ft_allocated = ft_substr(temp, 4, 3);
	printf("\tft:  %p\tstr: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_strlcpy(temp, "Programmer", 11);
	ft_allocated = ft_substr(temp, 0, 7);
	printf("\tft:  %p\tstr: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	
	printf("\nTesting ft_strjoin(\"This \", \"function \")\n\tft_strjoin(\"passed \", \"the test!\"):\n\n");
	ft_allocated = ft_strjoin("This ", "function ");
	printf("\tft:  %p\tstr: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = ft_strjoin("passed ", "the test!");
	printf("\tft:  %p\tstr: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = ft_strjoin("This function ", "passed the test!");
	printf("\tft:  %p\tstr: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	
 	printf("\nTesting ft_strtrim(\"ThisT\", \"T\")\n\tft_strtrim(\" passed \", \" \")\n\tft_strtrim(\"This function\", \"\"):\n\n");
	ft_allocated = ft_strtrim("ThisTh", "Th");
	printf("\tft:  %p\tstr: %s\\0\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = ft_strtrim(" passed ", " ");
	printf("\tft:  %p\tstr: %s\\0\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = ft_strtrim("This function", "");
	printf("\tft:  %p\tstr: %s\\0\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	
	printf("\nTesting ft_split(\" This is a test. \", \' \')\n\tft_split(\"Test.\", \',\'):\n");
	ft_strlcpy(temp, " This is a test. ", 46);
	allocated = ft_split(temp, ' ');
	printf("\n\t$%s$\n", temp);
	i = 0;
	while (allocated[i])
	{
		printf("\tstr[%d]: $%s$ ", i, allocated[i]);
		printf("--> ");
		for (size_t j = 0;  j < ft_strlen(allocated[i]) + 1; j++)
			printf("%d ", allocated[i][j]);
		printf("\n");
		i++;
	}
	printf("\n");
	free(allocated);
	ft_strlcpy(temp, "Test.", 44);
	allocated = ft_split(temp, ',');
	printf("\t$%s$\n", temp);
	i = 0;
	while (allocated[i])
	{
		printf("\tstr[%d]: $%s$ ", i, allocated[i]);
		printf("--> ");
		for (size_t j = 0;  j < ft_strlen(allocated[i]) + 1; j++)
			printf("%d ", allocated[i][j]);
		printf("\n");
		i++;
	}
	printf("\n");
	free(allocated);

	printf("\nTesting ft_itoa(-123123)\n\tft_itoa(0):\n");
	printf("\n");
	ft_allocated = ft_itoa(-123123);
	printf("\tc:  %p\tc: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	ft_allocated = ft_itoa(0);
	printf("\tft: %p\tft: %s\n", ft_allocated, ft_allocated);
	free(ft_allocated);
	
	printf("\nTesting ft_putchar_fd('t', 1)\n\tft_putchar_fd('e', 1)\n\tft_putchar_fd('s', 1)\n\tft_putchar_fd('t', 1)\n\tft_putchar_fd('.', 1):\n");
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\t', 1);
	ft_putchar_fd('f', 1);
	ft_putchar_fd('t', 1);
	ft_putchar_fd(':', 1);
	ft_putchar_fd(' ', 1);
	ft_putchar_fd('T', 1);
	ft_putchar_fd('e', 1);
	ft_putchar_fd('s', 1);
	ft_putchar_fd('t', 1);
	ft_putchar_fd('.', 1);
	ft_putchar_fd('\n', 1);

	printf("\nTesting ft_putstr_fd(\"Testing complete.\", 1):\n\n");
	ft_putstr_fd("\tft: Testing complete.\n", 1);
	
	printf("\nTesting ft_putendl_fd(\"Testing complete.\", 1):\n\n");
	ft_putendl_fd("\tft: Testing complete.", 1);
	
	printf("\nTesting ft_putnbr_fd(-1234, 1)\n\tft_putnbr_fd(-2147483648, 1):\n\n");
	ft_putstr_fd("\tft:  ", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putstr_fd("\n\tft: ", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd("\n", 1);
	
	printf("\n---------------------------------------------------------Testing bonus functions---------------------------------------------------------\n");
	printf("\n--------------------------------------------------------Program finished testing.--------------------------------------------------------\n");
	return (0);
}