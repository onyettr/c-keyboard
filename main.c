#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#define STDIN_FILENO 0

int main ( void )
{
  int ch, i;
  struct termios term, restore;

  tcgetattr( STDIN_FILENO, &term);
  restore = term;
  term.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &term );

  for (i = 0; i < 4; i++) {
      puts("enter arrow");
      ch = getchar() & 0xFF;
      ch += getchar() & 0xFF;
      ch += getchar() & 0xFF;
      printf("%c | %d\n", ch, ch);
  }

  tcsetattr(STDIN_FILENO, TCSANOW, &restore);
}
