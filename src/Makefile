ECHO = @echo
GCC = g++
RM = @rm -f
CCFLAGS = -c -g -O1 -ansi -pedantic -Wall -std=c++11 
MAP = -DMAP #Commenter cette ligne si on veut compiler sans le mode Mise Au Point
BIN = ../bin
EXE = analog
OBJETS = $(SRC:.cpp=.o)
SRC = $(wildcard *.cpp) #Récupère tous les fichiers .cpp du répertoire courant
OBJETS_DIR = $(OBJETS:%=$(BIN)/%)
EXE_DIR = $(EXE:%=$(BIN)/%)
LIBRAIRIES = 

$(EXE_DIR) : $(OBJETS_DIR)
	$(ECHO) "-Edition des liens de $(EXE)-"
	$(GCC) -o $@ $^ $(LIBRAIRIES)
	
$(BIN)/%.o:%.cpp
	$(ECHO) "-Compilation de $<- "
	$(GCC) $(CCFLAGS) $(MAP) -lstdc++ -o $@ $<

.PHONY: clean #Pour que make clean fonctionne même si un fichier s'appelant clean existe
clean:
	$(ECHO) "-Nettoyage-"
	$(RM) $(OBJETS_DIR) $(EXE_DIR)
