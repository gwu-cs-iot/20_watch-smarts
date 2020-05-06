#include <pgmspace.h>

#define SECRET

const char ssid[] = "************";
const char pass[] = "************";

#define THINGNAME "**********" // thing name

int8_t TIME_ZONE = -5; //NYC(USA): -5 UTC
const char MQTT_HOST[] = "*************-ats.iot.us-west-2.amazonaws.com"; // arn

static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
****************************************************************
****************************************************************
-----END CERTIFICATE-----
)EOF";

static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
****************************************************************
****************************************************************
-----END CERTIFICATE-----
)KEY";



// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
****************************************************************
****************************************************************
-----END RSA PRIVATE KEY-----
)KEY";
