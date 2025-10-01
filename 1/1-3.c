#include <stdio.h>
/* print fahrenheit-celsius table for f = 0, 20, ..., 300 */
main(){
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;

    printf("Fahrenheit\tCelsius\n");
    //printf("lower:%\t|\tupper:%\n",lower,upper);
        while (fahr > lower) {
        celsius = (5.0/9.0) * (fahr-32.0); 
        printf("%4.0f\t|\t%6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }

}
