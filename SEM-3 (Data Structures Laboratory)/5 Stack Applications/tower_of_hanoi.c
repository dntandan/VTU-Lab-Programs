#include<stdio.h>
#include<math.h>

void tower(int n, int source, int temp, int destination);

void tower(int n, int source, int temp, int destination) {
  if (n == 0)
    return;
  tower(n - 1, source, destination, temp);
  printf("\nMove disc %d from %c to %c", n, source, destination);
  tower(n - 1, temp, source, destination);
}

int main() {
  while(1){
  int n;
  printf("\nEnter the number of discs ==> \t");
  scanf("%d", & n);
  printf("The sequence of moves involved in the Tower of Hanoi are\n");
  tower(n, 'A', 'B', 'C');
  printf("\n\nTotal Number of moves are: %d\n", (int) pow(2, n) - 1);
  }
}
