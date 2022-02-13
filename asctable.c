#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asctable.h"

/*
TODO: make it make the table 
*/

char scrap[MAX_STR_LEN];

int print_col_segment(int width, char* str)
{
  char s[MAX_STR_LEN];
  int len = strlen(str);
  int offs = ((width - len) / 2);
  
  for (int x = 0; x < width; x++)
  {
    if (x >= offs && x < (offs+len))
    {
      s[x] = str[x-offs];
    }
    else s[x] = ' '; 
  }
  s[width] = '|';
  s[width+1] = '\0';
  printf("%s",s);
}

int print_hrule(int width)
{ 
  char c[MAX_STR_LEN] = "\0";
  for (int x = 0; x < width+1; x++)
  {
    if (x == width) c[x] = '+';
    else if (x == (width+1)) c[x] = '\0';
    else c[x] = '-';
  }
  printf("%s", c);
}

int print_top_row(int col_w)
{
  
  print_col_segment(col_w+1, "1977");
  for (int x = 0; x < 16; x++)
  {
    char label[MAX_STR_LEN];
    snprintf(label, col_w, "0x%01X", x);
    print_col_segment(col_w, label);
  }
}

int main(void)
{
  int width = 5;
  //int l_width = 7;
  printf("+");
  for (int x = 0; x < 17; x++)
  {
    if (x==0) print_hrule(width+1);
    else print_hrule(width);
  }
  printf("\n");
  printf("|");
  print_top_row(width);
  printf("\n");
  printf("+");
  for (int x = 0; x < 17; x++)
  {
    if (x==0) print_hrule(width+1);
    else print_hrule(width);
  }
  printf("\n");
  
  int index = 0;
  for (int y = 0; y < 8; y++)
  {
    printf("|");
    for (int x = 0; x < 17; x++)
    {
      char s[MAX_STR_LEN];
      if (x == 0)
      {
        snprintf(s, width+1, "0x%02X", (y*16));
        print_col_segment(width+1, s);
      }
      else
      {
        snprintf(s, width+1, "%s", ascii[index]);
        index++;
        print_col_segment(width, s);
      }
    }
    printf("\n");
    printf("+");
    for (int x = 0; x < 17; x++)
    {
      if (x == 0) print_hrule(width+1);
      else print_hrule(width);
    }
    printf("\n");
  }
}
