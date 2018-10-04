// COMP1521 18s2 mysh ... command history
// Implements an abstract data object

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

// This is defined in string.h
// BUT ONLY if you use -std=gnu99
//extern char *strdup(const char *s);

// Command History
// array of command lines
// each is associated with a sequence number

#define MAXHIST 21
#define MAXSTR  200

#define HISTFILE ".mymysh_history"

typedef struct _history_entry {
   int   seqNumber;
   char *commandLine;
} HistoryEntry;

typedef struct _history_list {
   int nEntries;
   HistoryEntry commands[MAXHIST];
} HistoryList;

HistoryList CommandHistory;

// initCommandHistory()
// - initialise the data structure
// - read from .history if it exists

void pushHistory(HistoryList); //declaration;

int initCommandHistory()
{
   // TODO

   return 0;

}

// [ 0 1 2 3 4 5]

// addToCommandHistory()
// - add a command line to the history list
// - overwrite oldest entry if buffer is full

void addToCommandHistory(char *cmdLine, int seqNo)
{
   // TODO
   //if seqNo <= maxhistory, :CommandHistory->commands[seqNo].seqNumber = seqNo
   //                        :strcpy(CommandHistory->commands[seqNo]->commandline, cmdLine)

   //else if seqNo > maxhistory,  pushHistory()
   //                             strcpy(CommandHistory->commands[MAXHIST - 1]->commandline, cmdLine)

   if (seqNo <= MAXHIST){
      CommandHistory.commands[seqNo].seqNumber = seqNo;
      strcpy(CommandHistory.commands[seqNo].commandLine, cmdLine);
   }
   else{
      pushHistory(CommandHistory);
      strcpy(CommandHistory.commands[MAXHIST - 1].commandLine, cmdLine);

   }
}

// showCommandHistory()
// - display the list of 

void showCommandHistory(FILE *outf)
{
   // TODO
}

// getCommandFromHistory()
// - get the command line for specified command
// - returns NULL if no command with this number

char *getCommandFromHistory(int cmdNo)
{
   // TODO

   return "charstar";
}

// saveCommandHistory()
// - write history to $HOME/.mymysh_history

void saveCommandHistory()
{


   // TODO

}

// cleanCommandHistory
// - release all data allocated to command history

void cleanCommandHistory()
{
   // TODO
}

void pushHistory(HistoryList list){
   int i = 1;

   while(i < MAXHIST - 1){
      strcpy(list.commands[i].commandLine, list.commands[i+1].commandLine);
      list.commands[i].seqNo = list.commands[i+1].commandLine;
      i++;
   }

}
