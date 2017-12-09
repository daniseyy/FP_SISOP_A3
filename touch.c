#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int mkfile(char *path)
{
return open(path,FCREAT);
}


int main(int argc,char *argv[])
{
 int i;
 if(argc==1)
    {
	printf(2,"touch: missing file operand\n");
	exit();
     }

   for(i=1;i<argc;i++)
	{if(mkfile(argv[i])<0)
    {printf(2,"touch: %s failed to create\n",argv[i]);
         break;}
	}
     exit();

}
