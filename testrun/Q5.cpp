#include<iostream>
#include<fstream>
#include<math.h>
#include<ios>

void input(float *a, float *b)
{ std::cout<<" Value of x at which error is to be found : ";
  std::cin>>*a;
  std::cout<<" dx = ";
  std::cin>>*b;
}

void output(float x, float dx, float dy_1, float y_1, float relerr, float pererr)
{ std::ofstream mdfile;
  mdfile.open("Q5.md",std::ios::app);
  mdfile<<"# Q5. If y=4Cosx-6x, find the relative error and percentage error in y at x=1 given   delta(x)=0.005. \n\n## Answer : \n\n";
  mdfile<<" Given equation : y = 4cosx - 6x ." ;
  mdfile<<"\n\n y(1) = "<<y_1 ;
  mdfile<<"\n\n Derivative : $\\frac{dy}{dx}$ = -4sinx - 6." ;
  mdfile<<"\n\n dy(1) = "<<dy_1 ;
  mdfile<<"\n\n Relative error = $\\frac{dy(1)}{y(1)}$" ;
  mdfile<<"\n\n Relative error = "<<relerr ;
  mdfile<<"\n\n Percentage error = Relative*100" ;
  mdfile<<"\n\n Percentage error = "<<pererr<<" %" ;
  mdfile.close();
}

void process(float x, float dx, float *dy_1, float *y_1, float *relerr, float *pererr)
{ *y_1 = 4*cos(x) - 6*x ;
  *dy_1 = ((-4)*sin(x) - 6 )*dx;
  *relerr = *dy_1 / *y_1 ;
  *pererr = *relerr*100 ;
}

int main()
{
  float dy_1=0.0, y_1=0.0, relerr=0.0, pererr=0.0, dx=0.0 , x=0.0;
  
  input(&x,&dx);
  process(x,dx,&dy_1,&y_1,&relerr,&pererr);
  output(x,dx,dy_1,y_1,relerr,pererr);
  return 0;
}
