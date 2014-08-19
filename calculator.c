//Calculator program for dailyprogrammer challenge #4 (Intermediate).
//Author: Ryan Wagner

#include<stdio.h>

int main(void){
  printf("Enter an equation: ");
  char in[100];
  fgets(in,sizeof in,stdin);
  printf("Equation results: %s\n",in);
  return 0;
}
