/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <oozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:24:44 by oozkaya           #+#    #+#             */
/*   Updated: 2018/03/20 10:33:38 by oozkaya          ###   ########.fr       */
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
	//我是一只猫。
	//AS_PRINTF
	char *str1;
	char *str2;
	printf("as_ret = %d\n", asprintf(&str1, "|%S|\n", L"我是一只猫。"));
	printf("ft_as_ret = %d\n", ft_asprintf(&str2, "|%S|\n", L"我是一只猫。"));
	printf("str1_ret = %d\n", printf("|str1 = %s|\n", str1));
	printf("str2_ret = %d\n", printf("|str2 = %s|\n", str2));
//	printf("%d\n", ft_printf("|{magenta}%s{eoc}{cyan}{{red}}{eoc}{green}ONUR{eoc}{yellow}{1234567890987654321}{}{eoc}{123}{{green}}{red}%drealred{eoc}|\n", "magenta", 25));
	printf("%d\n", ft_printf("Test couleurs : %sBleu%s, %sViolet%s, %sRouge%s, %sNoir%s, Rien\n", BLUE, EOC, MAGENTA, EOC, RED, EOC, BLACK, EOC));
	printf("%d\n", ft_printf("Test couleurs : Bleu, Violet, Rouge, Noir, Rien\n"));
	int		var = 125;
	printf("%d\n", printf("|PRINTF : s = %s, p = %p, d = %d|\n", "test", &var, var));
	printf("%d\n", ft_printf("|FT_PRINTF : s = %s, p = %p, d = %d|\n", "test", &var, var));
	printf("%d\n", printf("|PRINTF : %d, %d, %d, %d, %d|\n", 1, 2, 3, 4, 5));
	printf("%d\n", ft_printf("|FT_PRINTF : %d, %d, %d, %d, %d|\n", 1, 2, 3, 4, 5));
	printf("%d\n", printf("|PRINTF : %C, %C, %C, %C, %C|\n", L'α', L'β', L'γ', L'δ', L'ζ'));
	printf("%d\n", ft_printf("|FT_PRINTF : %C, %C, %C, %C, %C|\n", L'α', L'β', L'γ', L'δ', L'ζ'));
	printf("%d\n", printf("|PRINTF : S = %S, D = %D, i = %i, u = %u, U = %U,\nPRINTF : o = %o, O = %O, x = %x, X = %X, c = %c|\n", L"我是一只猫。", 9223372036854775807, 42, 100, 9223372036854775807, 42, 42, 42, 42, 'c'));
	printf("%d\n", ft_printf("|FT_PRINTF : S = %S, D = %D, i = %i, u = %u, U = %U,\nFT_PRINTF :  o = %o, O = %O, x = %x, X = %X, c = %c|\n", L"我是一只猫。", 9223372036854775807, 42, 100, 9223372036854775807, 42, 42, 42, 42, 'c'));
	return (0);
}
