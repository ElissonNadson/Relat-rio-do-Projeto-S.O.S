#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN 11
#define DURACAO_PONTO 200
#define DURACAO_TRACO 800
#define DURACAO_GAP 125
#define DURACAO_GAP_LETRA 250
#define DURACAO_GAP_CICLO 3000

void ponto() {
    printf("LED LIGADO (ponto)\n");
    gpio_put(LED_PIN, 1);
    sleep_ms(DURACAO_PONTO);
    gpio_put(LED_PIN, 0);
    printf("LED DESLIGADO\n");
    sleep_ms(DURACAO_GAP);
}

void traco() {
    printf("LED LIGADO (traço)\n");
    gpio_put(LED_PIN, 1);
    sleep_ms(DURACAO_TRACO);
    gpio_put(LED_PIN, 0);
    printf("LED DESLIGADO\n");
    sleep_ms(DURACAO_GAP);
}

void enviar_sos() {
    printf("Enviando SOS...\n");
    // S: "..."
    ponto(); ponto(); ponto();
    sleep_ms(DURACAO_GAP_LETRA);
    // O: "---"
    traco(); traco(); traco();
    sleep_ms(DURACAO_GAP_LETRA);
    // S: "..."
    ponto(); ponto(); ponto();
    printf("SOS enviado.\n");
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        enviar_sos();
        sleep_ms(DURACAO_GAP_CICLO);
    }
}
