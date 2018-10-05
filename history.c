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
   CommandHistory.nEntries = 0;
   FILE * historyFile = (fopen("$HOME/.mymysh_history", "r"));

   int i = 1;
   if (historyFile != NULL){
      while(fscanf(historyFile, "%d %s", &CommandHistory.commands[i].seqNumber,
                                         CommandHistory.commands[i].commandLine) 
                                         != EOF){


         CommandHistory.nEntries++;
         i++;

      }
   }

   return 0;
      
}

// [ 0 1 2 3 4 5]//

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

   if (seqNo < MAXHIST){
      CommandHistory.commands[seqNo].seqNumber = seqNo;
      strcpy(CommandHistory.commands[seqNo].commandLine, cmdLine);
      CommandHistory.nEntries++;
   }
   else{
      pushHistory(CommandHistory);
      strcpy(CommandHistory.commands[MAXHIST - 1].commandLine, cmdLine);
      CommandHistory.commands[MAXHIST-1].seqNumber = seqNo;

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

void getCommandFromHistory(int cmdNo, char* line)
{
   // TODO

   int i = 1;
   while (i < MAXHIST){

      if(cmdNo == CommandHistory.commands[i].seqNumber){
         strcpy(line, CommandHistory.commands[i].commandLine);

      }
      i++;
   }



   
}

// saveCommandHistory()
// - write history to $HOME/.mymysh_history

void saveCommandHistory()
{

   int i = 1 ;
   FILE* saveto = fopen("$HOME/.mymysh_history", "w");
   while (i < MAXHIST){

      fprintf(saveto, " %3d  %s\n", CommandHistory.commands[i].seqNumber,
                                    CommandHistory.commands[i].commandLine);

      i++;
   }
   fclose(saveto);

   // TODO

}

// cleanCommandHistory
// - release all data allocated to command history

void cleanCommandHistory()
{
   // TODO
   int i = 0;
   while(i < MAXHIST){

      i++;
   }
   
}

void pushHistory(HistoryList list){
   int i = 1;

   while(i < MAXHIST - 1){
      strcpy(list.commands[i].commandLine, list.commands[i+1].commandLine);
      list.commands[i].seqNumber = list.commands[i+1].seqNumber;
      i++;
   }

}
