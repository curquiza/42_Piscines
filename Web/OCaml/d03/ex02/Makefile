# Nom de l'executable
NAME = cipher

# Sources
SOURCES = cipher.ml uncipher.ml
OBJS = $(SOURCES:.ml=.cmo)
OPTOBJS = $(SOURCES:.ml=.cmx)
TMP = $(OBJS) $(OPTOBJS) $(SOURCES:.ml=.cmi) $(SOURCES:.ml=.o)

# Compilateurs
CAMLC = ocamlc
CAMLOPT = ocamlopt
CAMLDEP = ocamldep

### RULES ######################################################################

all: $(NAME)

$(NAME): opt byt
	ln -s $(NAME).byt $(NAME)

byt: $(NAME).byt
opt: $(NAME).opt

$(NAME).byt: $(OBJS)
	$(CAMLC) -o $@ $(LIBS) $^

$(NAME).opt: $(OPTOBJS)
	$(CAMLOPT) -o $@ $(LIBS:.cma=.cmxa) $^

# Compilation
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

re: fclean all
