import matplotlib.pyplot as plt

# Informações
segundos = [50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000]
insertionsort = [2_325_667, 10_717_000, 25_847_000, 47_534_667, 73_141_333, 103_874_333, 140_765_000, 187_018_667]
mergesort = [15_667, 26_333, 42_000, 46_667, 57_333, 73_333, 94_000, 100_000]

# Gráfico Insertion Sort
plt.figure(figsize=(10, 6))
plt.plot(segundos, insertionsort, marker='o', label='Insertion Sort', color='blue')
plt.title('Desempenho do Insertion Sort')
plt.xlabel('Número de Elementos')
plt.ylabel('Tempo de Execução')
plt.grid(True)
plt.legend()
plt.show()

# Gráfico Merge Sort
plt.figure(figsize=(10, 6))
plt.plot(segundos, mergesort, marker='o', label='Merge Sort', color='green')
plt.title('Desempenho do Merge Sort')
plt.xlabel('Número de Elementos')
plt.ylabel('Tempo de Execução')
plt.grid(True)
plt.legend()
plt.show()

# Gráfico comparando Insertion Sort e Merge Sort com escala logarítmica
plt.figure(figsize=(10, 6))
plt.plot(segundos, insertionsort, marker='o', label='Insertion Sort', color='blue')
plt.plot(segundos, mergesort, marker='o', label='Merge Sort', color='green')
plt.title('Comparação de Desempenho: Insertion Sort vs Merge Sort')
plt.xlabel('Número de Elementos')
plt.ylabel('Tempo de Execução (Escala Logarítmica)')
plt.yscale('log')
plt.grid(True, which="both", ls="--")
plt.legend()
plt.show()
