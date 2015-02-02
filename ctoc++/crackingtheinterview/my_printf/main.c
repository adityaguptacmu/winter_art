#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void myprintf(char * frmt,...);
char * convert(unsigned int, int);

int main(int argc, char const *argv[])
{
  /* code */
  int i=65;
  char str[]="This is my string";
  myprintf("\nMessage = %s%d%x",str,i,i);
  printf("\n\n");
  printf("\nMessage = %s%d%x",str,i,i);
  return 0;
}

void myprintf(char * frmt,...)
{
  char *p;
  int i;
  unsigned u;
  char *s;
  va_list argp;
  va_start(argp, frmt);

  p=frmt;
  for(p=frmt; *p!='\0';p++)
  {
    if(*p!='%')
    {
      putchar(*p);continue;
    }
    p++;

    switch(*p)
    {
      case 'c' : i=va_arg(argp,int);putchar(i);break;
      case 'd' : i=va_arg(argp,int); if(i<0){i=-i;putchar('-');}puts(convert(i,10));break;
      case 'o': i=va_arg(argp,unsigned int); puts(convert(i,8));break;
      case 's': s=va_arg(argp,char *); puts(s); break;
      case 'u': u=va_arg(argp, unsigned int); puts(convert(u,10));break;
      case 'x': u=va_arg(argp, unsigned int); puts(convert(u,16));break;
      case '%': putchar('%');break;
    }
  }
  va_end(argp);
}

char *convert(unsigned int num, int base)
{
  static char buf[33];
  char *ptr;
  ptr=&buf[sizeof(buf)-1];
  *ptr='\0';
  do
  {
    *--ptr="0123456789abcdef"[num%base];
    num/=base;
  }while(num!=0);
  return(ptr);
}