#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>





int main(){
  int ary[10];
  for (int i = 0; i < 10; i++){
    ary[i] = getRandom();
    printf("Random #%d: %d\n", i, ary[i]);
  }

  printf("\n\nWriting to File...\n");
  int f = open("rand.txt", O_CREAT | O_WRONLY, 0644);

  if (f < 0){
    printf("%s: %s\n", "Error Opening", strerror(errno));
  }

  int forComp = write(f, ary, sizeof(ary));
  if (forComp < 0) {
		printf("%s: %s\n", "Error Writing", strerror(errno));
	}
	close(f);

  printf("\nReading from that file\n");

  int new[10];
  f = open("rand.txt", O_RDONLY);

  if (f < 0){
    printf("%s: %s\n", "Error Opening", strerror(errno));
  }

  forComp = read(f, new, sizeof(new));
  if (forComp < 0) {
		printf("%s: %s\n", "Write Error", strerror(errno));
	}
	close(f);

  printf("\nChecking that numbers are the same:\n");
  for (int i = 0; i < 10; i++){
    printf("Random #%d: %d\n", i, new[i]);
  }
}
