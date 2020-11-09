# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corentin <corentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 15:18:14 by cochapel          #+#    #+#              #
#    Updated: 2020/11/09 18:57:27 by corentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= 	main.c \
						utils/ft_sub_after_char.c \
						utils/ft_sub_before_char.c \
						utils/ft_sp_split.c \
						utils/tab/ft_add_to_tab.c \
						utils/ft_transform.c \
						utils/tab/ft_copy_tab.c \
						utils/tab/ft_copy_tab_transformed.c \
						utils/tab/ft_print_tab.c \
						utils/tab/ft_remove_back_tab.c \
						utils/tab/ft_remove_front_tab.c \
						utils/tab/ft_remove_from_tab.c \
						utils/tab/ft_replace_from_tab.c \
						utils/tab/ft_tab_join.c \
						utils/tab/ft_join_two_tabs.c \
						utils/str/ft_str_delete_segment.c \
						utils/str/ft_str_add_segment.c \
						utils/str/ft_str_replace_segment.c \
						utils/str/ft_char_to_str.c \
						utils/file_and_dir/ft_does_file_exist.c \
						utils/file_and_dir/ft_does_dir_exist.c \
						utils/ft_get_path.c \
						utils/ft_tomaj.c \
						chain_list/cmd.c \
						chain_list/tmp.c \
						chain_list/ft_tab_to_tmp.c \
						chain_list/ft_tmp_to_cmd.c \
						var_env/ft_find_in_env.c \
						var_env/ft_return_good_env.c \
						var_env/ft_check_var_env.c \
						var_env/ft_replace_env.c \
						var_env/ft_get_var_env_content.c \
						free/ft_free.c \
						free/ft_free_data.c \
						free/ft_free_error.c \
						free/ft_free_cmd.c \
						free/ft_free_tmp.c \
						programme/ft_programme.c \
						programme/ft_get_input.c \
						programme/ft_get_actions.c \
						programme/ft_do_actions.c \
						programme/ft_reverse_actions.c \
						cmd/pwd/ft_pwd.c \
						cmd/env/ft_env.c \
						cmd/exit/ft_exit.c \
						cmd/echo/ft_echo.c \
						cmd/cd/ft_cd.c \
						cmd_options/ft_check_options_echo.c \
						redirections/ft_check_redirections.c \
						redirections/ft_fork.c \
						errors/ft_errors.c \
						errors/input_errors/ft_check_input.c \

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