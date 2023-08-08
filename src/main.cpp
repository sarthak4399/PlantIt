#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

#include <addons/TokenHelper.h>

#include <addons/RTDBHelper.h>

#define WIFI_SSID "RNXG"
#define WIFI_PASSWORD "Loop@rnxg22-23"

#define API_KEY "AIzaSyDEQbyt0lAQSAIA75lgoSwAqJvoA52GDYA"

#define DATABASE_URL "https://myesp32-615e9-default-rtdb.firebaseio.com/"

#define USER_EMAIL "rnxgattendance2022@gmail.com"
#define USER_PASSWORD "rnxg@2022"

FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;

void setup()
{

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback;
  config.database_url = DATABASE_URL;
  config.signer.tokens.legacy_token = "<AE7GafzXdp0TOH4cFp3ts5lPrIZdbT9tIpq4VmXq>";
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop()
{
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();

    FirebaseJson json;
    json.setDoubleDigits(3);
  }
}
