/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include <esp_log.h>
#include <inttypes.h>
#include <stdio.h>

extern "C" void app_main(void);
void print_memory_info(void);
void loop(void *pvParameter);

extern "C" void app_main(void) {
  xTaskCreate(loop, "loop", 4096, NULL, 1, NULL);
}

void print_memory_info(void) {
  int free_heap_size = esp_get_free_heap_size();
  ESP_LOGI("memory", "Free heap size: %d bytes", free_heap_size);
}

void loop(void *pvParameter) {
  while (1) {
    print_memory_info();
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}
