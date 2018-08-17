# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmushta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/04 13:50:01 by kmushta           #+#    #+#              #
#    Updated: 2018/02/04 13:50:03 by kmushta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PUSH_SWAP = push_swap
CHECKER = checker
RAND = randomizer
PS_SRCS = ft_bt.c ft_median.c ft_optimizer.c ft_p.c ft_plan_b.c ft_r.c \
	ft_rev.c ft_s.c ft_sort_check.c ft_sort_int_tab.c ft_stack.c \
	ft_stack_ops.c ft_stack_push_pop.c libft_funcs.c main_sort.c \
	push_swap.c ft_check_av.c ft_debug.c ft_strsplit.c ft_error.c \
	ft_print.c
C_SRCS = ft_bt.c ft_median.c ft_optimizer.c ft_p.c ft_plan_b.c ft_r.c \
	ft_rev.c ft_s.c ft_sort_check.c ft_sort_int_tab.c ft_stack.c \
	ft_stack_ops.c ft_stack_push_pop.c libft_funcs.c main_sort.c \
	checker.c ft_check_av.c ft_debug.c ft_strsplit.c ft_error.c \
	ft_print.c ft_app_ops.c
R_SRCS = ft_bt.c ft_median.c ft_optimizer.c ft_p.c ft_plan_b.c ft_r.c \
	ft_rev.c ft_s.c ft_sort_check.c ft_sort_int_tab.c ft_stack.c \
	ft_stack_ops.c ft_stack_push_pop.c libft_funcs.c main_sort.c \
	randomizer.c ft_check_av.c ft_debug.c ft_strsplit.c ft_error.c \
	ft_print.c ft_app_ops.c
PS_OBJ = $(PS_SRCS:.c=.o)
C_OBJ = $(C_SRCS:.c=.o)
R_OBJ = $(R_SRCS:.c=.o)

all: $(PUSH_SWAP) $(CHECKER) $(RAND) 

$(PUSH_SWAP): $(PS_OBJ)
	make -C ft_printf
	gcc -o $(PUSH_SWAP) $(PS_OBJ) -L. ft_printf/libftprintf.a

$(CHECKER): $(C_OBJ)
	gcc -o $(CHECKER) $(C_OBJ) -L. ft_printf/libftprintf.a

$(RAND): $(R_OBJ)
	gcc -o $(RAND) $(R_OBJ) -L. ft_printf/libftprintf.a

clean:
	make clean -C ft_printf
	rm -rf $(PS_OBJ) $(C_OBJ) $(R_OBJ)

fclean: clean
	make fclean -C ft_printf
	rm -rf $(PUSH_SWAP) $(CHECKER) $(RAND)

re: fclean all

ft_bt.o: ft_bt.c ft_stack.h ft_sort_utils.h ft_ops_def.h
	gcc $(CFLAGS) -c ft_bt.c -o ft_bt.o

ft_median.o: ft_median.c ft_sort_int_tab.h ft_stack.h
	gcc $(CFLAGS) -c ft_median.c -o ft_median.o

ft_optimizer.o: ft_optimizer.c ft_stack.h ft_ops_def.h
	gcc $(CFLAGS) -c ft_optimizer.c -o ft_optimizer.o

ft_p.o: ft_p.c ft_stack.h ft_ops_def.h
	gcc $(CFLAGS) -c ft_p.c -o ft_p.o

ft_plan_b.o: ft_plan_b.c push_swap.h ft_ops_def.h ft_stack.h
	gcc $(CFLAGS) -c ft_plan_b.c -o ft_plan_b.o

ft_r.o: ft_r.c ft_stack.h ft_ops_def.h
	gcc $(CFLAGS) -c ft_r.c -o ft_r.o

ft_rev.o: ft_rev.c push_swap.h ft_stack.h ft_ops_def.h ft_sort_utils.h
	gcc $(CFLAGS) -c ft_rev.c -o ft_rev.o

ft_s.o: ft_s.c ft_stack.h ft_ops_def.h
	gcc $(CFLAGS) -c ft_s.c -o ft_s.o

ft_sort_check.o: ft_sort_check.c ft_stack.h
	gcc $(CFLAGS) -c ft_sort_check.c -o ft_sort_check.o

ft_sort_int_tab.o: ft_sort_int_tab.c
	gcc $(CFLAGS) -c ft_sort_int_tab.c -o ft_sort_int_tab.o

ft_stack.o: ft_stack.c ft_stack.h
	gcc $(CFLAGS) -c ft_stack.c -o ft_stack.o

ft_stack_ops.o: ft_stack_ops.c ft_stack.h
	gcc $(CFLAGS) -c ft_stack_ops.c -o ft_stack_ops.o

ft_stack_push_pop.o: ft_stack_push_pop.c ft_stack.h
	gcc $(CFLAGS) -c ft_stack_push_pop.c -o ft_stack_push_pop.o

libft_funcs.o: libft_funcs.c
	gcc $(CFLAGS) -c libft_funcs.c -o libft_funcs.o

main_sort.o: main_sort.c ft_stack.h push_swap.h ft_sort_utils.h ft_ops_def.h
	gcc $(CFLAGS) -c main_sort.c -o main_sort.o

push_swap.o: push_swap.c ft_stack.h ft_ops_def.h libft_funcs.h push_swap.h
	gcc $(CFLAGS) -c push_swap.c -o push_swap.o

ft_check_av.o: ft_check_av.c
	gcc $(CFLAGS) -c ft_check_av.c -o ft_check_av.o

ft_debug.o: ft_debug.c ft_stack.h ft_ops_def.h libft_funcs.h
	gcc $(CFLAGS) -c ft_debug.c -o ft_debug.o -I ft_printf

ft_strsplit.o: ft_strsplit.c
	gcc $(CFLAGS) -c ft_strsplit.c -o ft_strsplit.o

ft_error.o: ft_error.c libft_funcs.h
	gcc $(CFLAGS) -c ft_error.c -o ft_error.o -I ft_printf

ft_print.o: ft_print.c libft_funcs.h ft_ops_def.h
	gcc $(CFLAGS) -c ft_print.c -o ft_print.o

checker.o: checker.c ft_ops_def.h push_swap.h libft_funcs.h ft_validate.h \
	ft_sort_utils.h ft_debug.h
	gcc $(CFLAGS) -c checker.c -o checker.o

ft_app_ops.o: ft_app_ops.c ft_validate.h ft_stack.h ft_ops_def.h \
	ft_sort_utils.h ft_debug.h
	gcc $(CFLAGS) -c ft_app_ops.c -o ft_app_ops.o

randomizer.o: randomizer.c libft_funcs.h
	gcc $(CFLAGS) -c randomizer.c -o randomizer.o -I ft_printf
