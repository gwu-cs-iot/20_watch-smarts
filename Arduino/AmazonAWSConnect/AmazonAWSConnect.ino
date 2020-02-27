#include <ESP8266WiFi.h>
#include <AmazonIOTClient.h>
#include "ESP8266AWSImplementations.h"

Esp8266HttpClient httpClient;
Esp8266DateTimeProvider dateTimeProvider;

AmazonIOTClient iotClient;
ActionError actionError;

char *ssid="MySSID";
char *password="MyPASS";

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to WAP
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  iotClient.setAWSRegion("us-west-2");
  iotClient.setAWSEndpoint("amazonaws.com");
  iotClient.setAWSDomain("a2dbgto9gcvbct-ats.iot.us-west-2.amazonaws.com");
  iotClient.setAWSPath("/things/smart_watch/shadow");
  iotClient.setAWSKeyID("AKIAWHIJ2XVXE3RN75A6");
  iotClient.setAWSSecretKey("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");
  iotClient.setHttpClient(&httpClient);
  iotClient.setDateTimeProvider(&dateTimeProvider);
}

void loop(){
  char* shadow = "{\"state\":{\"reported\": {\"foobar\": \"bar\"}}}";

  char* result = iotClient.update_shadow(shadow, actionError);
  Serial.print(result);

  delay(60000);
}
