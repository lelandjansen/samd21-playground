/**
 * \file
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include "samc20.h"

typedef void (*intfunc) (void);
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

void __iar_program_start(void);
int __low_level_init(void);

/* Default empty handler */
void Dummy_Handler(void);

/* Cortex-M0+ core handlers */
#pragma weak NMI_Handler              = Dummy_Handler
#pragma weak HardFault_Handler        = Dummy_Handler
#pragma weak SVC_Handler              = Dummy_Handler
#pragma weak PendSV_Handler           = Dummy_Handler
#pragma weak SysTick_Handler          = Dummy_Handler

/* Peripherals handlers */
#pragma weak SYSTEM_Handler           = Dummy_Handler /* MCLK, OSC32KCTRL, OSCCTRL, PAC, PM, SUPC, TAL */
#pragma weak WDT_Handler              = Dummy_Handler
#pragma weak RTC_Handler              = Dummy_Handler
#pragma weak EIC_Handler              = Dummy_Handler
#pragma weak FREQM_Handler            = Dummy_Handler
#ifdef       ID_TSENS
#pragma weak TSENS_Handler            = Dummy_Handler
#endif
#pragma weak NVMCTRL_Handler          = Dummy_Handler
#pragma weak DMAC_Handler             = Dummy_Handler
#pragma weak EVSYS_Handler            = Dummy_Handler
#pragma weak SERCOM0_Handler          = Dummy_Handler
#pragma weak SERCOM1_Handler          = Dummy_Handler
#pragma weak SERCOM2_Handler          = Dummy_Handler
#pragma weak SERCOM3_Handler          = Dummy_Handler
#ifdef       ID_SERCOM4
#pragma weak SERCOM4_Handler          = Dummy_Handler
#endif
#ifdef       ID_SERCOM5
#pragma weak SERCOM5_Handler          = Dummy_Handler
#endif
#ifdef       ID_CAN0
#pragma weak CAN0_Handler             = Dummy_Handler
#endif
#ifdef       ID_CAN1
#pragma weak CAN1_Handler             = Dummy_Handler
#endif
#pragma weak TCC0_Handler             = Dummy_Handler
#ifdef       ID_TCC1
#pragma weak TCC1_Handler             = Dummy_Handler
#endif
#ifdef       ID_TCC2
#pragma weak TCC2_Handler             = Dummy_Handler
#endif
#pragma weak TC0_Handler              = Dummy_Handler
#pragma weak TC1_Handler              = Dummy_Handler
#pragma weak TC2_Handler              = Dummy_Handler
#pragma weak TC3_Handler              = Dummy_Handler
#pragma weak TC4_Handler              = Dummy_Handler
#ifdef       ID_ADC0
#pragma weak ADC0_Handler             = Dummy_Handler
#endif
#ifdef       ID_ADC1
#pragma weak ADC1_Handler             = Dummy_Handler
#endif
#ifdef       ID_AC
#pragma weak AC_Handler               = Dummy_Handler
#endif
#ifdef       ID_DAC
#pragma weak DAC_Handler              = Dummy_Handler
#endif
#ifdef       ID_SDADC
#pragma weak SDADC_Handler            = Dummy_Handler
#endif
#ifdef       ID_PTC
#pragma weak PTC_Handler              = Dummy_Handler
#endif

/* Exception Table */
#pragma language = extended
#pragma segment  = "CSTACK"

/* The name "__vector_table" has special meaning for C-SPY: */
/* it is where the SP start value is found, and the NVIC vector */
/* table register (VTOR) is initialized to this address if != 0 */

#pragma section  = ".intvec"
#pragma location = ".intvec"
const DeviceVectors __vector_table[] = {
        __sfe("CSTACK"),
        (void*) Reset_Handler,
        (void*) NMI_Handler,
        (void*) HardFault_Handler,
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) SVC_Handler,
        (void*) (0UL), /* Reserved */
        (void*) (0UL), /* Reserved */
        (void*) PendSV_Handler,
        (void*) SysTick_Handler,

        /* Configurable interrupts */
        (void*) SYSTEM_Handler,         /*  0 Main Clock, 32k Oscillators Control, Oscillators Control, Peripheral Access Controller, Power Manager, Supply Controller, Trigger Allocator */
        (void*) WDT_Handler,            /*  1 Watchdog Timer */
        (void*) RTC_Handler,            /*  2 Real-Time Counter */
        (void*) EIC_Handler,            /*  3 External Interrupt Controller */
        (void*) FREQM_Handler,          /*  4 Frequency Meter */
#ifdef ID_TSENS
        (void*) TSENS_Handler,          /*  5 Temperature Sensor */
#else
        (void*) (0UL), /* Reserved*/
#endif
        (void*) NVMCTRL_Handler,        /*  6 Non-Volatile Memory Controller */
        (void*) DMAC_Handler,           /*  7 Direct Memory Access Controller */
        (void*) EVSYS_Handler,          /*  8 Event System Interface */
        (void*) SERCOM0_Handler,        /*  9 Serial Communication Interface 0 */
        (void*) SERCOM1_Handler,        /* 10 Serial Communication Interface 1 */
        (void*) SERCOM2_Handler,        /* 11 Serial Communication Interface 2 */
        (void*) SERCOM3_Handler,        /* 12 Serial Communication Interface 3 */
#ifdef ID_SERCOM4
        (void*) SERCOM4_Handler,        /* 13 Serial Communication Interface 4 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_SERCOM5
        (void*) SERCOM5_Handler,        /* 14 Serial Communication Interface 5 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_CAN0
        (void*) CAN0_Handler,           /* 15 Control Area Network 0 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_CAN1
        (void*) CAN1_Handler,           /* 16 Control Area Network 1 */
#else
        (void*) (0UL), /* Reserved*/
#endif
        (void*) TCC0_Handler,           /* 17 Timer Counter Control 0 */
#ifdef ID_TCC1
        (void*) TCC1_Handler,           /* 18 Timer Counter Control 1 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_TCC2
        (void*) TCC2_Handler,           /* 19 Timer Counter Control 2 */
#else
        (void*) (0UL), /* Reserved*/
#endif
        (void*) TC0_Handler,            /* 20 Basic Timer Counter 0 */
        (void*) TC1_Handler,            /* 21 Basic Timer Counter 1 */
        (void*) TC2_Handler,            /* 22 Basic Timer Counter 2 */
        (void*) TC3_Handler,            /* 23 Basic Timer Counter 3 */
        (void*) TC4_Handler,            /* 24 Basic Timer Counter 4 */
#ifdef ID_ADC0
        (void*) ADC0_Handler,           /* 25 Analog Digital Converter 0 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_ADC1
        (void*) ADC1_Handler,           /* 26 Analog Digital Converter 1 */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_AC
        (void*) AC_Handler,             /* 27 Analog Comparators */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_DAC
        (void*) DAC_Handler,            /* 28 Digital Analog Converter */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_SDADC
        (void*) SDADC_Handler,          /* 29 Sigma-Delta Analog Digital Converter */
#else
        (void*) (0UL), /* Reserved*/
#endif
#ifdef ID_PTC
        (void*) PTC_Handler             /* 30 Peripheral Touch Controller */
#else
        (void*) (0UL)  /* Reserved*/
#endif
};

/**------------------------------------------------------------------------------
 * This is the code that gets called on processor reset. To initialize the
 * device.
 *------------------------------------------------------------------------------*/
int __low_level_init(void)
{
        uint32_t *pSrc = __section_begin(".intvec");

        SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);

        return 1; /* if return 0, the data sections will not be initialized */
}

/**------------------------------------------------------------------------------
 * This is the code that gets called on processor reset. To initialize the
 * device.
 *------------------------------------------------------------------------------*/
void Reset_Handler(void)
{
        __iar_program_start();
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
        while (1) {
        }
}
