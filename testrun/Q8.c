#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float x_0,y_0,k,y,x,h,xn;
int n=0;

float f(float x,float y);

void input()
{ printf("Enter x_0,y_0,xn,h:");
  scanf("%f %f %f %f",&x_0,&y_0,&xn,&h);
}

void process()
{ FILE *mdfile;
  mdfile = fopen("Q8.md","a+");
  x=x_0;
  y=y_0;
  while(x<xn)
    {
        k = f(x_0,y_0);
        y=y+k*h;
        x=x+h;
        n++;
        fprintf(mdfile,"%d | %f | %f\n",n,x,y);
     }
  fprintf(mdfile,"\n\n Hence at x= %f , **y= %f**.\n\n",xn,y);
  fclose(mdfile);
}

void output()
{ FILE *mdfile;
  mdfile = fopen("Q8.md","a+");
  fprintf(mdfile,"\n\n# Q8 Use Runge-Kutta Method to find "); 
  fprintf(mdfile,"the value of y when x=0.5, given that y=1, when x=0 ");
  fprintf(mdfile,"and that y'=(y-x)/(y+x).\n\n");
  fprintf(mdfile,"## Answer : \n\n");
  fprintf(mdfile," Using 1st order R-K method : k = h*y'(x~n~,y~n~) ");
  fprintf(mdfile,"& y~n+1~ = y~n~ + k\n\n We get : \n\n");
  fprintf(mdfile," n | X | Y\n---|---|---\n");
  fclose(mdfile);
}

int main()
{
  input();
  output();
  process();
}

float f(float x,float y)
{
    float m;
    m=(y-x)/(y+x);
    return m;
}
