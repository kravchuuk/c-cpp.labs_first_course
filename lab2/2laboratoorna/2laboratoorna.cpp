#include<stdio.h>
#include<math.h>
int main() {
    double  x, k = 1, res = 0, preres = 0, d = 0.001;

    for (x = 1; x < 2; x += 0.1) {
        do {
            double a, b;
            a = pow(-1, k) * pow(cos((pow(2, k) * x)), 4);
            b = pow(2, 2 * k);
            preres = a / b;
            res += preres;
            k++;
        } while (preres >= d);

        printf("%f\n\t", res);
        res = 0;
    }
    return 0;
}