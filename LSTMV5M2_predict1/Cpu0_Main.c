/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#include <omp.h>
#include <stdio.h>

#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
/////////////////////////////
#include "main.h"
#include "my_predict_mode1.h"
#include "my_predict_mode1_terminate.h"
#include "Cpu0_Main.h"
#include "SysSe/Bsp/Bsp.h"
#include "AsclinAscDemo.h"
#include "IfxAsclin.h"
#include "IfxAsclin_Asc.h"
#include "IfxGtm_Tom_Timer.h"
#include "IfxPort.h"
#include "Bsp.h"
#include "UART_VCOM.h"

#define LED_D107_0 &MODULE_P13,0                                           /* LED D107: Port, Pin definition       */
#define LED_D107_1 &MODULE_P13,1                                           /* LED D107: Port, Pin definition       */
#define LED_D107_2 &MODULE_P13,2                                           /* LED D107: Port, Pin definition       */
#define LED_D107_3 &MODULE_P13,3                                           /* LED D107: Port, Pin definition       */
#define WAIT_TIME   100                                                     /* Wait time constant in milliseconds   */

void BlinkLEDs(int l){
    // Toggle the state of the LED
    switch(l){
        case 0:
            IfxPort_togglePin(LED_D107_0);
            break;
        case 1:
            IfxPort_togglePin(LED_D107_1);
            break;
        case 2:
            IfxPort_togglePin(LED_D107_2);
            break;
        case 3:
            IfxPort_togglePin(LED_D107_3);
            break;
    }
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    // Wait 100 milliseconds
}
////////////////////////////

IfxCpu_syncEvent g_cpuSyncEvent = 0;
/////////////////////
App_Cpu0 g_AppCpu0;
uint8 input_counter=0;
extern float SOH;
extern float SOH_ref;
extern double input_manual[150][210];
extern double output_manual[150];
extern uint32 output_counter;
extern Ifx_TickTime timeNow;

///////////////////

/* Function Declarations */
void argInit_3x70_real_T(double result[210]);

double argInit_real_T(void);

void main_my_predict_mode1(void);

/* Function Definitions */
/*
 * Arguments    : double result[210]
 * Return Type  : void
 */
void argInit_3x70_real_T(double result[210])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  input_counter=0;
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < 70; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 3 * idx1] = argInit_real_T();
      input_counter++;
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
double argInit_real_T(void)
{
  return input_manual[output_counter][input_counter];
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_my_predict_mode1(void)
{
  double dv[210];
  float out;
  /* Initialize function 'my_predict_mode1' input arguments. */
  /* Initialize function input argument 'in'. */
  /* Call the entry-point 'my_predict_mode1'. */
  argInit_3x70_real_T(dv);
  out = my_predict_mode1(dv);
  SOH = out;
  SOH_ref = output_manual[output_counter];
}

int core0_main(void)
{
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    /////////////IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    /* Initialise the application state */
    g_AppCpu0.info.pllFreq = IfxScuCcu_getPllFrequency();
    g_AppCpu0.info.cpuFreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreIndex());
    g_AppCpu0.info.sysFreq = IfxScuCcu_getSpbFrequency();
    g_AppCpu0.info.stmFreq = IfxStm_getFrequency(&MODULE_STM0);

    /* Enable the global interrupts of this CPU */
    IfxCpu_enableInterrupts();

    /* Demo init */
    ///////////////AsclinAscDemo_init();

    ///////////////////////////////////////
    IfxPort_setPinModeOutput(LED_D107_0, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Initialization of the LED used in this example
    IfxPort_setPinHigh(LED_D107_0); // Switch OFF the LED (low-level active)
    IfxPort_setPinModeOutput(LED_D107_1, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Initialization of the LED used in this example
    IfxPort_setPinHigh(LED_D107_1); // Switch OFF the LED (low-level active)
    IfxPort_setPinModeOutput(LED_D107_2, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Initialization of the LED used in this example
    IfxPort_setPinHigh(LED_D107_2); // Switch OFF the LED (low-level active)
    IfxPort_setPinModeOutput(LED_D107_3, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Initialization of the LED used in this example
    IfxPort_setPinHigh(LED_D107_3); // Switch OFF the LED (low-level active)
    int l = 0;

    init_UART();            /* Initialize the module            */

    /////////main_my_predict_mode1();
    /* Terminate the application.
    You do not need to do this more than one time. */
    /////////my_predict_mode1_terminate();
    ///////////////////////////////////////

    while(1)
    {
        ////////////////////////////
        timeNow = now();    //saving initial time before computing the machine learning part
        BlinkLEDs(l);     //This blinking led just to test if the loop works, and estimate/verify the computation time
        if (l==3) l=0;
        else l++;

        if (output_counter==150){
            my_predict_mode1_terminate();
            printRMSE();   // Print RMSE value
            output_counter=0;
            waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, 10000));    // Wait 10 seconds
        }
        else{
            main_my_predict_mode1();
            output_counter++;
        }
        send_UART_message();    /* Send the message "Hello World!"  */


        //AsclinAscDemo_run();
        //REGRESSION_RUN_STOP_PASS;
        ////////////////////////////
    }
    return (1);
}
