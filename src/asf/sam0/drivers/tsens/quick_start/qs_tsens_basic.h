/**
 * \file
 *
 * \brief SAM TSENS Quick Start
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

/**
 * \page asfdoc_sam0_tsens_basic_use_case Quick Start Guide for TSENS - Basic
 *
 * In this use case, the TSENS will be configured with the following settings:
 *  - GCLK generator 0 (GCLK main) clock source
 *  - Free running disabled
 *  - Run in standby
 *  - Window monitor disabled
 *  - All events (input and generation) disabled
 *  - Calibration value which read from NVM or user set
 *
 * \section asfdoc_sam0_tsens_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_tsens_basic_use_case_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * Copy-paste the following setup code to your user application:
 * \snippet qs_tsens_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_tsens_basic.c setup_init
 *
 * \subsection asfdoc_sam0_tsens_basic_use_case_workflow Workflow
 *
 * -# Configure the TSENS module.
 *  -# Create a TSENS module configuration struct, which can be filled out to
 *     adjust the configuration of a physical TSENS peripheral.
 *     \snippet qs_tsens_basic.c setup_config
 *  -# Initialize the TSENS configuration struct with the module's default values.
 *     \snippet qs_tsens_basic.c setup_config_defaults
 *     \note This should always be performed before using the configuration
 *           struct to ensure that all values are initialized to known default
 *           settings.
 *
 *  -# Set TSENS configurations.
 *     \snippet qs_tsens_basic.c setup_set_config
 *  -# Enable the TSENS module so that conversions can be made.
 *     \snippet qs_tsens_basic.c setup_enable
 *
 * \section asfdoc_sam0_tsens_basic_use_case_use Use Case
 *
 * \subsection asfdoc_sam0_tsens_basic_use_case_use_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_tsens_basic.c main
 *
 * \subsection asfdoc_sam0_tsens_basic_use_case_use_workflow Workflow
 *  -# Start conversion.
 *  \snippet qs_tsens_basic.c start_conv
 *  -# Wait until conversion is done and read result.
 *  \snippet qs_tsens_basic.c get_res
 *  -# Enter an infinite loop once the conversion is complete.
 *  \snippet qs_tsens_basic.c inf_loop
 */