import numpy as np
from scipy.optimize import curve_fit

# Определяем функцию аппроксимации
def func(x, A, B, C):
    return A + B / (x - C)

# Загрузка данные из файла data.txt
data = np.loadtxt('data.txt')
x_data = data[:, 0]  # Предполагаем, что первая колонка в файле содержит данные x
y_data = data[:, 1]  # Предполагаем, что вторая колонка в файле содержит данные y

# Используем curve_fit для аппроксимации данных
params, covariance = curve_fit(func, x_data, y_data)

# params содержит найденные значения A, B и C
A, B, C = params

# Оценка ошибок параметров A, B и C
errors = np.sqrt(np.diag(covariance))

A_error, B_error, C_error = errors

print(f"A = {A} ± {A_error}")
print(f"B = {B} ± {B_error}")
print(f"C = {C} ± {C_error}")
