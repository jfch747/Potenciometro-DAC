/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ64GB002
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/adc1.h"

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    int vin = 0;
    int aux = 62;
    int b1 = 0;
    int b2 = 0;
    int b3 = 0;
    int b4 = 0;
    int b5 = 0;
   
    while (1)
    {
       vin = ADC1_ConversionResultGet();
       if ((vin > 0) && (vin<aux) && (b1==0)){
           LATBbits.LATB15 = 1;
           b1 = 1;
       }
       else if ((vin >= aux ) && (vin<(aux+aux) && (b2==0) )){
           LATBbits.LATB14 = 1 ;
           b2 = 1;
       }
       else if ((vin >= (aux+aux) && (vin<(aux*3) && (b3==0)))){
           LATBbits.LATB13 = 1 ;
           b3 = 1;
       }
       else if ((vin >= (aux*3) && (vin<(aux*4) && (b4==0)))){
           LATBbits.LATB11 = 1 ;
           b4 = 1;
       }
       else if ((vin >= (aux*4) && (vin<(aux*5)&& (b5==0)))){
           LATBbits.LATB10 = 1 ;
           b5 = 1;
       }
       else if ((b5 == 1) && (vin >= (aux*3)) && (vin <= aux*4)){
           LATBbits.LATB10 = 0;
           b5 = 0;
       }
       else if ((b4 == 1) && (vin >= (aux*2)) && (vin <= aux*3)){
           LATBbits.LATB11 = 0;
           b4 = 0;
       }
       else if ((b3 == 1) && (vin >= (aux)) && (vin <= aux*2)){
           LATBbits.LATB13 = 0;
           b3 = 0;
       }
       else if ((b2 == 1) && (vin > 0 ) && (vin <= (aux))){
           LATBbits.LATB14 = 0 ;
           b2 = 0;
       }
       else if ((b1 == 1) && (vin == 0) && (vin < aux)){
           LATBbits.LATB15 = 0;
           b1 = 0;    
    }
    }

    return 1;
}
/**
 End of File
*/

