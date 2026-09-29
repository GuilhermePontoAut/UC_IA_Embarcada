#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dht.h"

#define DHT_GPIO GPIO_NUM_1
#define DHT_TYPE DHT_TYPE_AM2301

void app_main(void)
{
    float temperatura;
    float umidade;

    while (1)
    {
        if (dht_read_float_data(DHT_TYPE, DHT_GPIO,
                                &umidade, &temperatura) == ESP_OK)
        {
            printf("Temperatura: %.1f °C | Umidade: %.1f %%\n",
                   temperatura, umidade);
        }
        else
        {
            printf("Erro ao ler o DHT22\n");
        }

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
