# System for identifying salt and sugar in a solution

## Contents
+ [Motivation](#motivation)
+ [Getting Started](#getting-started)
+ [Required content](#required-content)
+ [Items accomplished](#items-accomplished)

<h2 id="Motivation">Motivation</h2>

The objective of this project is to develop a system for the detection and analysis of salt and sugar in a solution, using the cyclic voltammetry technique. In order to accomplish this, concepts from electronics (operational amplifiers, current-to-voltage converter, filters, offset control) and programming (Python, Arduino, and ESP) were employed to simulate a prototype.


<h2 id="Getting Started">Getting Started</h2>

Please adhere to these instructions to replicate the procedure. All codes and circuit files are located above, along with a PDF containing the theoretical part and images of simulation results.

<h3 id='Prerequisites'>Prerequisites</h3>

The main prerequisites are the following software: LTspice, Proteus (v8.6), Arduino IDE, and Visual Studio Code.

To program the ESP8266 in VS Code, it is necessary to install an extension called "PlatformIO". Additionally, certain libraries that are not included in the listed software need to be added, and an installation guide can be found in the attachments of the PDF document.

<h3 id='Setup'>Setup</h3>

In addition to the Arduino code, the ESP8266 and Python codes are located above. Both are within the "potentiostat" folder, under the "src" subdivision.

To execute the ESP8266 code, it is necessary to install the aforementioned expansion and libraries (link to tutorial: <a href="https://www.embarcados.com.br/esp8266-com-arduino">tutorial link</a>). To generate graphs, create a CSV file, and read data from Firebase, it is necessary to install the pandas, pyrebase, and matplotlib libraries. 
```
!pip install pandas
```
```
!pip install pyrebase
```
```
!pip install matplotlib
```


<h2 id="Required content">Required content</h2>

<h3 id='Schematic and simulations'>Schematic and simulations</h3>

The simulations were performed using the software Proteus and LTspice, as there were issues with offset control in Proteus. Therefore, to achieve optimal functionality, each part was simulated separately. The file names are "Completo" and "Offset".

The schematics can be found in the "Results - Schematic" section, and their corresponding simulation results are available in the "Results - Simulation" section of the PDF.

The Arduino code (PWM) is located in the "potentiostat_Arduino" folder and should be included in Proteus, as demonstrated in the attached file. The required libraries are located in the "Extra" folder, which should be included following the protocol outlined in the attachments.

Note: The Proteus files are in PCB design format. To simulate the signal conversion or current-to-voltage converter, you need to replace the "Tblock" with corresponding voltage sources. Additionally, the "Input" should be changed to pin 10 of the Arduino Uno, and the ESP8266 should be removed as it is not simulatable.

<h3 id='Printed Circuit Board (PCB)'>Printed Circuit Board (PCB)</h3>

The 3D visualization and connections of the printed circuit board are located in the "Results - Printed Circuit Board" section of the PDF.

<h2 id='Items accomplished'>Items accomplished</h2>

+ Enable the hardware operator to utilize the cyclic voltammetry technique for the analysis of the aqueous substance.
+ Provide a list of necessary equipment and materials for the construction of the device.
+ Present the schematic circuit diagram.
+ Simulate the functioning of the circuit.
+ Design the printed circuit board.
+ Export the cyclic voltammetry reading data in graphical form.
+ Export the cyclic voltammetry reading data in CSV file format.
