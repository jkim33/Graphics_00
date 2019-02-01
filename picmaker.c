#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
  int fd;
  char line[20];
  int rgb[3];

  fd = open("pic.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  snprintf(line, sizeof(line), "P3 560 560 255\n");
  write(fd, line, strlen(line));

  int x, y;
  for (x = 0; x < 560; x++) {
    for (y = 0; y < 560; y++) {
      if ((x%140)%2 == 0 && (y%140)%2 == 0) {
	rgb[0] = (x*2)%140;
	rgb[1] = (x*y)%140;
	rgb[1] = (y*2)%140;
      }
      else {
	rgb[0] = (x/2)%140;
	rgb[1] = (x*y)%140;
	rgb[2] = (y/2)%140;
      }
      snprintf(line, sizeof(line), "%d %d %d ", rgb[0], rgb[1], rgb[2]);
      write(fd, line, strlen(line));
    }
  }
  close(fd);
  return 0;
}

