#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float suma = 1.e-6, potencia = 0;
    int i = 0;

    for(i = 0; i < N; i++){
        suma += x[i]*x[i];
    }
    potencia = 10*log10(suma/N);

    return potencia;
}

float compute_am(const float *x, unsigned int N) {
    float suma = 0, amplitud = 0;
    int i = 0;

    for(i = 0; i < N; i++){
        suma += fabs(x[i]);
    }
    amplitud = suma/N;

    return amplitud;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float suma = 0, ZCR = 0;
    int i = 0;

    for(i = 1; i < N; i++){
        if(x[i] > 0 && x[i-1] <= 0){
            suma++;
        }else if(x[i] < 0 && x[i-1] >= 0){
            suma++;
        }else if(x[i] == 0 && ((x[i-1] < 0) || (x[i-1] > 0))){
            suma++;
        }
    }
    ZCR = (fm/2)*(suma/(N-1));

    return ZCR;
}
