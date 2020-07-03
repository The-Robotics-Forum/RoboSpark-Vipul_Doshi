
#include <stdio.h>
#include<string.h>
struct s
{
  int top;
  char stk[30];
} c;
void
push (char item)
{
  if (c.top < 29)
    {
      c.top = c.top + 1;
      c.stk[c.top] = item;
    }
}

void
pop ()
{
  if (c.top >= 0)
    {
      c.top = c.top - 1;
    }
}

int
main ()
{

  c.top = -1;
  char a[30];
  scanf ("%s", a);
  for (int i = 0; i < 30; i++)
    {
      if (a[i] == "(")
	push (a[i]);
      else
	pop ();
    }
  if (c.top == 0)
    printf ("balanced");
  else
    printf ("not balanced");
  return 0;
}
