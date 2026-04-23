# Práctica: IoT con MQTT (ESP32 + Raspberry Pi)

## Descripción
Este proyecto implementa un sistema de comunicación inalámbrica utilizando el protocolo **MQTT**. Se utiliza un microcontrolador **ESP32** como nodo de publicación (*Publisher*) y una **Raspberry Pi 3** como servidor de mensajería (*Broker*).

## Objetivos de Aprendizaje
* Comprender y aplicar el protocolo MQTT en entornos IoT.
* Instalar y configurar el broker **Mosquitto** en una Raspberry Pi.
* Programar un Publisher en ESP32 para enviar mensajes estructurados.
* Documentar procesos técnicos bajo estándares de control de versiones con Git.

## Requisitos
* **Hardware:**
  * ESP32 (WROOM-DA Module).
  * Raspberry Pi 3 Model B+.
* **Software:**
  * Arduino IDE (Librería `PubSubClient`).
  * Mosquitto MQTT Broker.

## Configuración del Broker (Raspberry Pi)
Se habilitó el acceso externo modificando el archivo `/etc/mosquitto/conf.d/external.conf`:
```text
listener 1883
allow_anonymous true

El servicio se reinició mediante sudo systemctl restart mosquitto.

## Configuración del Broker (Raspberry Pi)
Configuración: Actualizar los campos ssid, password e ip_server en el código .ino.

Carga: Subir el script al ESP32 mediante Arduino IDE.

Suscripción: En la terminal de la Raspberry Pi, ejecutar el comando:

Bash
mosquitto_sub -t "escom/practica" -v
Evidencia de Funcionamiento
1. Conexión del ESP32 a la Red
El Monitor Serial confirma que el ESP32 se asocia correctamente al Wi-Fi "REDJSPY" y establece el handshake con el Broker en la IP 192.168.1.175:
<img width="1552" height="214" alt="serialESP32ConectadoAInternet" src="https://github.com/user-attachments/assets/40b4cbdf-7dda-459e-9c00-2d8d6ac29b1e" />


2. Estado del Broker en Espera
Configuración de la terminal de la Raspberry Pi, lista y a la escucha de paquetes en el tópico escom/practica:
<img width="512" height="74" alt="mosquittoEsperaRecepcionMensajes" src="https://github.com/user-attachments/assets/02cccddb-a0ed-43bc-a02f-3f79a345c82d" />


3. Recepción de Mensajes (Telemetría)
Se observa el flujo continuo de datos recibidos exitosamente, validando la comunicación entre ambos dispositivos:
<img width="717" height="227" alt="mensajesRecibidosRP" src="https://github.com/user-attachments/assets/cc3ddb71-b326-404e-bc9f-a8acb32bbcd2" />



4. Entorno de Ejecución en Raspberry Pi
Vista general de la terminal del servidor durante la ejecución de la práctica:

Autor: Diego Aarón Cárdenas Mendoza

Institución: Escuela Superior de Cómputo (ESCOM) - IPN

Semestre: 6to Semestre
