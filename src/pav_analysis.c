#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float sumatorio =1e-6;
    for(int i=0; i<N; i++){
        sumatorio = sumatorio + (x[i] * x[i]);
    }
    return 10*log10(sumatorio/N);
}

float compute_am(const float *x, unsigned int N) {
    float sumatorio=0;
    for(int i=0; i<N; i++){
        sumatorio = sumatorio + fabs(x[i]);
    }
    return sumatorio/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int sumatorio =0;
    for(int i=1; i<N;i++){
        if(copysign(1.0, x[i]) != copysign(1.0, x[i-1])){
            sumatorio =  sumatorio +1;
        }
    }
    return fm*sumatorio/(2*(N-1));
}
