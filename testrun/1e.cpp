#include<iostream>
#include<fstream>
#include<iomanip>

float xd=0.1429, yd=0.0667, xf=1.0/7, yf=1.0/15, relerr=0.0, pererr=0.0;

void process()
{ relerr = ((xd+yd)-(xf+yf))/(xf+yf);
  pererr = relerr*100;
}

void output()
{ std::ofstream mdfile;
  mdfile.open("1e.md",std::ios::app);
  mdfile<<"# Question 1(e) : Find the relative error for the sum of $\\frac{1}{7}$ and $\\frac{1}{15}$ correct to four decimal.\n\n";
  mdfile<<"## Answer : \n\n";
  mdfile<<" Realtive error = $\\frac{(0.1429 + 0.0667) - (\\frac{1}{7} + \\frac{1}{15})}{(\\frac{1}{7} + \\frac{1}{15})}$ \n\n Relative error =";
  mdfile<< std::fixed;
  mdfile<<std::setprecision(4);
  mdfile<<relerr;
  mdfile<<"\n\n Percentage error = Relative error*100 \n\n Precentage error = ";
  mdfile<<std::setprecision(4);
  mdfile<<pererr<<"%\n\n";
}

int main()
{ 
  process();
  output();
  return 0;
}

