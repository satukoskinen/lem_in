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


all:
			+@make -C $(RAW)
			+@make -C $(MEMORY)
			+@make -C $(ARR)
			+@make -C $(LIN)
			+@make -C $(PARR)
			+@make -C $(CSTR)
			+@make -C $(GRAPH)
			+@make -C $(MAP)
			+@make -C $(MATH)
			+@make -C $(PRINT)
			+@make -C $(STRING)
			+@make -C $(CHECKS)
			+@make -C $(SYSTEM)
			@mkdir -p $(OBJ)
			@mv $(RAW)obj/*.o $(OBJ)
			@mv $(MEMORY)obj/*.o $(OBJ)
			@mv $(ARR)obj/*.o $(OBJ)
			@mv $(LIN)obj/*.o $(OBJ)
			@mv $(PARR)obj/*.o $(OBJ)
			@mv $(CSTR)obj/*.o $(OBJ)
			@mv $(GRAPH)obj/*.o $(OBJ)
			@mv $(MAP)obj/*.o $(OBJ)
			@mv $(MATH)obj/*.o $(OBJ)
			@mv $(PRINT)obj/*.o $(OBJ)
			@mv $(PRINT)obj/sub/*.o $(OBJ)
			@mv $(STRING)obj/*.o $(OBJ)
			@mv $(CHECKS)obj/*.o $(OBJ)
			@mv $(SYSTEM)obj/*.o $(OBJ)
			@ar -rcs $(NAME) $(OBJ)*.o
			@echo "\\n\033[32;1mCORE ACTIVATED \033[0m \\n"

clean:
			@make clean -C $(RAW)
			@make clean -C $(MEMORY)
			@make clean -C $(ARR)
			@make clean -C $(LIN)
			@make clean -C $(PARR)
			@make clean -C $(CSTR)
			@make clean -C $(GRAPH)
			@make clean -C $(MAP)
			@make clean -C $(MATH)
			@make clean -C $(PRINT)
			@make clean -C $(STRING)
			@make clean -C $(CHECKS)
			@make clean -C $(SYSTEM)
			@echo "\\n\033[32;1mCORE DEACTIVATED \033[0m \\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@make fclean -C $(RAW)
			@make fclean -C $(MEMORY)
			@make fclean -C $(ARR)
			@make fclean -C $(LIN)
			@make fclean -C $(PARR)
			@make fclean -C $(CSTR)
			@make fclean -C $(GRAPH)
			@make fclean -C $(MAP)
			@make fclean -C $(MATH)
			@make fclean -C $(PRINT)
			@make fclean -C $(STRING)
			@make fclean -C $(CHECKS)
			@make fclean -C $(SYSTEM)

re:			fclean all

.PHONY: 	all fclean clean re
