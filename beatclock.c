#include <error.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

const char numbers[][2] = {
    {0x3f, 0x00}, // 0
    {0x06, 0x00}, // 1
    {0xdb, 0x00}, // 2
    {0xcf, 0x00}, // 3
    {0xe6, 0x00}, // 4
    {0xed, 0x00}, // 5
    {0xfd, 0x00}, // 6
    {0x07, 0x00}, // 7
    {0xff, 0x00}, // 8
    {0xef, 0x00}, // 9
};

char buf[17] = {0};

int configure_display(char *device) {
  int file;

  if ((file = open("/dev/i2c-1", O_RDWR)) < 0) {
    perror("open");
    exit(1);
  }

  int addr = 0x70;
  if (ioctl(file, I2C_SLAVE, addr) < 0) {
    perror("ioctl");
    exit(1);
  }

  /* Get oscillated. */
  buf[0] = 0x21;
  if (write(file, buf, 1) != 1) {
    perror("write");
    exit(1);
  }

  /* Let there be light. */
  buf[0] = 0x81;
  if (write(file, buf, 1) != 1) {
    perror("write");
    exit(1);
  }

  return file;
}

void display(int file, int val, char dot) {
  char strbuf[5];

  sprintf(strbuf, "%04d", val);
  for (unsigned char i = 0; i < 4; i++) {
    int num = strbuf[i] - '0';
    memcpy(buf + 1 + (i * 2), numbers[num], 2);
  }

  if (dot) {
    buf[8] |= 0x40;
  }
  buf[6] |= 0x40; // Decimal pt.

  /* Load the data. */
  buf[0] = 0x0;
  if (write(file, buf, 17) != 17) {
    perror("write");
    exit(1);
  }
}

int main(void) {
  int file = configure_display("/dev/i2c-1");
  char dot = 0;

  for (;; dot = !dot) {
    double t = (double)time(NULL);
    t = t + 3600; // BMT, not GMT, for Internet time
    int beats = (int)((t / 8.64)) % 10000;
    display(file, beats, dot);
    sleep(1);
  }
}
