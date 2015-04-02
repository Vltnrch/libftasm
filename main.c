/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 11:27:31 by vroche            #+#    #+#             */
/*   Updated: 2015/04/02 18:46:06 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"

static void	ft_bzero_tests(void)
{
	char	control[10];
	char	subject[] = "123456789";
	char	control2[] = "123456789";
	char	subject2[] = "123456789";
	char	control3[] = "123456789";
	char	subject3[] = "123456789";

	bzero(control, 10);
	ft_bzero(subject, 10);
	printf("ft_bzero test 1 - correct result : 0 | your result : %d\n", memcmp(control, subject, 10));
	subject[0] = 'a';
	ft_bzero(subject, 0);
	printf("ft_bzero test 2 - correct result : a | your result : %c\n", subject[0]);
	bzero(control2, 3);
	ft_bzero(subject2, 3);
	printf("ft_bzero test 3 - correct result : 0 | your result : %d\n", memcmp(subject2, control2, 10));
	bzero(control3, 0);
	ft_bzero(subject3, 0);
	printf("ft_bzero test 4 - correct result : 0 | your result : %d\n--------------------------\n", memcmp(subject3, control3, 10));
}

static void	ft_strcat_tests(void)
{
	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	printf("ft_strcat test 1 - correct result : 0 | your result : %d\n", strcmp(buf, "Bonjour."));
	printf("ft_strcat test 1 - correct result : %p | your result : %p\n", buf, ft_strcat(buf, ""));
	printf("ft_strcat test 2 - correct result : Bonjour. | your result : %s\n--------------------------\n", buf);
}

static void	ft_isalpha_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isalpha(i) != isalpha(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isalpha tests ok if you see only this message\n--------------------------\n");
}

static void	ft_isdigit_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isdigit(i) != isdigit(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isdigit tests ok if you see only this message\n--------------------------\n");
}

static void	ft_isalnum_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isalnum(i) != isalnum(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isalnum tests ok if you see only this message\n--------------------------\n");
}

static void	ft_isascii_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isascii(i) != isascii(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isascii tests ok if you see only this message\n--------------------------\n");
}

static void	ft_isprint_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isprint(i) != isprint(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isprint tests ok if you see only this message\n--------------------------\n");
}

static void	ft_toupper_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_toupper(i) != toupper(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_toupper tests ok if you see only this message\n--------------------------\n");
}

static void	ft_tolower_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_tolower(i) != tolower(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_tolower tests ok if you see only this message\n--------------------------\n");
}

static void	ft_puts_tests(void)
{
	int		puts_ret1;
	int		puts_ret2;

	puts_ret1 = ft_puts("aaa");
	printf("ft_puts test 1 - correct result (before): aaa\\n and return > 0 ??? : %d\n", puts_ret1);
	puts_ret2 = ft_puts(NULL);
	printf("ft_puts test 2 - correct result (before): (null)\\n and return > 0 ??? : %d\n\n", puts_ret2);
}

static void	ft_strlen_tests(void)
{
	int test_len = 1000*1000;
	char str[test_len];

	printf("ft_strlen test 1 - correct result : %lu | your result : %zu\n", strlen("chat"), ft_strlen("chat"));
	printf("ft_strlen test 2 - correct result : %lu | your result : %zu\n", strlen(""), ft_strlen(""));
	printf("ft_strlen test 3 - correct result : %lu | your result : %zu\n", strlen("aaa\0aaa"), ft_strlen("aaa\0aaa"));
	memset(str, 'a', test_len);
	str[test_len - 1] = '\0';
	printf("ft_strlen test 4 - correct result : %lu | your result : %zu\n--------------------------\n", strlen(str), ft_strlen(str));
}

static void	ft_memset_tests(void)
{
	char	b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	printf("ft_memset test 1 - correct result : 0 | your result : %d\n", memcmp(memset(b1, 99, 0), ft_memset(b1, 99, 0), 100));
	printf("ft_memset test 2 - correct result : 0 | your result : %d\n", memcmp(b1, b2, 100));
	b1[0] = 1;
	ft_memset(b1, 0, 0);
	printf("ft_memset test 3 - correct result : 1 | your result : %d\n", b1[0]);
	printf("ft_memset test 4 - correct result : 0 | your result : %d\n", memcmp(memset(strdup("abcd"), 'A', 5), ft_memset(strdup("abcd"), 'A', 5), 5));
	printf("ft_memset test 5 - correct result : 0 | your result : %d\n--------------------------\n", memcmp(memset(strdup("abcd"), 0, 0), ft_memset(strdup("abcd"), 0, 0), 5));
}

static void	ft_memcpy_tests(void)
{
	char	b1[100], b2[100];

	memset(b1, 33, 100);
	memset(b2, 63, 100);

	ft_memcpy(b1, b2, 100);
	printf("ft_memcpy test 1 - correct result : 0 | your result : %d\n", memcmp(b1, b2, 100));
	printf("ft_memcpy test 2 - correct result : 0 | your result : %d\n--------------------------\n", memcmp(ft_memcpy(b1, b2, 0), b1, 100));
}

static void	ft_strdup_tests(void)
{
	char *s1;
	char *s2;

	printf("ft_strdup test 1 - correct result : 0 | your result : %d\n", strcmp(ft_strdup("aaaaa"), "aaaaa"));
	printf("ft_strdup test 2 - correct result : 0 | your result : %d\n", strcmp(ft_strdup(""), ""));
	s1 = "aaa";
	s2 = ft_strdup(s1);
	printf("ft_strdup test 3 - NON correct result : %p | your result : %p\n\n", s1, s2);
}

static void	ft_cat_tests(void)
{
	int pids[2];
	char buf[10];
	int saved_stdout;

	saved_stdout = dup(1);
	pipe(pids);
	dup2(pids[1], 1);

	int fd;

	system("echo '12345678912345678' > catout");
	fd = open("catout", O_RDONLY);
	if (fd == -1)
		return ;
	ft_cat(fd);
	read(pids[0], buf, 17);
	dup2(saved_stdout, 1);

	close(fd);
	close(pids[0]);
	close(pids[1]);
	close(saved_stdout);
	system("rm catout");
	printf("ft_cat test 1 - correct result : 0 | your result : %d\n\n", memcmp(buf, "12345678912345678", 17));
}

static void	ft_strcpy_tests(void)
{
	char	buf1[6], buf2[6];

	bzero(buf1, 6);
	bzero(buf2, 6);
	printf("ft_strcpy test 1 - correct result : 0 | your result : %d\n", strcmp(ft_strcpy(buf1, "abcde"), strcpy(buf1, "abcde")));
	bzero(buf1, 6);
	bzero(buf2, 6);
	printf("ft_strcpy test 2 - correct result : 0 | your result : %d\n--------------------------\n", strcmp(ft_strcpy(buf1, "abc"), strcpy(buf1, "abc")));
}

static void	ft_strclr_tests(void)
{
	char	str[] = "tttttt";

	ft_strclr(str);
	printf("ft_strclr test 1 - correct result : 0 | your result : %d\n--------------------------\n", memcmp(str, "\0\0\0\0\0\0", 7));
}

static void	ft_strnew_tests(void)
{
	char	*str;
	char	*t;

	str = ft_strnew(100);
	t = malloc(101);
	bzero(t, 101);
	printf("ft_strnew test 1 - correct result : 0 | your result : %d\n", memcmp(str, t, 101));
	printf("ft_strnew test 2 - NO correct result : 0x0 | your result : %p\n", ft_strnew(0));
	printf("ft_strnew test 3 - correct result : 0x0 | your result : %p\n--------------------------\n", ft_strnew(ULONG_MAX - 1));
}

static void	ft_isspace_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isspace(i) != isspace(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isspace tests ok if you see only this message\n--------------------------\n");
}

static void ft_islower_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_islower(i) != islower(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_islower tests ok if you see only this message\n--------------------------\n");
}

static void ft_isupper_tests(void)
{
	int i;

	i = -10;
	while (i < 9000)
	{
		if (ft_isupper(i) != isupper(i))
			printf("%d: %c", i, i);
		i++;
	}
	printf("ft_isupper tests ok if you see only this message\n\n");
}

int			main(void)
{
	printf("\n\n----------PART 1----------\n\n");
	ft_bzero_tests();
	ft_strcat_tests();
	ft_isalpha_tests();
	ft_isdigit_tests();
	ft_isalnum_tests();
	ft_isascii_tests();
	ft_isprint_tests();
	ft_toupper_tests();
	ft_tolower_tests();
	ft_puts_tests();

	printf("----------PART 2----------\n\n");
	ft_strlen_tests();
	ft_memset_tests();
	ft_memcpy_tests();
	ft_strdup_tests();

	printf("----------PART 3----------\n\n");
	ft_cat_tests();

	printf("----------BONUS-----------\n\n");
	ft_strcpy_tests();
	ft_strclr_tests();
	ft_strnew_tests();
	ft_isspace_tests();
	ft_islower_tests();
	ft_isupper_tests();
	return(0);
}
