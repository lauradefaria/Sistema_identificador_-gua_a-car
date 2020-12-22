# Sistema identificador de sal e açúcar em solução

## Índice
+ [Sobre](#sobre)
+ [Pré-requisitos](#pre_req)
+ [Esquemático e simulações](#sim)
+ [Placa de circuito impresso](#cir)
+ [Códigos](#cod)

<h2 id="sobre">Sobre</h2>

O objetivo desse projeto é construir um sistema de detecção de sal ou açúcar em um recipiente com água, utilizando o método da voltametria cíclica.

<h2 id="comecando">Começando</h2>

Siga estas instruções para replicar o procedimento. Todos os códigos e arquivos de circuitos se localizam acima, além de um pdf com a parte teórica e imagens dos resultados das simulações.

<h3 id='pre_req'>Pré-requisitos</h3>

Os principais pré-requisito são os softwares: LTspice, Proteus (v8.6), Arduino IDE e Visual Studio Code.

Para programar a ESP8266 no VS Code, torna-se necessário instalar uma extensão chamada "PlatformIO". Além disso, precisa-se adicionar algumas bibliotecas que não estão presentes nos softwares listados, possuindo um guia de instalação nos anexos do pdf.

<h2 id="obr">Conteúdo obrigatório</h2>

<h3 id='sim'>Esquemático e simulações</h3>

As simulações foram realizadas através dos softwares Proteus e LTspice, uma vez que houve falhas no controle do offset pelo Proteus. Assim, para uma melhor funcionalidade, simulou-se todas as partes separadamente. Os nomes dos arquivos são "Completo" e "Offset".

Os esquemáticos se encontram na seção "Resultados - Esquemático" e seus resultados em "Resultados - Simulação" do pdf.

O código do arduino (pwm) está na pasta "potentiostat_Arduino", e deve ser incluido no Proteus, como demonstrado no anexo. Já as bibliotecas, se encontram na pasta "Extra", as quais serão incluidas seguindo o protocólo constatado nos anexos.

Observação: Os arquivos do proteus estão no formato para design da PCB, para simular a parte de conversão do sinal ou corversor corrente-tensão, deve-se substituir oas "Tblock" por fontes de tensão correspondetes. Além disso, precisa-se mudar a "Entrada" para o pino 10 do Arduino uno e retirar a ESP8266, uma vez que ela não é simulável.

<h3 id='cir'>Placa de circuito impresso</h3>

A vizualização 3D e ligações da placa de circuito impresso localizam-se na seção "Resultados - Placa de circuito impresso" do pdf.

<h3 id='cod'>Códigos</h3>

Além do código do arduino, estão localizados acima os códigos da ESP8266 e em Python. Ambos estão na pasta "potentiostat", na subdivisão "src".

Para executar o código da ESP8266, é preciso instalar a expansão citada anteriormente e a bibliotecas (<a href="https://www.embarcados.com.br/esp8266-com-arduino">link para tutorial</a>).

Para gerar os gráficos, gerar um arquivo CSV e ler os dados do firebase, é necessário instalar as bibliotecas pandas, pyrebase e matplotlib. Para instalar através do Anaconda prompt: 
```
Conda install pandas
```
```
Conda install pyrebase
```
```
Conda install matplotlib
```
<h2 id='todo'>Itens concluídos</h2>

- Permitir que o operador do hardware possa utilizar a técnica de voltametria
cíclica para análise da substância aquosa
- Lista de equipamentos e materiais necessários para a construção do
equipamento
- Esquemático do circuito
- Simulação do circuito em funcionamento
- Design da placa de circuito impresso
- Exportar em forma de gráficos os dados de leitura da técnica de
voltametria cíclica
- Exportar em forma de arquivo CSV os dados de leitura da técnica de
voltametria cíclica


