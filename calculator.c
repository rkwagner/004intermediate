//Calculator program for dailyprogrammer challenge #4 (Intermediate).
//Author: Ryan Wagner


//Idea: use recursion to create a stack every time a paren is used.
//Valid symbols:  /-+*%^()
//Priorities:     1.()    2.^   3.*/%   4.+-
//Use a stack and a postfix string, popping the stack until the item of
//lower priority is the next on the stack, at which point a push occurs.
//numbers are always parsed in order and put directly into the string.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CMP 4

void input(char *a){
  printf("> ");
  fgets(a, 256, stdin);
}

int priorityCh(char a, char b){
  int priorityA,priorityB;
  switch(a){
    case '+':case '-':priorityA=0;break;
    case '*':case '/':case '%':priorityA=1;break;
    case '^':case ')':priorityA=2;break;
    case '(':priorityA=3;break;
    default:priorityA=-100;break;
  }
  switch(b){
    case '+':case '-':priorityB=0;break;
    case '*':case '/':case '%':priorityB=1;break;
    case '^':case ')':priorityB=2;break;
    case '(':priorityB=3;break;
    default:priorityB=-1;break;
  }
  return priorityA-priorityB;
}//Check which symbol is of higher priority.  If b, pop the stack until
 //a is highest priority left.

void push(char *a, char b){
  a[strlen(a)]=b;
  a[strlen(a)+1]='\0';
}

char pop(char *a){
  char newA = a[strlen(a)-1];
  a[strlen(a)-1]='\0';
  return newA;
}

void calculate(char *infix, char *postfix, char *bucket){
  if(!(*infix) || *infix=='\n'){
    if(strlen(bucket)){
      push(postfix,pop(bucket));
    }
    else{/*EMPTY*/}
    (void)printf("%s\n", postfix);
  }
  else{
    if(*infix<='9'&&*infix>='0'){
      push(postfix,*infix);
      calculate(infix+1,postfix, bucket);
    }
    else{
      int checker=priorityCh(*infix,bucket[strlen(bucket)-1]);
      if(checker>0){
        push(bucket,*infix);
      }
      else if(checker<-50){
        *infix=infix[strlen(infix)-1];
        (void)printf("Invalid input detected, terminating...\n");
      }
      else{
        while(checker<=0&&checker>=-50 && strlen(bucket)>0){
          push(postfix,pop(bucket));
          checker=priorityCh(*infix,bucket[strlen(bucket)-1]);
        }
        push(bucket,*infix);
      }
      calculate(infix+1,postfix, bucket);
    }
  }
}//Create a postfix expression to evaluate and calculate.

int main(void){
  char in[256],post[256]="",bucket[256]="";
  while(strncmp(in,"quit",MAX_CMP)){
    input(in);
    strncmp(in,"quit",MAX_CMP)?(calculate(in,post,bucket)):
      (void)printf("Sequence terminated.\n");
  }
  return 0;
}
