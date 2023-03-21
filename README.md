# Trabalho Final de MICMIC - Grupo B

O grupo escolheu desenvolver um projeto com um microcontrolador que é **controlado por voz**. O controle será feito através de um aplicativo para ANDROID, o qual transformará a fala do usuário em texto, e o enviará para o microcontrolador. O microcontrolador, por sua vez, irá realizar uma ação de acordo com o texto recebido.

* Materiais utilizados:

  - Microcontrolador ESP32;
  - LED's;
  - Motores de passo;
  - Manipulador robótico;
  - Celular ANDROID.

* Softwares adotados:

  - Plataforma **Arduino IDE** para programação do ESP32;
  - Plataforma **BIPES** para programação do ESP32 (alternativa);
  - Plataforma **MIT App Inventor** para criação do aplicativo.
  
## Cronograma

*  Semana 1 - 28/02/2023 à 06/03/2023
    
    ✅ Elaboração da ideia principal do projeto;
    
    ✅ Listagem de componentes e softwares principais;
    
    ✅ Criação do repositório e escrita do "README";
    
    ✅ Escrita dos primeiros programas e realização dos primeiros testes.
    
*  Semana 2 - 07/03/2023 à 13/03/2023

    - Aprimorar programa para realizar outros comandos por voz (LED RGB);
    
    - Estudar e implementar o MQTT.
    
*  Semana 3 - 14/03/2023 à 20/03/2023

    - Finalizar projeto;
    - Gravar vídeo-apresentação.


## Semana 1 - 28/02/2023 à 06/03/2023

Na primeira semana de trabalho, o grupo conversou sobre possibilidades de projetos que poderiam ser desenvolvidos. O projeto escolhido foi um controlador por voz. O projeto tem como finaldade controlar atuadores (LED's, motores, etc) utilizando comando de voz. 

Então foi discutido a maneira com que isso seria feito e quais seriam os componentes e softwares utilizados. Decidimos que usaremos o microcontrolador ESP32 e a plataforma **Arduino IDE** para sua programação. Com relação aos componentes, será utilizado um celular ANDROID e LED's que serão controlados. Para sua execução, ficou decidido que seria cirado um aplicativo (MIT App Inventor) para converter o comando de voz em texto e, assim, enviá-lo para o microcontrolador para que o LED possa ser controlado.

Além disso, começamos a esboçar os programas para controlar os LED's e testá-los.

## Semana 2 - 07/03/2023 à 13/03/2023

Nesta semana o projeto começou a ser efetivamente a ser desenvolvido. Então foi criado o aplicativo para ANDROID através do App Inventor. Posteriormente, foi desenvolvido o programa para controlar o LED. Uma importante mudança da semana passada para esta foi a utilização de um LED RGB e com isso, o controle por voz consegue reconhecer a cor com que se deseja ligar o LED. Com esta nova atualização, o código precisou ser modificado para atender essa nova função. 

Um dos desafios encontrados nesta etapa foi conseguir conectar o microcontrolador à uma rede. Primeiramente tentamos conectá-lo ao EDUROAM, porém não estava dando certo e então, como alternativa, conetamos a uma rede compartilhada por um smartphone. Dessa forma a conecção obteve sucesso.

Por fim, foram feitos testes para verificar se tudo estava funcionando conforme o planejado e o resultado foi positivo. Tanto o aplicativo quanto o programa feito estavam controlando o LED da maneira correta.

## Semana 3 - 14/03/2023 à 20/03/2023

Para esta semana o projeto já está todo desenvolvido e então foram realizados os últimos testes para confirmar o sucesso do projeto. Além disso foi discutido com os integrantes como seria feita a apresentação do projeto. A ideia inicial é gravar um vídeo explicando o nosso projeto e o modo como ele foi desenvolvido.

A forma para que isso fosse feito seria apresentação de slides, nestes slides estaria o código usado no projeto, o qual seria explicado pelo grupo. Depois da explicação sobre o programa, um vídeo do projeto em funcionamento seria mostrado.

## Semana 4 - 21/03/2023 à 27/03/2023

Esta semana está destinada para a criação propriamente dita do vídeo sobre nosso projeto (como foi descrito acima). E, consequentemente, para sua aprentação no dia 28/03. 


