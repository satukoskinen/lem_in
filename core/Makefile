NAME		=	libcore.a

ARR 		=	core_containers/array/
PARR 		=	core_containers/parray/
MAP 		=	core_containers/map/
MEMORY 		=	core_standard/memory/
RAW 		=	core_containers/raw/
PRINT		=	core_standard/print/
CHECKS		=	core_standard/checks/
LIN 		=	core_math/linear_algebra/
MATH 		=	core_math/math/
GRAPH 		=	core_math/graph/
CSTR 		=	core_string/cstring/
STRING		=	core_string/string/
SYSTEM		=	core_system/

RM			=	rm -rf

OBJ			=	obj/
MFLAGS		=	--jobs --directory

all:
			+@make $(MFLAGS) $(RAW)
			+@make $(MFLAGS) $(MEMORY)
			+@make $(MFLAGS) $(ARR)
			+@make $(MFLAGS) $(LIN)
			+@make $(MFLAGS) $(PARR)
			+@make $(MFLAGS) $(CSTR)
			+@make $(MFLAGS) $(GRAPH)
			+@make $(MFLAGS) $(MAP)
			+@make $(MFLAGS) $(MATH)
			+@make $(MFLAGS) $(PRINT)
			+@make $(MFLAGS) $(STRING)
			+@make $(MFLAGS) $(CHECKS)
			+@make $(MFLAGS) $(SYSTEM)
			@mkdir -p $(OBJ)
			@cp $(RAW)obj/*.o $(OBJ)
			@cp $(MEMORY)obj/*.o $(OBJ)
			@cp $(ARR)obj/*.o $(OBJ)
			@cp $(LIN)obj/*.o $(OBJ)
			@cp $(PARR)obj/*.o $(OBJ)
			@cp $(CSTR)obj/*.o $(OBJ)
			@cp $(GRAPH)obj/*.o $(OBJ)
			@cp $(MAP)obj/*.o $(OBJ)
			@cp $(MATH)obj/*.o $(OBJ)
			@cp $(PRINT)obj/*.o $(OBJ)
			@cp $(PRINT)obj/sub/*.o $(OBJ)
			@cp $(STRING)obj/*.o $(OBJ)
			@cp $(CHECKS)obj/*.o $(OBJ)
			@cp $(SYSTEM)obj/*.o $(OBJ)
			@ar -rcs $(NAME) $(OBJ)*.o
			@echo "\\n\033[32;1mCORE ACTIVATED \033[0m \\n"

clean:
			@make clean $(MFLAGS) $(RAW)
			@make clean $(MFLAGS) $(MEMORY)
			@make clean $(MFLAGS) $(ARR)
			@make clean $(MFLAGS) $(LIN)
			@make clean $(MFLAGS) $(PARR)
			@make clean $(MFLAGS) $(CSTR)
			@make clean $(MFLAGS) $(GRAPH)
			@make clean $(MFLAGS) $(MAP)
			@make clean $(MFLAGS) $(MATH)
			@make clean $(MFLAGS) $(PRINT)
			@make clean $(MFLAGS) $(STRING)
			@make clean $(MFLAGS) $(CHECKS)
			@make clean $(MFLAGS) $(SYSTEM)
			@echo "\\n\033[32;1mCORE DEACTIVATED \033[0m \\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@make fclean $(MFLAGS) $(RAW)
			@make fclean $(MFLAGS) $(MEMORY)
			@make fclean $(MFLAGS) $(ARR)
			@make fclean $(MFLAGS) $(LIN)
			@make fclean $(MFLAGS) $(PARR)
			@make fclean $(MFLAGS) $(CSTR)
			@make fclean $(MFLAGS) $(GRAPH)
			@make fclean $(MFLAGS) $(MAP)
			@make fclean $(MFLAGS) $(MATH)
			@make fclean $(MFLAGS) $(PRINT)
			@make fclean $(MFLAGS) $(STRING)
			@make fclean $(MFLAGS) $(CHECKS)
			@make fclean $(MFLAGS) $(SYSTEM)

re:			fclean all

.PHONY: 	all fclean clean re
