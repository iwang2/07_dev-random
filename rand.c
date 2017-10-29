#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int random_int() {
  int fd = open("/dev/random", O_RDONLY);
  int i;
  if (read(fd, &i, sizeof(int)) == -1) {
    printf("Error detected!\n%s\n", strerror(errno));
  }
  if (close(fd)  == -1) {
    printf("Error detected!\n%s\n", strerror(errno));
  }
  return i;
}

int main() {
  umask(0);
  int old_array[10], new_array[10];
  int a;
  for(a = 0; a < 10; a++) {
    int r = random_int();
    old_array[a] = r;
    printf("random %d: %d\n", a, r);
  }
  printf("\n");
  
  int write_to = open("array.txt", O_CREAT | O_WRONLY, 0644);
  printf("Writing numbers to file...\n\n");
  if ((int)write(write_to, &old_array[0], sizeof(int) * 10) == -1) {
    printf("Error detected!\n%s\n\n", strerror(errno));
  }
  close(write_to);

  // reading file into different array
  int read_me = open("array.txt", O_RDONLY);
  printf("Reading numbers from file...\n\n");
  if(read(read_me, &new_array[0], sizeof(int) * 10) == -1){
    printf("error reading file!\n%s\n\n", strerror(errno));
  }
  close(read_me);

  // printing new array
  int b;
  for(b = 0; b < 10; b++){
    printf("random %d: %d\n", b, new_array[b]);
  }
  return 0;
}
