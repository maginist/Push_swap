# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maginist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 16:58:32 by maginist          #+#    #+#              #
#    Updated: 2019/02/20 11:44:54 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
OBJ_PATH1 = ./obj_c
OBJ_PATH2 = ./obj_ps
SRC_PATH1 = ./src_c
SRC_PATH2 = ./src_ps

SRCS1 = arg_stock.c\
		inst_stock.c\
		init_fct.c\
		ft_display.c\
		use_dr.c\
		use_p_r.c\
		use_s.c\
		list_sort.c\
		free_all_list.c\
		checker.c

SRCS2 = push_swap.c\
		arg_stock.c\
		use_dr.c\
		use_s.c\
		use_p_r.c\
		free_all_list.c\
		ft_algo3.c\
		ft_algo3_rev.c\
		ft_algoplus.c\
		ft_algo10.c\
		norm_killer.c\
		list_sort.c

OBJ_NAME1 = $(SRCS1:.c=.o)
OBJ_NAME2 = $(SRCS2:.c=.o)
	LIB = libft/
	CCF = gcc -g3 -Wall -Werror -Wextra
	INC = -I./includes
	SRC1 = $(addprefix $(SRC_PATH1)/,$(SRCS1))
	OBJ1 = $(addprefix $(OBJ_PATH1)/,$(OBJ_NAME1))
	SRC2 = $(addprefix $(SRC_PATH2)/,$(SRCS2))
	OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

all: $(NAME1) $(NAME2)


$(NAME1): $(OBJ_PATH1) $(OBJ1) $(LIB)
	make -C $(LIB) -j
	cp libft/libft.a ./
	$(CCF) -o $(NAME1) $(OBJ1) libft.a

$(NAME2): $(OBJ_PATH2) $(OBJ2)
	$(CCF) -o $(NAME2) $(OBJ2) libft.a

$(OBJ_PATH1)/%.o : $(SRC_PATH1)/%.c
	$(CCF) -c $? $(INC) -o $@

$(OBJ_PATH2)/%.o : $(SRC_PATH2)/%.c
	$(CCF) -c $? $(INC) -o $@

clean:
	make -C $(LIB) clean
	rm -rf ./obj_c
	rm -rf ./obj_ps
	rm -rf ./libft.a

$(OBJ_PATH1):
	mkdir -p $(OBJ_PATH1)

$(OBJ_PATH2):
	mkdir -p $(OBJ_PATH2)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all
