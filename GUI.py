import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Button
from tkinter import *
import subprocess
fig = plt.figure()
ax = fig.add_subplot(111)
plt.grid(True)
plt.ylim(1,10) 
plt.xlim(1,10)

ax.xaxis.set_ticks(np.arange(1, 10, 0.5))
ax.yaxis.set_ticks(np.arange(1,10,0.5)) 
ax.set_title('Convex Hull input')
ax.set_xlabel('x')
ax.set_ylabel('y')

fx = open("Input.txt","w")
def onclick(event):
    
    x, y = event.xdata, event.ydata
    fx = open("Input.txt","a")
    fx.write(str(x)+" "+str(y)+"\n")
    print("x is:",x),
    print("y is:",y)
    plt.plot(x,y,'*')
    plt.show()
    plt.close()
for i in range(0,1):

    plt.connect('button_press_event', onclick)
plt.show()
master = Tk()
def closewindow():
    exit()
master.title("Choose the algorithm")
button1= Button(master,text="KPS",width=10,command=closewindow)
button1.grid(row=0,column=1)
button2= Button(master,text="Graham",width=10,command=closewindow)
button2.grid(row=0,column=2)
button3= Button(master,text="Jarvis March",width=10,command=closewindow)
button3.grid(row=0,column=3)
mainloop()
subprocess.call("./Compile.sh", shell=True)
