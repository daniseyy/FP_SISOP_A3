#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"



void tail (int fd) {
  int n;
  int count=0;
  int linesToPrint;
  int temporary;
  int i = 0;
  char buf [512];
  
  temporary = open ("~implisit", O_CREATE | O_RDWR);
  while ((n = read(fd, buf, sizeof(buf))) > 0) {
    write (temporary, buf, n);
    for (i = 0; i<n; i++) {
      if(buf[i] == '\n')
        count++;
    }
  }
  if (n < 0) {
    printf (1, "tail: read error \n");
    exit ();
  }
  if (count < 10)
    linesToPrint = 0;
  linesToPrint = count - 10;

  close (temporary);
  temporary = open ("~implisit", 0);

  int counter = 0;
  while ((n = read(temporary, buf, sizeof(buf))) > 0) {
    for (i = 0; i<n; i++) {
      if (counter >= linesToPrint)
        printf(1,"%c",buf[i]);
      if (buf[i] == '\n')
        counter++;
      }
    }
    close (temporary);
    unlink("~implisit");
}

int main (int argc, char *argv[]) {
  
  int fd ;

  if (argc <= 1) {
    printf(1,"tail: no file operand\n");
    exit();
  }
 
  else {
    
      for (int i=2; i<=argc; i++) {
      if((fd = open (argv[i],O_RDONLY)) < 0) {
        printf (1, "tail: cannot open %s\n", argv[i]);
        exit ();
      }
  		else tail (fd);
 		close (fd);
    }
  }
  exit();
}
