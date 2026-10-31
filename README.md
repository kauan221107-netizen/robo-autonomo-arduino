#  Robô Autônomo com Arduino

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=cplusplus&logoColor=white)

Projeto de um robô autônomo controlado por Arduino Uno, programado em C++, que usa um sensor ultrassônico para identificar obstáculos.

##  Objetivo
Aprender, na prática, a integração entre hardware e software: leitura de sensores, controle de motores e programação em C++ para Arduino.

##  Funcionalidades
- Anda para frente quando não há obstáculos próximos
- Detecta objetos à frente com o sensor ultrassônico HC-SR04
- Recua ao encontrar um obstáculo a aproximadamente 26 cm ou menos
- Ignora leituras inválidas do sensor (valor 0) e usa timeout para evitar travamentos
- Funciona de forma autônoma, sem celular ou controle remoto

> **Observação:** na versão atual, depois de detectar um obstáculo, o robô entra em modo de recuo permanente. Ele ainda não faz curvas nem desvia automaticamente.

##  Tecnologias e componentes
- **Linguagem:** C++ (Arduino IDE / VS Code)
- Arduino Uno
- 2 motores DC com rodas
- Driver de motor L298N
- Sensor ultrassônico HC-SR04
- Bateria para alimentação
- Chassi com estrutura de suporte
- Jumpers e fios

##  Demonstração
<p align="center">
<img alt="robo" fdaf src="robo.png">
</p>

##  Como usar
1. Monte o circuito com os componentes acima.
2. Abra o arquivo robo-autonomo-arduino.ino na Arduino IDE.
3. Selecione a placa **Arduino Uno** e a porta correta.
4. Clique em **Upload** e ligue a bateria.

##  Esquema de ligação
- Componente e Pino do Arduino
- HC-SR04 (Trig)	8
- HC-SR04 (Echo)	9
- L298N ENA (Motor A)	6 (PWM)
- L298N IN1	7
- L298N IN2	5
- L298N ENB (Motor B)	3 (PWM)
- L298N IN3	4
- L298N IN4	2

## Como funciona a lógica
- O sensor mede a distância à frente do robô.
- Leituras inválidas (0) são ignoradas.
- Se a distância for maior que 26 cm, o robô anda para frente.
- Se for 26 cm ou menos, o robô recua e uma variável de controle (eventoDisparado) mantém o recuo permanente.

##  Desafios e aprendizados
**Desafios:** realizar as conexões dos componentes, controlar os dois motores pelo driver L298N e ajustar a leitura do sensor ultrassônico para identificar corretamente os obstáculos.

**Aprendizados:** programação em C++ com Arduino, funcionamento de sensores, controle de motores, circuitos eletrônicos e integração entre hardware e software.

##  Contato
Kauan José da Silva · [LinkedIn](https://www.linkedin.com/in/kauan-silva-903134266/) · kauan221107@hotmail.com
