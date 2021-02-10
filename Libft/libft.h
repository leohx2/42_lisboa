#ifndef LIBFT_H
#define LIBFT_H

int             ft_isalpha(int c);
int             ft_isdigit(int c);
int             ft_isalnum(int c);
int             ft_isascii(int c);
int             ft_isprint(int c);
int             ft_toupper(int c);
int             ft_tolower(int c);//  08/07/2020 ate aqui
unsigned int    ft_strlen(const char *s);
unsigned int    ft_strlcpy(char *dst, const char *src, unsigned int size);
unsigned int    ft_strlcat(char *dst, const char *src, unsigned int size);
char            *ft_strchr(const char *s, int c);
char            *ft_strrchr(const char *s, int c);
char            *ft_strnstr(const char *dest, const char *src, unsigned int len);
int             ft_strncmp(const char *s1, const char *s2, unsigned int n);
void            *ft_memset(void *s, int c, unsigned n);
#endif