##############################################################################
#
# The Linux-GCC/DOS-GJPP Makefile
#
##############################################################################

#
# Object files.
#

OBJ = main.o actor.o dungeon.o sysdep.o error.o game.o misc.o monster.o player.o sprite.o map.o draw_map.o

#
# Compiler stuff -- adjust to your system.
#

# Linux

CC     = gcc
LFLAGS = -g -o edom -lncurses -lSDL -lSDL_image
CFLAGS = -g -Wall -Dlinux -DSDL_GFX -I/usr/include/SDL

# DOS

#CC = gcc
#LFLAGS = -o edom
#CFLAGS = -Wall -O2

#
# Targets.
#

edom: $(OBJ) 
	gcc $(OBJ) $(LFLAGS)

depend:
	@-rm makefile.dep
	@echo Creating dependencies.
	@for i in *.c; do $(CC) $(INC) -MM $$i; done > makefile.dep
	@echo Done.

clean:
	rm *.o edom

count:
	wc *.c *.h Makefile

#
# Dependencies.
#

include makefile.dep

#
# The default rule.
#

.c.o:
	gcc $(CFLAGS) -c $<

