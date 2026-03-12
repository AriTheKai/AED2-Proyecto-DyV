import matplotlib

matplotlib.use("Agg")

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# Leer CSV
df = pd.read_csv("resultados.csv")
df.columns = [c.strip() for c in df.columns]

# Adaptar nombres del CSV al formato sin espacios para simplificar el resto del script
df = df.rename(columns={"Mejor Caso": "MejorCaso", "Peor Caso": "PeorCaso"})

# Calcular variables auxiliares
df["n"] = df["Longitud"]
df["nlog2n"] = df["Longitud"] * (np.log2(df["Longitud"]) ** 2)

# --- REGRESION PARA MEJOR CASO: T(n) vs n ---
slope_mejor, intercept_mejor, r_mejor, p_mejor, _ = stats.linregress(df["n"], df["MejorCaso"])

# --- REGRESION PARA PEOR CASO: T(n) vs n log^2 n ---
slope_peor, intercept_peor, r_peor, p_peor, _ = stats.linregress(df["nlog2n"], df["PeorCaso"])
mse_peor = np.mean((df["PeorCaso"] - (slope_peor * df["nlog2n"] + intercept_peor)) ** 2)

# Resultados
print("   Regresion lineal MejorCaso ~ n")
print(f"  Pendiente: {slope_mejor:.6f}")
print(f"  R2: {r_mejor**2:.4f}")
print(f"  MSE: {np.mean((df['MejorCaso'] - (slope_mejor * df['n'] + intercept_mejor))**2):.4f}")
print(f"  p-valor: {p_mejor:.4e}\n")

print("   Regresion lineal PeorCaso ~ n log^2 n")
print(f"  Pendiente: {slope_peor:.6f}")
print(f"  R2: {r_peor**2:.4f}")
print(f"  MSE: {mse_peor:.4f}")
print(f"  p-valor: {p_peor:.4e}\n")


# 1. Grafico de dispersion sin ajuste (x en log)
plt.figure()
plt.scatter(df["Longitud"], df["MejorCaso"], label="MejorCaso", marker="o")
plt.scatter(df["Longitud"], df["PeorCaso"], label="PeorCaso", marker="x")
plt.xscale("log", base=2)
plt.xlabel("n")
plt.ylabel("Tiempo (us)")
plt.title("Mejor y Peor Caso")
plt.legend()
plt.grid(True)
plt.savefig("scatter_plot_log.pdf")
plt.close()

# 2. Ajuste mejor caso ~ Theta(n)
plt.figure()
plt.plot(df["Longitud"], df["MejorCaso"], "o", label="MejorCaso")
plt.plot(df["Longitud"], slope_mejor * df["n"] + intercept_mejor, label=r"Ajuste $\Theta(n)$")
plt.xscale("log", base=2)
plt.xlabel("n")
plt.ylabel("Tiempo (us)")
plt.title(r"Mejor caso $\sim \Theta(n)$")
plt.legend()
plt.grid(True)
plt.savefig("ajuster_mejor_log.pdf")
plt.close()

# 3. Ajuste peor caso ~ Theta(n log^2 n)
plt.figure()
plt.plot(df["Longitud"], df["PeorCaso"], "x", label="PeorCaso")
plt.plot(df["Longitud"], slope_peor * df["nlog2n"] + intercept_peor, label=r"Ajuste $\Theta(n \log^2 n)$")
plt.xscale("log", base=2)
plt.xlabel("n")
plt.ylabel("Tiempo (us)")
plt.title(r"Peor caso $\sim \Theta(n\log^2n)$")
plt.legend()
plt.grid(True)
plt.savefig("ajuster_peor_log.pdf")
plt.close()

# Idem pero sin log en el eje x

# 1. Grafico de dispersion sin ajuste
plt.figure()
plt.scatter(df["Longitud"], df["MejorCaso"], label="MejorCaso", marker="o")
plt.scatter(df["Longitud"], df["PeorCaso"], label="PeorCaso", marker="x")
plt.xlabel("n")
plt.ylabel("Tiempo (us)")
plt.title("Mejor y Peor Caso")
plt.legend()
plt.grid(True)
plt.savefig("scatter_plot.pdf")
plt.close()

# 2. Ajuste mejor caso ~ Theta(n)
plt.figure()
plt.plot(df["Longitud"], df["MejorCaso"], "o", label="MejorCaso")
plt.plot(df["Longitud"], slope_mejor * df["n"] + intercept_mejor, label=r"Ajuste $\Theta(n)$")
plt.xlabel("n")
plt.ylabel("Tiempo (us)")
plt.title(r"Mejor caso $\sim \Theta(n)$")
plt.legend()
plt.grid(True)
plt.savefig("ajuster_mejor.pdf")
plt.close()

# 3. Ajuste peor caso ~ Theta(n log^2 n)
plt.figure()
plt.plot(df["Longitud"], df["PeorCaso"], "x", label="PeorCaso")
plt.plot(df["Longitud"], slope_peor * df["nlog2n"] + intercept_peor, label=r"Ajuste $\Theta(n \log^2 n)$")
plt.xlabel("n")
plt.ylabel("Tiempo (us)")
plt.title(r"Peor caso $\sim \Theta(n\log^2n)$")
plt.legend()
plt.grid(True)
plt.savefig("ajuster_peor.pdf")
plt.close()

