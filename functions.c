#include "headers.h"
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int getRandom(){
  int f = open("/dev/random", O_RDONLY);
  if (f < 0) {
		printf("%s: %s\n", "Error on open", strerror(errno));
	}
  int ans = 0;
  int toComp = read(f, &ans, sizeof(ans));
  if (toComp < 0) {
		printf("%s: %s\n", "Error when reading", strerror(errno));
	}
  close(f);
  return ans;
}
