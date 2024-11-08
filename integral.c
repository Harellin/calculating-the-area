#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double f1 (double x);
double f2 (double x);
double f3 (double x);
double test1 (double x);
double test2 (double x);
double test3 (double x);

static long long unsigned iterations = 0;

static double h_function(double x, double (*f)(double), double (*g)(double)) {
    return f(x) - g(x);
}

static double root_function(double (*f)(double), double (*g)(double), double a, double b, double e1){
    double a1, b1, c1;
    a1 = h_function(a, f, g);
    b1 = h_function(b, f, g);
    if (a1*b1 > 0){
        return -1;
    }
    while (a - b >= e1){
        a1 = h_function(a, f, g);
        b1 = h_function(b, f, g);
        c1 = h_function((a+b) / 2, f, g);
        if (b1 * c1 < 0){
            a = (a + b) / 2;
        }
        else {
            b = (a + b) / 2;
        }
    }
    return a;
}

double integral(double (*f)(double), double a, double b, double e2);

double integral(double (*f)(double), double a, double b, double e2) {
    int n = (int)((b - a) / e2);
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 4 * f(a + i * h);
        }
    }
    return sum * h / 3;
}

int main(int argc, char* argv[]) {
   double (*f[6]) (double) = {f1, f2, f3, test1, test2, test3};
   if(argc > 3){
      printf("This program doesn't support more than one argument at once\n");
   }
   else if(argc > 1){
      if((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
         if(argc == 3){
            printf("Incorrect input");
            return 1;
         }
         printf("--help\n");
         printf("-h\n");
         printf("--root\n");
         printf("-r\n");
         printf("--iterations\n");
         printf("-i\n");
         printf("--test-root\n");
         printf("-R\n");
         printf("--test-integral\n");
         printf("-I\n");
      }
      else if((strcmp(argv[1], "-r") == 0) || (strcmp(argv[1], "--root") == 0)){
         if(argc == 3){
            printf("Incorrect input");
            return 1;
         }
         printf("%lf\n", root_function(f1, f2, 0.0, 2.0, 0.00001));
         printf("%lf\n", root_function(f1, f3, -3.0, 0.0, 0.00001));
         printf("%lf\n", root_function(f2, f3, -2.0, 5.0, 0.00001));
      }
      else if((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--iterations") == 0)){
         if(argc == 3){
            printf("Incorrect input");
            return 1;
         }
         long long unsigned counter = 0;
         root_function(f1, f2, 0.0, 2.0, 0.00001);
         counter += iterations;
         root_function(f1, f3, -3.0, 0.0, 0.00001);
         counter += iterations;
         root_function(f2, f3, -2.0, 5.0, 0.00001);
         counter += iterations;
         printf("%llu\n", counter);
      }
      else if((strcmp(argv[1], "-R") == 0) || (strcmp(argv[1], "--test-root") == 0)){
         if(argc != 3){
            printf("Incorrect input");
            return 1;
         }
         int t1, t2;
         double a, b, e, r;
         int testarg = sscanf(argv[2], "%d:%d:%lf:%lf:%lf:%lf", &t1, &t2, &a, &b, &e, &r);
         if((testarg != 6) || (t1 < 4) || (t2 < 4) || (t1 > 6) || (t2 > 6)){
            printf("Incorrect input");
            return 1;
         }
         t1--;
         t2--;
         double testroot = root_function(f[t1], f[t2], a, b, e);
         printf("%lf %lf %lf\n", testroot, fabs(fabs(testroot) - fabs(r)), fabs(fabs(testroot) - fabs(r)) / fabs(r));
      }
      else if((strcmp(argv[1], "-I") == 0) || (strcmp(argv[1], "--test-integral") == 0)){
         if(argc != 3){
            printf("Incorrect input");
            return 1;
         }
         int t1;
         double a, b, e, r;
         int testarg = sscanf(argv[2], "%d:%lf:%lf:%lf:%lf", &t1, &a, &b, &e, &r);
         if((testarg != 5) || (t1 < 4) || (t1 > 6)){
            printf("Incorrect input");
            return 1;
         }
         t1--;
         double testint = integral(f[t1], a, b, e);
         printf("%lf %lf %lf\n", testint, fabs(fabs(testint) - fabs(r)), fabs(fabs(testint) - fabs(r)) / fabs(r));
      }
      else{
         printf("Incorrect input");
         return 1;
      }
   }
   else{
      double r1 = root_function(f1, f2, 0.0, 2.0, 0.00001);
      double r2 = root_function(f1, f3, -3.0, 0.0, 0.00001);
      double r3 = root_function(f2, f3, -2.0, 0.0, 0.00001);
      printf("%lf %lf %lf\n", r1, r2, r3);
      double i1 = integral(f1, r2, r1, 0.00001);
      double i2 = integral(f2, r3, r1, 0.00001);
      double i3 = integral(f3, r2, r3, 0.00001);
      printf("%lf\n", i1 - i2 - i3);
   }
   return 0;
}
