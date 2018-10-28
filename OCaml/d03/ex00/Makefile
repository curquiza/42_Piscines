# Nom de l'executable
NAME = ft_graphics

# Sources
SOURCES = ft_graphics.ml
OBJS = $(SOURCES:.ml=.cmo)
OPTOBJS = $(SOURCES:.ml=.cmx)
TMP = $(OBJS) $(OPTOBJS) $(SOURCES:.ml=.cmi) $(SOURCES:.ml=.o)

# Compilateurs
CAMLC = ocamlc
CAMLOPT = ocamlopt
CAMLDEP = ocamldep

# Libs
LIBS = $(WITHGRAPHICS)
WITHGRAPHICS = graphics.cma -cclib -lGraphics

### RULES ######################################################################

all: depend $(NAME)

$(NAME): opt byt
	ln -s $(NAME).byt $(NAME)

byt: $(NAME).byt
opt: $(NAME).opt

$(NAME).byt: $(OBJS)
	$(CAMLC) -o $@ $(LIBS) $^

$(NAME).opt: $(OPTOBJS)
	$(CAMLOPT) -o $@ $(LIBS:.cma=.cmxa) $^

# Compilation
#.SUFFIXES:
#.SUFFIXES: .ml .mli .cmo .cmi .cmx
#
#.ml.cmo:
#	$(CAMLC) -c $<
#
#.mli.cmi:
#	$(CAMLC) -c $<
#
#.ml.cmx:
#	$(CAMLOPT) -c $<

%.cmo: %.ml
	$(CAMLC) $(CFLAGS) -c $< -o $@

%.cmi: %.ml
	$(CAMLC) $(CFLAGS) -c $< -o $@

%.cmx: %.ml
	$(CAMLOPT) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(TMP)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME).opt
	rm -f $(NAME).byt

depend: .depend
	 $(CAMLDEP) $(SOURCES) > .depend

re: fclean all

include .depend
