/*
**
**
**
**
**
**
*/

#include <unistd.h>

int	ft_putchar(char c)
{
  return (write(1, &c, 1));
}

int	is_safe(int rows[8], int x, int y)
{
  int i;
  
  i = 0;
  if (y == 0)
    return 1;
  while (i < y) {
    if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y +i)
      return (0);
    ++i;
  }

  return (1);
}

void	printsolution(int rows[8])
{
  int	x;
  int	y;

  x = 0;
  while (x < 8)
    {
      y = 0;
      while (y < 8)
	{
	  if (x == rows[y])
	    ft_putchar(y + 1 + '0');
	  ++y;
	}
      ++x;
    }
  ft_putchar('\n');
}

void	eight_queens_solver(int rows[8], int y)
{
  int x;
  
  x = 0;
  while (x < 8) {
if (is_safe(rows, x, y)) {
      rows[y] = x;
      if (y == 7)
	printsolution(rows);
      else
	eight_queens_solver(rows, y+1);
    }
    ++x;
  }
}

void ft_eight_queens_puzzle_2(void)
{
  int rows[8];

  eight_queens_solver(rows, 0);
}

int main()
{
  ft_eight_queens_puzzle_2();
}
