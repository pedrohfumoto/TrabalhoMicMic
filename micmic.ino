#include <WiFi.h>

#define led 2

String ClientRequest;

IPAddress staticIP(192,168,0,48);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

WiFiServer server(80);

WiFiClient client;

String myresultat;

String ReadIncomingRequest()
{

  while(client.available())
  {
    ClientRequest = (client.readStringUntil('\r'));

    if ((ClientRequest.indexOf("HTTP/1.1")>0))
      myresultat = ClientRequest;
  }

  return myresultat;

}

void setup() {
  
  ClientRequest = "";

  pinMode(led, OUTPUT);

  Serial.begin(115200);
  delay(10);

  Serial.println("START");

  WiFi.begin("eduroam", "758912");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");

  WiFi.config(staticIP, gateway, subnet);

  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));

  server.begin();

}

void loop() {
  
  client = server.available();

  if(!client)
    return;
  
  while(!client.available())
    delay(1);

  ClientRequest = (ReadIncomingRequest());

  ClientRequest.remove(0, 5);
  ClientRequest.remove(ClientRequest.length()-9,9);

  if (ClientRequest == "acender")
    digitalWrite(led, HIGH);
  if (ClientRequest == "apagar")
    digitalWrite(led, LOW);
  if (ClientRequest == "piscar")
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("");
  client.println("");
  client.println("OK");
  client.println("");
  client.flush();
  client.stop();
  delay(1);  



}
