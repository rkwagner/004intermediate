/*
 *Author: Ryan Wagner
 *Date: August 20, 2014
 *Description: Basic calculator in c.
 */

#include <stdio.h>
#include <string.h>

//Begin function prototypes.
void menu(char * input);
void push(char ** dest, char * src);
char * pop(char ** src);
char ** list(char * input);
char ** stack(char ** list);
int doMath(char ** stack);
//End function prototypes.

int main(void){
  char input[256];
  while(strcmp(input,"quit")){
    menu(input);
  }
  return 0;
}
//Display user menu.
void menu(char * input){
  (void)printf(">");
  (void)fgets(input, 256, stdin);
}
//Push onto stack.
void push(char ** dest, char * src){

}
//Pop from stack.
char * pop(char ** src){
  return *src;
}
//Read input to a string of strings.
//Return the string of strings.
char ** list(char * input){
  char * key = "!%^&*()/+-";
  return &key;
}
//Convert to postfix notation.
char ** stack(char ** list){
  return list;
}
//Read postfix expression.
int doMath(char ** stack){
  int i=0;
  return i;
}
