/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:02:25 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/23 18:18:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

ssize_t     ft_read(int fd, char *buf, size_t size);
ssize_t     ft_write(int fd, char *buf, size_t size);
int     	ft_strcmp(char *str1, char *str2);
char    	*ft_strcpy(char *dst, char *src);
char    	*ft_strdup(char *str);
size_t    	ft_strlen(char *str);

int main(void)
{
	char    *empty_str = "";
	char    *long_str = "gagagalgklagagkadkjhaehufhejbgugvenjsbvcvha9u39r0q30-iufj3290f8v39j0jjj`0c0`j0jj1k00fj3pf''/mfq//.,";
	char    buf1[110];
	char    buf2[110];
	int     fd;
	int     ft_fd;

	printf("Test ft_strlen:\n\n");
	printf("empty org: >%lu<\n", strlen(empty_str));
	printf("empty my: >%lu<\n", ft_strlen(empty_str));
	printf("long org: >%lu<\n", strlen(long_str));
	printf("long my: >%lu<\n\n", ft_strlen(long_str));

	printf("Test ft_strcpy:\n\n");
	printf("empty org: >%s< <%lu>\n", strcpy(buf1, empty_str), strlen(buf1));
	printf("empty my : >%s< <%lu>\n", ft_strcpy(buf2, empty_str), strlen(buf2));
	memset(buf1, 0, 109);
	memset(buf2, 0, 109);
	printf("long org: >%s< <%lu>\n", strcpy(buf1, long_str), strlen(buf1));
	printf("long my : >%s< <%lu>\n\n", ft_strcpy(buf2, long_str), strlen(buf2));
	memset(buf1, 0, 109);
	memset(buf2, 0, 109);

	printf("Test ft_strcmp: <org - my> <str1> <str2>\n\n");
	printf("1: <%d - %d> <> <>\n", strcmp("", ""), ft_strcmp("", ""));
	printf("2: <%d - %d> <> <abc>\n", strcmp("", "abc"), ft_strcmp("", "abc"));
	printf("3: <%d - %d> <abc> <>\n", strcmp("abc", ""), ft_strcmp("abc", ""));
	printf("4: <%d - %d> <abc> <cda>\n", strcmp("abc", "cda"), ft_strcmp("abc", "cda"));
	printf("5: <%d - %d> <cda> <abc>\n", strcmp("cda", "abc"), ft_strcmp("cda", "abc"));
	printf("6: <%d - %d> <abcd> <abc>\n", strcmp("abcd", "abc"), ft_strcmp("abcd", "abc"));
	printf("7: <%d - %d> <    > <cda>\n", strcmp("    ", " cda"), ft_strcmp("    ", " cda"));
	printf("8: <%d - %d> </xff/x80> </xff/x80>\n", strcmp("\xff\x80", "\xff\x00"), ft_strcmp("\xff\x80", "\xff\x00"));
	printf("9: <%d - %d> </xff/xfe> </xff>\n", strcmp("\xff\xfe", "\xff"), ft_strcmp("\xff\xfe", "\xff"));
	printf("0: <%d - %d> <abcd> <abcd>\n", strcmp("abcd", "abcd"), ft_strcmp("abcd", "abcd"));
	printf("1: <%d - %d> </xff> </xff/xfe>\n\n", strcmp("\xff", "\xff\xfe"), ft_strcmp("\xff", "\xff\xfe"));
	
	printf("Test ft_write:\n\n");
	char    *str = strdup("1234567");
	fd = open("write.txt", O_WRONLY | O_CREAT,  S_IREAD | S_IWRITE);
	ft_fd = open("ft_write.txt", O_WRONLY | O_CREAT,  S_IREAD | S_IWRITE);
	write(1, str, 7);
	printf(" - stdout org\n");
	ft_write(1, str, 7);
	printf(" - stdout my\n");
	write(fd, str, 7);
	ft_write(ft_fd, str, 7);
	printf(">>>> write file!\n");
	printf("error org: %zd, %s\n", write(21, str, 7), strerror(errno));
	printf("error my : %zd, %s\n\n", ft_write(21, str, 7), strerror(errno));
	close(fd);
	close(ft_fd);

	printf("Test ft_read\n\n");
	fd = open("input.txt", O_RDONLY);
	ft_fd = open("ft_input.txt", O_RDONLY);
	//next read test stdin
	/*
	printf("Please write 14 symbols and press <Enter>\n");
	read(0, buf1, 7);
	printf("stdin: >%s<\n", buf1);
	ft_read(0, buf2, 7);
	printf("stdin: >%s<\n", buf2);
	memset(buf1, 0, 109);
	memset(buf2, 0, 109);
	*/
	read(fd, buf1, 7);
	printf("file org: >%s<\n", buf1);
	ft_read(ft_fd, buf2, 7);
	printf("file my : >%s<\n", buf2);
	memset(buf1, 0, 109);
	memset(buf2, 0, 109);
	printf("error org: %zd, %s\n", read(21, buf1, 7), strerror(errno));
	printf("error my : %zd, %s\n\n", ft_read(21, buf2, 7), strerror(errno));

	printf("Test ft_strdup >result< <length of result>\n\n");
	printf("empty org: >%s< <%lu>\n", strdup(empty_str), strlen(strdup(empty_str)));
	printf("empty my : >%s< <%lu>\n", ft_strdup(empty_str), strlen(ft_strdup(empty_str)));
	printf("long org: >%s< <%lu>\n", strdup(long_str), strlen(strdup(long_str)));
	printf("long my : >%s< <%lu>\n", ft_strdup(long_str), strlen(ft_strdup(long_str)));

	exit(0);
	return (0);
}
