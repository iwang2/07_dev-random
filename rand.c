#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int random_int(){
  int fd = open("/dev/random", O_RDONLY);
  int i;
  read(fd, &i, sizeof(int));
  return i;
}

int main(){
  int ia[10];
  for(a = 0; a < 10; a++){
    printf("%d\n", random_int());
  }
}
