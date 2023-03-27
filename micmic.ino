#include <WiFi.h>


#define led_red 12
#define led_blue 13
#define led_green 14
#define led 2

String ClientRequest;

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
  pinMode(led, OUTPUT);

  Serial.begin(115200);
  delay(10);

  Serial.println("START");

  WiFi.begin("rede", "senha");
  WiFi.softAP("rede", "senha");
  Serial.print("Access point running. IP address: ");
  Serial.print(WiFi.softAPIP());
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");

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
    analogWrite(led_green, 180);
    analogWrite(led_blue, 0);}
    
  if (ClientRequest == "apagar")
  {  
    analogWrite(led_red, 0);
    analogWrite(led_green, 0);
    analogWrite(led_blue, 0);}
 
  if (ClientRequest == "Verde")
    {  
    analogWrite(led_red, 0);
    analogWrite(led_green, 255);
    analogWrite(led_blue, 0);
    }

  if (ClientRequest == "azul")
   {  
    analogWrite(led_red, 0);
    analogWrite(led_green, 0);
    analogWrite(led_blue, 255);
    }

  if (ClientRequest == "vermelho")
{  
    analogWrite(led_red, 255);
    analogWrite(led_green, 0);
    analogWrite(led_blue, 0);} 

  if (ClientRequest == "Roxo")
{  
    analogWrite(led_red, 153);
    analogWrite(led_green, 51);
    analogWrite(led_blue, 153);}     
  

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
