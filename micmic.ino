#include <WiFi.h>

#define led_red 12
#define led_blue 13
#define led_green 14

String ClientRequest;

IPAddress staticIP(192,168,43,124);
IPAddress gateway(192,168,43,1);
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

  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  pinMode(led_green, OUTPUT);

  Serial.begin(115200);
  delay(10);

  Serial.println("START");

  WiFi.begin("iPhone (3)", "micmic123");
  WiFi.softAP("iPhone (3)", "micmic123");
  Serial.print("Access point running. IP address: ");
  Serial.print(WiFi.softAPIP());
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");

  //WiFi.config(staticIP, gateway, subnet);

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

  if (ClientRequest == "Amarelo")
  {
    analogWrite(led_red, 255);
    analogWrite(led_green, 255);
    analogWrite(led_blue, 0);}
    
  if (ClientRequest == "apagar")
  {  
    analogWrite(led_red, 0);
    analogWrite(led_green, 0);
    analogWrite(led_blue, 0);}
 // if (ClientRequest == "piscar")
  //{
   // digitalWrite(led, HIGH);
    //delay(500);
    //digitalWrite(led, LOW);
    //delay(500);
    //digitalWrite(led, HIGH);
    //delay(500);
    //digitalWrite(led, LOW);
    //delay(500);
    //digitalWrite(led, HIGH);
    //delay(500);
    //digitalWrite(led, LOW);
    //delay(500);
    //digitalWrite(led, HIGH);
    //delay(500);
    //digitalWrite(led, LOW);
    //delay(500);
 // }

  if (ClientRequest == "Verde")
    {  
    analogWrite(led_red, 0);
    analogWrite(led_green, 255);
    analogWrite(led_blue, 0);
    }

  if (ClientRequest == "Azul")
   {  
    analogWrite(led_red, 0);
    analogWrite(led_green, 0);
    analogWrite(led_blue, 255);
    }

  if (ClientRequest == "Vermelho")
{  
    analogWrite(led_red, 255);
    analogWrite(led_green, 0);
    analogWrite(led_blue, 0);}    
  

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
