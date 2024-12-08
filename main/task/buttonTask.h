// buttonTask.h
#ifndef BUTTON_TASK_H
#define BUTTON_TASK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void buttonTask(void *pvParameter);
extern TaskHandle_t button;

#endif // BUTTON_TASK_H
