# Permet d'utiliser make directement à la racine en renvoyant vers le make de src

CLEAN = clean

all:
	+$(MAKE) -C src

.PHONY: clean
clean:
	+$(MAKE) $(CLEAN) -C src