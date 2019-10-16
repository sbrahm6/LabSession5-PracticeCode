#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define SIGINT 1   // Interrupt the process
#define SIGTSTP 2  // Stop the process

void sigint_handler(int sig) {
  int n = sig;
  char *msg;
  switch (n) {
    case 1:  // code to be executed if n = 1;
      msg = "SIGINT Handled\n";
      write(1, msg, sizeof(msg));
      exit(0);
      break;
    case 2:  // code to be executed if n = 2;
      msg = "SIGTSTP Handled\n";
      write(1, msg, sizeof(msg));
      exit(0);
      break;
      //  default:  // code to be executed if n doesn't match any cases
  }
}

int main() {
  signal(SIGINT, sigint_handler);

  int i = 99;
  while (1) {
    printf("%d bottles of beer on the wall\n", i);
    printf("%d bottles of beer\n", i);
    printf("Take one down, pass it around\n");
    i = i - 1;
    printf("%d bottles of beer on the wall\n", i);
  }
}
