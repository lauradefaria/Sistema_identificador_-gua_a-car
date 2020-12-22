import serial
import time
import pandas as pd
import re
import matplotlib.pyplot as plt
import pyrebase

#Configuração do firebase
firebaseConfig={"apiKey: AIzaSyB807m67aV902ej85wE5At-4ma3JEunQvA",
    "authDomain: potentiostat-2a3f2.firebaseapp.com",
    "databaseURL: https://potentiostat-2a3f2-default-rtdb.firebaseio.com",
    "projectId: potentiostat-2a3f2",
    "storageBucket: potentiostat-2a3f2.appspot.com",
    "messagingSenderId: 412535919143",
    "appId: 1:412535919143:web:4055386eb62722a3883402",
    "measurementId: G-1JDM2KCZ2Z"}

#Recebe os filhos do nó "Valores"
firebase=pyrebase.initialize_app(firebaseConfig)
db = firebase.database()

#Lista para armazenar todos os valores da tensão e corrente
tensao = []
corrente = []

tensao_db = db.child("Valores").child("Tensao").get()
corrente_db = db.child("Valores").child("Corrente").get()

#Todos os arquivos agrupado
for task in tensao_db.each():
tensao.append(task.val())
print(task.val())

for task in corrente_db.each():
corrente.append(task.val())

#Gera o arquivo em formato CSV
data = {'tensao': tensao, 'corrente': corrente }
csvFile = pd.DataFrame(dataAnalysis, columns=['Tensao', 'Corrente'])
csvFile.to_csv ('experimentData.csv', index = False, header=True)

#Gera o gráfico e salva (plt.savefig)
plt.title('Voltametria cíclica')
plt.xlabel('Tensão (V)')
plt.ylabel('Corrente (A)')
plt.scatter(dataAnalysis['tensao'],dataAnalysis['corrente'])
plt.savefig('experimetData.png', format='png')
plt.show()