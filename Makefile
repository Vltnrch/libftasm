# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 11:41:38 by vroche            #+#    #+#              #
#    Updated: 2015/04/02 18:21:38 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

NFLAGS = -f macho64

S = ft_bzero.s \
	ft_strcat.s \
	ft_isalpha.s \
	ft_isdigit.s \
	ft_isalnum.s \
	ft_isascii.s \
	ft_isprint.s \
	ft_toupper.s \
	ft_tolower.s \
	ft_puts.s \
	\
	ft_strlen.s \
	ft_memset.s \
	ft_memcpy.s \
	ft_strdup.s \
	ft_cat.s \
	\
	ft_strcpy.s \
	ft_strclr.s \
	ft_strnew.s \
	ft_isspace.s \
	ft_islower.s \
	ft_isupper.s

O = $(S:.s=.o)

$(NAME): $(O)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

all: $(NAME)

%.o:%.s
	nasm $(NFLAGS) $<

clean:
	rm -f $(O) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
