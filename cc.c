#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int main(int argc,char *argv[])
{
 printf(1,"hallo %s\n",argv[1]);
 if(argc==1){chdir("/");exit();}
 if(argc>2)
 {
  printf(1,"Terlalu banyak operand\n");
  exit();
 }
 if(chdir(argv[1])<0)
 {
  printf(1,"gagal untuk menuju direktori\n");
  exit();
 }
 exit();
}
