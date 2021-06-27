from subprocess import call
import matplotlib.pyplot as plt

with open('duomgraph.txt', 'r') as file:
    data = file.readlines()
    
words = data[5].split()
words.append("\n")
num = int(words[0])

x_values = []
y_values = []

for temp in range(num):
    words[0] = str(temp+1)
    line = " ".join(words)
    data[5] = line
    with open('duomgraph.txt', 'w') as file:
        file.writelines( data )
    call(["./polikgraph", "args", "to", "polik"])
    with open('rezgraph.txt', 'r') as file:
        xy = file.readlines()
    x_values.append(int(xy[0]))
    y_values.append(int(xy[1]))
    
plt.plot(x_values, y_values, linewidth=1)
plt.title("Poliklinika", fontsize=19)
plt.xlabel("Aplinkiniu spec. skaic.", fontsize=10)
plt.ylabel("Mokestis", fontsize=10)
plt.tick_params(axis='both', labelsize=9)
plt.show()
