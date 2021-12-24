import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

file_path = "Path to CSV file"
with open(file_path) as file_name:
    array = np.loadtxt(file_name, delimiter=",")

x, y = array[:, 0], array[:, 1]

runtime = x[-2] - x[1]
mass_lost = y[0] - y[-1]

def f(x):
    return (max(y) - y[0])
res, err = quad(f, 0, y[-1])

print("Newton seconds: {:f} (+-{:g})"
    .format(res, err))
print("Runtime:",runtime)
print("Mass lost during burn:",mass_lost)
print(np.std(y[1:-2], dtype=np.float64), "% deviation")


plt.title("Thrust over time")
plt.xlabel("Seconds")
plt.ylabel("Newtons")
plt.plot(x, y, color ="red")
plt.show()
