
#include <stdio.h>
#include <conio.h>
void main()
{
  int boxX = 40, boxY = 24, candyX = 40, candyY = 2, score = 0, life = 4, d;
  char ch;
  int i = 100;
begin:
  textbackground(WHITE);
  clrscr();
  textcolor(BLACK);
  gotoxy(candyX, candyY);
  cprintf("#");
  gotoxy(60, 7);
  textcolor(BLUE);
  cprintf("Score=%d", score);
  gotoxy(60, 8);
  textcolor(BLUE);
  cprintf("Life=%d", life);
  gotoxy(boxX, boxY); //(40,24)
  textcolor(BLACK);
  cprintf("*");
  gotoxy(boxX + 7, boxY);
  cprintf("*");
  gotoxy(boxX, boxY + 1);
  cprintf("********");
  delay(10);
  if (kbhit())
  {
    ch = getch();
    switch (ch)
    {
    case 'a':
      if (boxX >= 3)
      {
        boxX--;
      }
      else
      {
        boxX = 2;
      }
      break;
    case 'd':
      if (boxX <= 70)
      {
        boxX++;
      }
      else
      {
        boxX = 71;
      }
      break;
    case 'e':
      exit(0);
    } //switch

  } //kb
  candyY++;
  if (candyY == 26)
  {
    sound(2000);
    delay(500);
    nosound();
    candyY = 2;
    candyX = rand() % 80 + 1;
    d = candyX - boxX;
    if (d == 0 || d == 1 || d == -1)
    {
      score++;
    }
    else
    {
      life--;
      if (life == 0)
      {
        textcolor(RED);
        gotoxy(35, 12);
        sound(2000);
        delay(20);
        nosound();
        cprintf("Game Over");
        getch();
        clrscr();
        exit(0);

      } //else

    } //if life

  } //if
  delay(60);
  sound(i);
  i++;
  goto begin;
  getch();

} //main