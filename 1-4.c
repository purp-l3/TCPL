#include <stdio.h>
/* print celsius-fahrenheit table for f = 0, 20, ..., 300 */
main(){
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 150;
    step = 10;

    celsius = lower;

    printf("Celsius\t|\tFahrenheit\n");
    while (celsius <= upper) {
        
        fahr =  (celsius * (9/5)) + 32;
        printf("%6.1f\t|\t%4.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

}
