# 🌱 **Projeto IoT Sustentabilidade**

Um sistema integrado de monitoramento ambiental com foco em **sustentabilidade**, utilizando **Arduino** e **Node-RED** para coleta, análise e visualização de dados em tempo real.

---

## 📋 **Índice**

- [📖 Descrição Geral](#-descrição-geral)
- [✨ Funcionalidades](#-funcionalidades)
- [💻 Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [🔌 Circuito e Componentes](#-circuito-e-componentes)
- [⚙️ Instalação e Configuração](#️-instalação-e-configuração)
  - [📦 Requisitos](#-requisitos)
  - [🛠️ Configuração do Arduino](#️-configuração-do-arduino)
  - [🖥️ Configuração do Node-RED](#-configuração-do-node-red)
- [🚀 Como Usar](#-como-usar)
- [📊 Exemplos de Saída](#-exemplos-de-saída)
- [🤝 Contribuição](#-contribuição)
- [📜 Licença](#-licença)

---

## 📖 **Descrição Geral**

Este projeto combina sensores ambientais, automação e IoT para monitorar variáveis como **temperatura**, **umidade** e **luminosidade**. Com base nesses dados, LEDs e um buzzer indicam o nível de sustentabilidade do ambiente. Os dados são enviados ao **Node-RED** via **MQTT** para análise e visualização gráfica.

---

## ✨ **Funcionalidades**

✔️ Monitoramento de temperatura, umidade e luminosidade em tempo real.  
✔️ Controle automático com LEDs e buzzer para indicar níveis de sustentabilidade.  
✔️ Abertura automática ou manual de um servo motor.  
✔️ Envio de dados via protocolo MQTT para o **Node-RED**.  
✔️ Dashboard interativo com gráficos e medidores.  
✔️ Interface amigável e fácil de operar.

---

## 💻 **Tecnologias Utilizadas**

### 🔧 **Hardware**

- **Arduino Uno** ou equivalente
- **Sensor DHT22** (temperatura e umidade)
- **Sensor LDR** (luminosidade)
- **LCD 16x2** com módulo I2C
- **Servo Motor SG90**
- **LEDs** (vermelho, amarelo e azul)
- **Buzzer**

### 🖥️ **Software**

- Arduino IDE

---

## 🔌 **Circuito e Componentes**

### 🎛️ **Diagrama Esquemático**
> *(Adicione aqui uma imagem do diagrama de montagem do circuito, caso tenha)*

### 📋 **Lista de Componentes**

| Quantidade | Componente           |
|------------|----------------------|
| 1          | Arduino Uno          |
| 1          | Sensor DHT22         |
| 1          | Sensor LDR           |
| 1          | LCD 16x2 (I2C)       |
| 1          | Servo Motor SG90     |
| 1          | Buzzer               |
| 3          | LEDs (RGB)           |
| 1          | Resistor 10kΩ        |
| -          | Protoboard e fios    |

---

## ⚙️ **Instalação e Configuração**

### 📦 **Requisitos**

- **Hardware:** Montagem completa do circuito com os sensores e atuadores listados.
- **Software:**
  - Arduino IDE com bibliotecas instaladas.
  - Node-RED configurado e acessível.
  - Broker MQTT ativo (como **Mosquitto**).

---

### 🛠️ **Configuração do Arduino**

1. **Instale as bibliotecas necessárias no Arduino IDE:**
   - `DHT Sensor Library`
   - `ArduinoJson`
   - `Servo`
   - `LiquidCrystal_I2C`

2. **Carregue o código:**
   - Abra o código `codigo_arduino.ino` no Arduino IDE.
   - Conecte o Arduino ao computador.
   - Faça o upload para a placa.

---

### 🖥️ **Configuração do Node-RED**

1. **Instale o Node-RED-SerialPort e o Node-RED-Dashboard:**
   ```bash
   npm install -g node-red
   npm install node-red-serialport
   npm install node-red-dashboard
   ```

2. **Configure o fluxo:**
   - Importe o fluxo `fluxo_node_red.json` no Node-RED:
     - Clique no menu no canto superior direito do Node-RED.
     - Escolha a opção **Import > Clipboard**.
     - Cole o conteúdo do arquivo `fluxo_node_red.json`.
     - Clique em **Import**.
   - Ajuste o nó **MQTT IN** para o tópico configurado no Arduino (`testtopic/gs`).

2. **Acesse o Dashboard:**
   - No navegador, abra: `http://localhost:1880/ui`.

---

## 🚀 **Como Usar**

1. **Prepare o Hardware:**
   - Conecte todos os sensores e atuadores ao Arduino.
   - Ligue a alimentação da placa.

2. **Inicie o Node-RED:**
   - Certifique-se de que o broker MQTT está ativo.
   - Inicie o fluxo no Node-RED.

3. **Interaja com o Sistema:**
   - Veja as variáveis em tempo real no LCD e no dashboard.
   - Acione o botão para abrir o servo manualmente.

---

## 📊 **Exemplos de Saída**

### 🌡️ **Dados Monitorados**
- **Temperatura:** `25°C`
- **Umidade:** `60%`
- **Luminosidade:** Exibida em gráfico no Node-RED.

### 💡 **Status Indicados**

| LED              | Significado                      |
|------------------|----------------------------------|
| Azul             | Nível sustentável               |
| Amarelo          | Nível médio de consumo          |
| Vermelho + Buzzer| Consumo excessivo               |

### 📈 **Node-RED Dashboard**

> *(Adicione aqui uma imagem do dashboard ou um exemplo visual.)*

---

## 🤝 **Contribuição**

Contribuições são bem-vindas! Siga os passos abaixo:

1. Faça um fork do repositório.
2. Crie uma branch para sua feature:
   ```bash
   git checkout -b feature-nome
   ```
3. Envie um Pull Request com sua contribuição:
   - Certifique-se de descrever claramente a proposta de alteração.
   - Inclua detalhes sobre a motivação e os benefícios da mudança.

---

## 📜 **Licença**

Este projeto está sob a licença MIT. Veja o arquivo `LICENSE` para mais informações.

---

### 🌟 *Obrigado por conferir este projeto! Qualquer dúvida ou sugestão, sinta-se à vontade para entrar em contato.* 🌟

--

## ✒️ Autores

* **Luiz Felipe Coelho Ramos** - *RM:555074* - [Luiz0770](https://github.com/Luiz0770)
* **Fernando Gonzales Alexandre** - *RM:555045* - [Fernando1403](https://github.com/Fernando1403)
* **Lucas Catroppa Piratininga** - *RM:555450* - [Fernando1403](https://github.com/lucasdias0812)


