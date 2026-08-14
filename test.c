#include <stdio.h>   // для sprintf и puts
#include <stdint.h>
#include <math.h>
//#include "complex.h"
#define ADC_BUF_SIZE 4095
#define Pi  3.1415926535
int main() {  

    float adc_buf[ADC_BUF_SIZE];                                  // буфер входный значений
    float Sum_Re, Sum_Im;                                           // действительная и мнимая часть суммы произведений гарм. функции на буфер АЦП
    float Xk_Re[ADC_BUF_SIZE], Xk_Im[ADC_BUF_SIZE];                 // действительная и мнимая части спектра
    float Abs[ADC_BUF_SIZE];                                        // буфер для хранения результата модуля спектра
    
    
    for(int i = 0; i < ADC_BUF_SIZE; i++)   {
        adc_buf[i] = sin(2*Pi*i*2/ADC_BUF_SIZE)+sin(2*Pi*i*10/ADC_BUF_SIZE)+sin(2*Pi*i*20/ADC_BUF_SIZE);     // запись тестовой функции для построения спектра
    }

    for (int k = 0; k < ADC_BUF_SIZE; k++)  {                       // расчет спектра ДПФ двойным циклом
        for (int n = 0; n < ADC_BUF_SIZE; n++)  {
            Sum_Re += adc_buf[n]*cos(2*Pi*k*n/ADC_BUF_SIZE);        // рассчет суммы действительной части всех отсчетов для данного k
            Sum_Im += adc_buf[n]*sin(2*Pi*k*n/ADC_BUF_SIZE);        // рассчет суммы мнимой части всех отсчетов для данного k
        }
        Xk_Re[k] = Sum_Re;                                          // запись действительной части спектра в буфер
        Xk_Im[k] = Sum_Im;                                          // запись мнимой части спектра в буфер
        Abs[k] = sqrtf(Xk_Re[k] * Xk_Re[k] + Xk_Im[k] * Xk_Im[k]);  // расчет модуля спектра
        Sum_Re = 0;
        Sum_Im = 0;
    }

    for (int k = 0; k < ADC_BUF_SIZE; k++)  {                       // вывод результатов
        printf("k\t%i\tCOMPLEX_SPECTRE[k]\t%.5f+%.5fi\tABS_SPECTRE[k]\t%.5f\n", k, Xk_Re[k], Xk_Im[k], Abs[k]);
    }

    return 0;
}