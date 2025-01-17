/****************************************************************************
 * arch/xtensa/src/esp32s3/esp32s3_touch.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_TOUCH_H
#define __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_TOUCH_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>
#include <stdbool.h>

#include "esp32s3_touch_lowerhalf.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define TOUCH_SLOPE_DEFAULT               (TOUCH_SLOPE_7)
#define TOUCH_TIE_OPT_DEFAULT             (TOUCH_TIE_OPT_LOW)
#define TOUCH_HIGH_VOLTAGE_THRESHOLD      (TOUCH_HVOLT_2V7)
#define TOUCH_LOW_VOLTAGE_THRESHOLD       (TOUCH_LVOLT_0V5)
#define TOUCH_ATTEN_VOLTAGE_THRESHOLD     (TOUCH_HVOLT_ATTEN_0V5)
#define TOUCH_IDLE_CH_CONNECT_DEFAULT     (TOUCH_CONN_GND)
#define TOUCH_THRESHOLD_MAX               (0x1fffff)
#define TOUCH_SLEEP_CYCLE_DEFAULT         (0xf)
#define TOUCH_MEASURE_CYCLE_DEFAULT       (500)
#define TOUCH_DEBOUNCE_CNT_MAX            (7)
#define TOUCH_NOISE_THR_MAX               (3)
#define TOUCH_JITTER_STEP_MAX             (15)
#define TOUCH_PROXIMITY_CHANNEL_NUM       (3)

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__

struct touch_config_s
{
  enum touch_high_volt_e refh;
  enum touch_low_volt_e refl;
  enum touch_volt_atten_e atten;
  enum touch_cnt_slope_e slope;
  enum touch_tie_opt_e tie_opt;
  enum touch_fsm_mode_e fsm_mode;
#ifdef CONFIG_ESP32S3_TOUCH_FILTER
  enum touch_filter_mode_e filter_mode;
  uint32_t filter_debounce_cnt;
  uint32_t filter_noise_thr;
  uint32_t filter_jitter_step;
  enum touch_smooth_mode_e filter_smh_lvl;
#endif
#ifdef CONFIG_ESP32S3_TOUCH_DENOISE
  enum touch_denoise_grade_e denoise_grade;
  enum touch_denoise_cap_e denoise_cap_level;
#endif
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* Store GPIO number corresponding to the Touch Sensor channel number.
 * Note: T0 is an internal channel that does not have a corresponding
 * external GPIO.
 */

static const int touch_channel_to_gpio[] =
{
  -1,
  TOUCH_PAD_NUM1_GPIO_NUM,
  TOUCH_PAD_NUM2_GPIO_NUM,
  TOUCH_PAD_NUM3_GPIO_NUM,
  TOUCH_PAD_NUM4_GPIO_NUM,
  TOUCH_PAD_NUM5_GPIO_NUM,
  TOUCH_PAD_NUM6_GPIO_NUM,
  TOUCH_PAD_NUM7_GPIO_NUM,
  TOUCH_PAD_NUM8_GPIO_NUM,
  TOUCH_PAD_NUM9_GPIO_NUM,
  TOUCH_PAD_NUM10_GPIO_NUM,
  TOUCH_PAD_NUM11_GPIO_NUM,
  TOUCH_PAD_NUM12_GPIO_NUM,
  TOUCH_PAD_NUM13_GPIO_NUM,
  TOUCH_PAD_NUM14_GPIO_NUM
};

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: esp32s3_configtouch
 *
 * Description:
 *   Configure a touch pad channel.
 *
 * Input Parameters:
 *   tp - The touch pad channel;
 *   config - The touch pad configuration structure.
 *
 * Returned Value:
 *   OK.
 *
 ****************************************************************************/

int esp32s3_configtouch(enum touch_pad_e tp, struct touch_config_s config);

/****************************************************************************
 * Name: esp32_touchread
 *
 * Description:
 *   Read a touch pad channel.
 *
 * Input Parameters:
 *   tp - The touch pad channel.
 *
 * Returned Value:
 *   0 if touch pad pressed, 1 if released.
 *
 ****************************************************************************/

bool esp32s3_touchread(enum touch_pad_e tp);

/****************************************************************************
 * Name: esp32s3_touchbenchmark
 *
 * Description:
 *   Read the touch pad channel benchmark.
 *
 * Input Parameters:
 *   tp - The touch pad channel.
 *
 * Returned Value:
 *   The benchmark value.
 *
 ****************************************************************************/

uint32_t esp32s3_touchbenchmark(enum touch_pad_e tp);

/****************************************************************************
 * Name: esp32s3_touchsetthreshold
 *
 * Description:
 *   Set the touch pad channel threshold.
 *
 * Input Parameters:
 *   tp - The touch pad channel;
 *   threshold - The threshold value.
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

void esp32s3_touchsetthreshold(enum touch_pad_e tp, uint32_t threshold);

#ifdef __cplusplus
}
#endif
#undef EXTERN

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_XTENSA_SRC_ESP32S3_ESP32S3_TOUCH_H */
