#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_AZUL 11
#define LED_VERMELHO 12
#define LED_VERDE 13
#define BOTAO 5

#define INTERVALO_ALARME_MS 3000

bool temporizador_ativo = false;
int estado_led = 0;

bool turn_off_callback(struct repeating_timer *t) {
    if (estado_led == 0) {
        gpio_put(LED_AZUL, 0);
        estado_led++;
        add_alarm_in_ms(INTERVALO_ALARME_MS, turn_off_callback, NULL, false);
    } else if (estado_led == 1) {
        gpio_put(LED_VERMELHO, 0);
        estado_led++;
        add_alarm_in_ms(INTERVALO_ALARME_MS, turn_off_callback, NULL, false);
    } else {
        gpio_put(LED_VERDE, 0);
        temporizador_ativo = false;
    }
    return false;
}

void botao_callback(uint gpio, uint32_t events) {
    if (!temporizador_ativo) {
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
        estado_led = 0;
        temporizador_ativo = true;
        add_alarm_in_ms(INTERVALO_ALARME_MS, turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &botao_callback);

    while (1) {
        sleep_ms(100);
    }
}
