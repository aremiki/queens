/*
**
**
**
**
**
**
*/

#include <stdio.h>

int	g_count = 0;

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

void	eight_queens_solver(int rows[8], int y)
{
  int x;
  
  x = 0;
  while (x < 8) {
    if (is_safe(rows, x, y)) {
      rows[y] = x;
      if (y == 7)
	g_count++;
      else
	eight_queens_solver(rows, y+1);
    }
    ++x;
  }
}

int ft_eight_queens_puzzle(void)
{
  int rows[8];
  
  eight_queens_solver(rows, 0);
  return (g_count);
}

int main()
{
  printf("%d\n", ft_eight_queens_puzzle());
}
