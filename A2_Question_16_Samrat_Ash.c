#include <stdio.h>
#include <math.h>

double exact_solution(double t) {
    return pow(t + 1, 2) - 0.5 * exp(t);
}

double euler_method(double t, double y, double h) {
    return y + h * (y - pow(t, 2) + 1);
}

int main() {
    double t = 0.0; // Initial time
    double y = 0.5; // Initial value of y
    double h = 0.2; // Step size
    double exact, error, error_bound;

    printf("t\tExact\t\tEuler\t\tError\t\tError Bound\n");
    printf("-------------------------------------------------------------------\n");

    while (t <= 2.0) {
        exact = exact_solution(t);
        error = exact - y;
        error_bound=0.2*(exp(t)-1); // Error bound derived in class

        printf("%.1f\t%.6f\t%.6f\t%.6f\t%.6f\n", t, exact, y, error, error_bound);

        y = euler_method(t, y, h);
        t += h;
    }

    return 0;
}
