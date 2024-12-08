#include "buttonTask.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define BUTTON_GPIO GPIO_NUM_0

static const char *TAG = "BUTTON";
TaskHandle_t button;

void buttonTask(void *pvParameter) {
  // Configure the button GPIO as input with pull-up resistor
  gpio_config_t btn_config = {};
  btn_config.intr_type = GPIO_INTR_DISABLE; // We'll use polling
  btn_config.mode = GPIO_MODE_INPUT;
  btn_config.pin_bit_mask = (1ULL << BUTTON_GPIO);
  btn_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
  btn_config.pull_up_en =
      GPIO_PULLUP_ENABLE; // Enable internal pull-up resistor

  gpio_config(&btn_config);

  while (1) {
    int button_state = gpio_get_level(BUTTON_GPIO);
    if (button_state == 0) { // Button pressed (active low)
      ESP_LOGI(TAG, "Button pressed!");
      // Perform action based on button press
      // Add debouncing logic here if needed
    }

    vTaskDelay(pdMS_TO_TICKS(10)); //  Poll every 10ms. Adjust as needed
  }
}
