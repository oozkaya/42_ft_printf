/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:24:44 by oozkaya           #+#    #+#             */
/*   Updated: 2018/02/23 15:14:28 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	//char *str = "onuraydin";
	//char *str2 = "onuraydin12";
	//printf("size = %ld", str2 - str);
	//int		ret;
	//printf("Base 8: %s\n", ft_utoa_base(SIZE_MAX, 8));
	//printf("Base:10 %s\n", ft_lltoa(9223372036854775807, 10));
	/*printf("Base:10 %s\n", ft_itoa_base(-1567, 10));
	  printf("Base:2 %s\n", ft_itoa_base(1567, 2));
	  printf("Base:8 %s\n", ft_itoa_base(1567, 8));
	  printf("Base:16 %s\n", ft_itoa_base(1567, 16));
	  */
	//char *format = "123%test5";
	//char *conv = ft_strchr(format, '%');
	//ft_putstr(conv);
	//char conv = 'D';
	//printf("conv = %c\n", conv|0x20);
	///////////int		test = 125;
	//我是一只猫。
	/*char value1 = '我'¾;
	wchar_t value2 = L's';
	char *value3 = "我是一只猫。";
	wchar_t *value4 = L"ssssssssss";
	printf("%d\n", printf("|C = %C|\n", value1));*/
	//	wchar_t value = L'¾';☭
	//	char *value3 = "我是一只猫。";
	//	printf("%d\n", printf("|%lc|\n"));
	//"☭|☭"
	//printf("%d\n", ft_printf("|%C|\n", 0xDE11));
/*	//AS_PRINTF
	char *str1;
	char *str2;
	printf("as_ret = %d\n", asprintf(&str1, "|%S|\n", L"\xe2\x98\xadbar\xe2\x98\xad"));
	printf("ft_as_ret = %d\n", ft_asprintf(&str2, "|%S|\n", L"\xe2\x98\xadbar\xe2\x98\xad"));
	printf("str1_ret = %d\n", printf("|str1 = %s|\n", str1));
	printf("str2_ret = %d\n", printf("|str2 = %s|\n", str2));*/
/*	//SN_PRINTF
	char *str1;
	char *str2;
	str1 = malloc(sizeof(char) * 16);
	str2 = malloc(sizeof(char) * 16);
	printf("sn_ret = %d\n", snprintf(str1, 16, "|%S|\n", L"\xe2\x98\xadbar\xe2\x98\xad"));
	printf("ft_sn_ret = %d\n", ft_snprintf(str2, 16, "|%S|\n", L"\xe2\x98\xadbar\xe2\x98\xad"));
	printf("str1_ret = %d\n", printf("|str1 = %s|\n", str1));
	printf("str2_ret = %d\n", printf("|str2 = %s|\n", str2));*/
	//printf("%d\n", printf("|%s%X{red}AYDIN{1234567890987654321}{}{123}{green}onur|\n", "test", 42));
	//printf("%d\n", ft_printf("|{magenta}%s{eoc}{black}%X{eoc}{cyan}{{red}}{eoc}{green}AYDIN{eoc}{yellow}{1234567890987654321}{}{eoc}{123}{eoc}{{green}}{red}onur{eoc}|\n", "test", 42));
	// BINAIRE
//	printf("%d\n", printf("|%b|\n", 42));
//	printf("%d\n", ft_printf("|%08b|\n", 42));
	//	printf("%d\n", printf("@moulitest: %#20.x %#20.0x\n", 0, 0));
	//	printf("%d\n", ft_printf("@moulitest: %#20.x %#20.0x\n", 0, 0));
	//	printf("%d\n", printf("|%010.ji|\n", 32767));
				//printf("%d\n", printf("|%*3d|\n", 5, 0));
	//printf("%d\n", printf("|s = %s|\n", value3));qthjlzv
	//	printf("%d\n", ft_printf("|%lc|\n"));
				//printf("%d\n", ft_printf("|%*3d|\n", 5, 0));
				//printf("%d\n", printf("|%15f|\n", 4.2));
//	while (1);
					//ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
					//	   L"A α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
					//	   L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
					/*unsigned int o = value;
	unsigned char octet;
	octet = 0x80 | (o & 0x3F);
	write(1, &octet, 1);
	octet = 0x80 | (o >> 6 & 0x3F);
	write(1, &octet, 1);
	octet = 0xE0 | (o >> 12 & 0x0F);
	write(1, &octet, 1);*/
					//printf("RET = %d\n", ret);
					//ret = ft_printf("|%d|\n", 1);
					//printf("RET = %d\n", ret);
					/*int fd = open("Makefile", O_RDONLY);
	  char *line;
	  while (get_next_line(fd, &line))
	  ft_putendl(line);
	//ft_putstr(line);*/
	int		var = 125;
	printf("%d\n", printf("|s = %s, p = %p, d = %d|\n", "test", &var, var));
	printf("%d\n", ft_printf("|s = %s, p = %p, d = %d|\n", "test", &var, var));
	printf("%d\n", printf("|%d, %d, %d, %d, %d|\n", 1, 2, 3, 4, 5));
	printf("%d\n", ft_printf("|%d, %d, %d, %d, %d|\n", 1, 2, 3, 4, 5));
	printf("%d\n", printf("|%C, %C, %C, %C, %C|\n", L'α', L'β', L'γ', L'δ', L'ζ'));
	printf("%d\n", ft_printf("|%C, %C, %C, %C, %C|\n", L'α', L'β', L'γ', L'δ', L'ζ'));
	printf("%d\n", printf("|S = %S, D = %D, i = %i, u = %u, U = %U, o = %o, O = %O, x = %x, X = %X, c = %c|\n", L"我是一只猫。", 9223372036854775807, 42, 100, 9223372036854775807, 42, 42, 42, 42, 'c'));
	printf("%d\n", ft_printf("|S = %S, D = %D, i = %i, u = %u, U = %U, o = %o, O = %O, x = %x, X = %X, c = %c|\n", L"我是一只猫。", 9223372036854775807, 42, 100, 9223372036854775807, 42, 42, 42, 42, 'c'));
	return (0);
}

/*int		main(void)
  {
  int		j;
  int		ret;


//printf("testttttt ; %2$*1$d", 8, 57);
j = 4;
ret = ft_printf("|testons le numero %0-3d et le numero %0-3d|\n", j, 25);
printf("RET = %d\n", ret);
//ft = ft_printf("testons le numero %d et le numero %d\n", j, 25);
printf("FT2 = %d\n", ft);
ft = ft_printf("testons le numero %d et le numero %d\n", j, 25);
printf("FT3 = %d\n", ft);
ft = ft_printf("testons le numero %d et le numero %d\n", j, 25);
printf("FT4 = %d\n", ft);
//printf("4567 |%-10]5d| plip\n", 12);
//printf("4567 |%10]5d| plip\n", 12);
//printf("|%10.5d|\n", -12);
//printf("|%10d|\n", -12);
//printf("|%010d|\n", -12); 
//printf("|%-15d|\n", 124567);
//printf("|%-010.5d|\n", -12);
printf("|%-+8X|\n", 42);
ret = ft_printf("|testons le numero %-05d et le numero %-05d|\n", j , -25);
printf("RET FT = %d\n", ret);
ret = printf("|testons le numero %-05d et le numero %-05d|\n", j , -25);
printf("RET PF = %d\n", ret);
return (0);
}*/
