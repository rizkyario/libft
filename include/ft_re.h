/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:24:05 by rnugroho          #+#    #+#             */
/*   Updated: 2018/04/13 15:45:57 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RE_H
# define FT_RE_H

# define MAX_REGEXP_OBJECTS 30
# define MAX_CHAR_CLASS_LEN 40

enum
{
	UNUSED,
	DOT,
	BEGIN,
	END,
	QUESTIONMARK,
	STAR,
	PLUS,
	CHAR,
	CHAR_CLASS,
	INV_CHAR_CLASS,
	DIGIT,
	NOT_DIGIT,
	ALPHA,
	NOT_ALPHA,
	WHITESPACE,
	NOT_WHITESPACE
};

typedef struct regex_t
{
	unsigned char  type;
	union
	{
		unsigned char  ch;
		unsigned char* ccl;
	};
} regex_t;

typedef struct regex_t* re_t;

re_t	ft_re_compile(const char* pattern);
int 	ft_re_matchp(re_t pattern, const char* text);
int		ft_re_match(const char* pattern, const char* text);
int		matchpattern(regex_t* pattern, const char* text);
int 	matchcharclass(char c, const char* str);
int 	matchstar(regex_t p, regex_t* pattern, const char* text);
int 	matchplus(regex_t p, regex_t* pattern, const char* text);
int 	matchone(regex_t p, char c);
int 	matchdigit(char c);
int 	matchalpha(char c);
int		matchalphanum(char c);
int 	matchwhitespace(char c);
int 	matchmetachar(char c, const char* str);
int 	matchrange(char c, const char* str);
int 	ismetachar(char c);
int		ft_re_matchn(const char* pattern, const char* text, int len);
char	*ft_re_match_capture(const char *pattern, const char *group,
		const char *text);
#endif