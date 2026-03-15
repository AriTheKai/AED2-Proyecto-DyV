# ✨ Práctica DyV
Práctica que resuelve el problema 7 de la colección de ejercicios. Este problema se basa en encontrar subcadenas vñalidas dentro de una cadena dada. Para que estos segmentos sean válidos, los caracteres que los comformen deberán estar contenidos en un conjunto $S$. <br>
El programa está escrito en C++ y, a parte de filtrar dichas subcadenas, se encarga de medir los tiempos y generar gráficas de estos últimos.
<br> <br>

# 🛝 Estructura
- **common.cpp** ~ Fichero con funciones auxiliares para imprimir la solución así como identificar las subcadenas validas.
- **dyv.cpp** ~ Fichero con la función que realiza el estudio de las cadenas mediante la estrategia "Divide y Vencerás".
- **iterativo.cpp** ~ Fichero con la función que realiza el estudio de las cadenas mediante la estrategia iterativa.
- **regresion.py** ~ Fichero que contiene el código que genera las gráficas de tiempos.
- **testsAleatorios.cpp** ~ Fichero que contiene el código para generar cadenas aleatorias.
- **testsUnitarios.cpp** ~ Fichero que contiene el código para generar los casos de prueba mencionados en el apartado de Validación.
- **tiempos.cpp** ~ Fichero con el código para el cálculo de las longitudes de las cadenas y medianas de los tiempos. 
<br> <br> 

# 🧨 Requisitos
Herramientas del sistema (Linux): <br>
- g++ (C++11 o superior)
- make
- Python 3.8+ y `pip`
Instalación rápida en Ubuntu:<br>

```
sudo apt update
sudo apt install -y g++ make python3 python3-pip
```
<br>
Dependencias Python (para `regresion.py`):

```
python3 -m pip install --upgrade pip
python3 -m pip install pandas numpy matplotlib scipy
```
<br>
Opcional (recomendado): entorno virtual <br>

```
python3 -m venv .venv
source .venv/bin/activate
pip install pandas numpy matplotlib scipy
```
<br> <br>

# 📊 Análisis y gráficas (opcional)
Con `resultados.csv`  generado, lanzar el script de regresión y guardar gráficas en PDF:

```
python3 ./regresion.py
```
El script imprime métricas (pendiente, R 2 , M S E , etc.) y crea los ficheros: <br>
- `scatter_plot_log.pdf`, `ajuster_mejor_log.pdf`, `ajuster_peor_log.pdf`.
- `scatter_plot.pdf`, `ajuster_mejor.pdf`, `ajuster_peor.pdf`.
<br> <br>

# 🧹 Limpieza
```
make clean
```
