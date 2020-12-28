// ###################################################################################
// # Project: ECG Health Sensor
// # Engineer:  Mic.Tsai
// # Date:  30 July 2020
// # Objective: Dev.board
// # Usage: ESP8266
// # Modified: ECG
// ###################################################################################
// ########################
#include <ESP8266WiFi.h>
#include <espnow.h>
// ########################
// REPLACE WITH RECEIVER MAC Address
  uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

typedef struct struct_message {
  int a;
  int b;
  int c;
  int d;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}

void setup() {
  // initialize the serial communication:
  Serial.begin(38400);

      WiFi.mode( WIFI_OFF );
      WiFi.forceSleepBegin();
      Serial.println("WiFi is down");

// ########################

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

// ########################


}

void loop() {
  
  delay(20);

// ########################

    // Set values to send
    myData.a = analogRead(A0);
    myData.b = 0;   
    
    // Send message via ESP-NOW
    esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  
// ########################

    Serial.print(millis());
    Serial.print(",");
    Serial.print(myData.a);
    Serial.print(",");
    Serial.print(0);
    Serial.println(",");
  
}

