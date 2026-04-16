#include <WiFi.h>
#include <PubSubClient.h>

//DATOS DE LA RED
const char* ssid = "SSID";
const char* password = "PASSWORD"; 
const char* mqtt_server = "IP"; // <-- CAMBIA ESTO POR LA IP DE TU RASPBERRY

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;

void setup() {
  Serial.begin(115200);
  
  // Forzar modo estación para mayor estabilidad
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  //CICLO PARA CONECTAR CON LA RED A LA ESP32
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectado!");
  
  client.setServer(mqtt_server, 1883);
}


  //ALGORITMO PARA USAR CON EL SERVIDOR MQTT DE LA RAPSBERRY
void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    if (client.connect("ESP32_Diego_ESCOM")) { // ID único
      Serial.println("¡CONECTADO AL BROKER!");
    } else {
      Serial.print("falló, rc=");
      Serial.print(client.state());
      Serial.println(" reintentando en 5s");
      delay(5000);
    }
  }
}
//PARA NO PERDER LA CONEXIÓN
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    String mensaje = "Logre la practica, profesor. Soy Diego Cardenas.";
    client.publish("escom/practica", mensaje.c_str());
    Serial.println("Mensaje enviado a la Raspberry!");
  }
}