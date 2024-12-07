import matplotlib.pyplot as plt

# Dados fornecidos
n_values = [
    20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000,
    220000, 240000, 260000, 280000, 300000, 320000, 340000, 360000, 380000, 400000
]
insertion_sort_times = [
    318.333333, 1290.333333, 2747.000000, 6959.000000, 16181.000000, 16785.333333,
    23049.000000, 27362.333333, 38207.666667, 41870.333333, 48366.000000, 62104.000000,
    66612.000000, 74525.333333, 84455.333333, 92904.000000, 106148.333333, 119408.000000,
    134277.666667, 149741.666667
]
merge_sort_times = [
    0.000000, 5.000000, 16.000000, 28.333333, 87.333333, 44.000000, 35.666667, 34.666667,
    42.666667, 84.666667, 58.666667, 85.333333, 64.000000, 73.333333, 76.000000, 90.333333,
    120.333333, 84.333333, 121.000000, 96.666667
]
quick_sort_times = [
    0.000000, 5.333333, 0.000000, 15.333333, 63.666667, 17.666667, 19.333333, 38.000000,
    35.333333, 52.666667, 38.333333, 59.000000, 44.333333, 50.666667, 50.666667, 67.000000,
    86.333333, 67.000000, 96.000000, 62.000000
]

# Converte tempos de ms para segundos
insertion_sort_times = [t / 1000 for t in insertion_sort_times]
merge_sort_times = [t / 1000 for t in merge_sort_times]
quick_sort_times = [t / 1000 for t in quick_sort_times]

# Gráfico comparativo dos três algoritmos
plt.figure(figsize=(10, 6))
plt.plot(n_values, insertion_sort_times, label='Insertion Sort')
plt.plot(n_values, merge_sort_times, label='Merge Sort')
plt.plot(n_values, quick_sort_times, label='Quick Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Comparação de Tempo de Execução dos Algoritmos de Ordenação')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico comparativo entre Insertion Sort e Merge Sort
plt.figure(figsize=(10, 6))
plt.plot(n_values, insertion_sort_times, label='Insertion Sort')
plt.plot(n_values, merge_sort_times, label='Merge Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Comparação entre Insertion Sort e Merge Sort')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico comparativo entre Insertion Sort e Quick Sort
plt.figure(figsize=(10, 6))
plt.plot(n_values, insertion_sort_times, label='Insertion Sort')
plt.plot(n_values, quick_sort_times, label='Quick Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Comparação entre Insertion Sort e Quick Sort')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico comparativo entre Merge Sort e Quick Sort
plt.figure(figsize=(10, 6))
plt.plot(n_values, merge_sort_times, label='Merge Sort')
plt.plot(n_values, quick_sort_times, label='Quick Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Comparação entre Merge Sort e Quick Sort')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico individual do Insertion Sort
plt.figure(figsize=(10, 6))
plt.plot(n_values, insertion_sort_times, label='Insertion Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Tempo de Execução do Insertion Sort')
plt.grid(True)
plt.show()

# Gráfico individual do Merge Sort
plt.figure(figsize=(10, 6))
plt.plot(n_values, merge_sort_times, label='Merge Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Tempo de Execução do Merge Sort')
plt.grid(True)
plt.show()

# Gráfico individual do Quick Sort
plt.figure(figsize=(10, 6))
plt.plot(n_values, quick_sort_times, label='Quick Sort')
plt.xlabel('n')
plt.ylabel('Tempo (s)')
plt.title('Tempo de Execução do Quick Sort')
plt.grid(True)
plt.show()
