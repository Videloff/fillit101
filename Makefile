NAME        = fillit

INC_P       = -I./includes/
SRCS_P      = ./srcs/
OBJS_P      = ./objs/
LIB_P       = -C libft/

CLR_D       = \033[0m
BLINK       = \033[5m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
PURPLE      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m
WRN         = $(BLINK) $(WHITE) \033[41m

GCC         = gcc -Wall -Wextra -Werror 
LFT         = -L./libft/ -lft

SRCS        = main.c\
			  check_file.c\
			  listing.c\
			  resolver.c\
			  extend_board.c\
			  display.c
				
OBJS        = $(SRCS:.c=.o)

SRC         = $(addprefix $(SRCS_P)/,$(SRCS))
OBJ         = $(addprefix $(OBJS_P), $(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n                  $(WRN)WATCH OUT !$(CLR_D) \n\n$(UNDERLINE)$(PURPLE)Would you $(RED)PLEASE$(PURPLE) let me compile all those library ????\n\n$(CLR_D)"
	@make $(LIB_P)
	@echo "\n                    $(BLUE)\033[42mJOB DONE !$(CLR_D)\n"
	@echo "      $(GREEN)$(BLINK)Now I'll just compile the entire project...\n$(CLR_D)"
	@$(GCC) $(OBJ) $(LFT) -o $@
	@echo "                $(BLINK)$(BLANK)\033[41mCOMPILATION DONE !"

$(OBJS_P)%.o: $(SRCS_P)%.c
	@echo "\n             $(CYAN)Generating objects files..."
	@mkdir $(OBJS_P) 2> /dev/null || true
	@$(GCC) -o $@ -c $<

clean:
	@echo "\n                  $(WRN)WATCH OUT !$(CLR_D)\n\n $(YELLOW)Io soy SUPPRESSING all the OBJECT files$(CLR_D)\n"
	@make clean $(LIB_P)
	@rm -rf $(OBJ)
	@rmdir $(OBJS_P)

fclean:
	@echo "\n                  $(WRN)WATCH OUT !$(CLR_D)\n\n $(YELLOW)Io soy SUPPRESSING all the OBJECT files + exectutor$(CLR_D)\n"
	@make fclean $(LIB_P)
	@rm -rf $(NAME)
	@rm -rf $(OBJ)

re: fclean all
