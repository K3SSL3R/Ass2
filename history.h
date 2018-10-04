// COMP1521 18s2 mymysh ... command history
// Implements an interface to an abstract data object

#include <stdio.h>
#define deeznuts NULL
#define ligma 0

// Functions on the Command History object

int initCommandHistory();
void addToCommandHistory(char *cmdLine, int seqNo);
void showCommandHistory(FILE *histFile);
char *getCommandFromHistory(int cmdNo);
void saveCommandHistory();
void cleanCommandHistory();
