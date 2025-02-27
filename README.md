# Projeto Embarcatech - Unidade 4 | Capítulo 5 : C5O123A - Temporizadores

---

## 📌 Sobre o Projeto

**Tarefa 01 - Dia 29/01/2025**  
Este projeto é composto por **2 códigos**:

### 1. Atividade 1: Semáforo Periódico 🚦
- **Objetivo:**  
  Alternar entre três estados (vermelho, amarelo e verde) a cada 3 segundos.
- **Funcionamento:**  
  - Utiliza a função `add_repeating_timer_ms()` do Pico SDK para criar um temporizador que dispara a cada 3 segundos.
  - Em cada disparo, o callback do temporizador altera o estado do semáforo, acendendo o LED correspondente.
  - No loop principal, é exibida uma mensagem no terminal a cada segundo, mostrando o estado atual do semáforo.
  
### 2. Atividade 2: Temporizador de Um Disparo (One Shot) com Debounce ⏱️🔘
- **Objetivo:**  
  Acionar um sistema de temporização para desligar LEDs em sequência após o pressionamento de um botão.
- **Funcionamento:**  
  - Ao pressionar o botão, os três LEDs (azul, vermelho e verde) acendem simultaneamente.
  - É utilizado a função `add_alarm_in_ms()` para criar um alarme que, após 3 segundos, desliga o primeiro LED. Em seguida, o próximo LED é desligado com outro intervalo de 3 segundos, e assim por diante.
  - Uma rotina de debounce em software é implementada para evitar múltiplos acionamentos devido ao efeito bouncing do botão.
  - O botão só permite uma nova ação quando todos os LEDs estiverem desligados.

---

## ⚙️ Diagrama de Conexões (Wokwi)

O projeto foi simulado no [Wokwi](https://wokwi.com/) com as seguintes conexões:

- **LEDs:**
  - LED Azul: GPIO 11
  - LED Vermelho: GPIO 12
  - LED Verde: GPIO 13
- **Botão:**
  - Botão: GPIO 5

Consulte o arquivo `diagram.json` para mais detalhes sobre as conexões.

---

## 📚 Peculiaridade do Projeto


- O projeto 01 foi pensando em conformidade com a BitDogLab para ser usado com o sistema RGB, assin acendendo a cor amarela pelo acionamento dos pinos vermeelho e verde, alternativamente existe comentado no codigo sua estrutura com o led amarelo sendo utilizado, para a simulação.

