#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 13
#define LED_AMARELO 12
#define LED_VERDE 11

#define INTERVALO_TEMPORIZADOR_MS 3000

int estado_semaforo = 0;

bool callback_temporizador(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    if (estado_semaforo == 0) {
        gpio_put(LED_VERMELHO, 1);
    } else if (estado_semaforo == 1) {
        //gpio_piut(LED_AMARELO, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
    } else {
        gpio_put(LED_VERDE, 1);
    }

    estado_semaforo = (estado_semaforo + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();
    
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    struct repeating_timer temporizador;
    add_repeating_timer_ms(INTERVALO_TEMPORIZADOR_MS, callback_temporizador, NULL, &temporizador);

    while (1) {
        printf("Semáforo ativo - Estado atual: %d\n", estado_semaforo);
        if (estado_semaforo == 0) {
            printf("Luz Vermelha - Pare\n");
        } else if (estado_semaforo == 1) {
            printf("Luz Amarela - Atenção\n");
        } else {
            printf("Luz Verde - Siga\n");
        }
        sleep_ms(1000);
    }
}
