//Calculator program for dailyprogrammer challenge #4 (Intermediate).
//Author: Ryan Wagner


//Idea: use recursion to create a stack every time a paren is used.
//Valid symbols:  /-+*%^()
//Priorities:     1.()    2.^   3.*/%   4.+-
//
#include<stdio.h>
#include<string>

int add(char *a);
int sub(char *a);
int mult(char *a);
int div(char *a);
int mod(char *a);
int exp(char *a);
int paren(char *a);

int main(void){
  printf("Enter an equation: ");
  char in[100];
  fgets(in,sizeof in,stdin);
  printf("Equation results: %s\n",in);
  return 0;
}

int paren(char *a){
  char *closeParen=strchr(a,')');
}//Operate on everything until a close paren is found.

int exp(char *a){
  
}//Recurse until parsed int is achieved.

int mod(char *a){

}//Find the remainder of division by the second int.
