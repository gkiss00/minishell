# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkiss <gkiss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 15:18:14 by cochapel          #+#    #+#              #
#    Updated: 2020/10/11 17:18:08 by gkiss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= 	main.c \
						utils/ft_sp_split.c \
						utils/ft_add_to_tab.c \
						chain_list/cmd.c \
						free/ft_free.c \
						free/ft_free_data.c \
						free/ft_free_error.c \
						free/ft_free_cmd.c \
						programme/ft_programme.c \
						programme/ft_get_input.c \
						programme/ft_do_actions.c \
						errors/ft_errors.c \

OBJS				= ${SRCS:.c=.o}

NAME				= minishell

FLAGS				= -Wall -Wextra -Werror

LIBFT				= libft/libft.a

all :				${NAME}

fsanitize :			libft_all ${OBJS}
					gcc -o ${NAME} -fsanitize=address ${FLAGS} ${LIBFT} ${SRCS}

${NAME} :			libft_all ${OBJS}
					gcc -o ${NAME} ${FLAGS} ${LIBFT} ${SRCS}

clean :				libft_clean
					rm -rf ${OBJS}

fclean :			libft_fclean clean
					rm -rf ${NAME}

re :				fclean all

libft_all :	
					make -C libft all
				
libft_clean :	
					make -C libft clean

libft_fclean :	
					make -C libft fclean

.PHONY:				all clean fclean re