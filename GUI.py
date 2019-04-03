import numpy as np
import time
import matplotlib.pyplot as plt
from matplotlib.widgets import Button
from tkinter import *
import subprocess
fig = plt.figure()
ax = fig.add_subplot(111)
plt.grid(True)
plt.ylim(1,10) 
plt.xlim(1,10)

ax.xaxis.set_ticks(np.arange(1, 10, 0.5))						#Setting parameters of the Grpah
ax.yaxis.set_ticks(np.arange(1,10,0.5)) 
ax.set_title('Convex Hull input')					
ax.set_xlabel('x')
ax.set_ylabel('y')

fx = open("Input.txt","w")										#fx as a reader of input file
def onclick(event):												#Action listener to record coordinates of mouse click
    
    x, y = event.xdata, event.ydata
    fx = open("Input.txt","a")
    fx.write(str(round(x,6))+" "+str(round(y,6))+"\n")			#Saving the coordinates into file
    print("x is:",round(x,6))
    print("y is:",round(y,6))
    plt.plot(x,y,'*')											#plotting the clicked point on graph
    plt.show()
    plt.close()
for i in range(0,1):

    plt.connect('button_press_event', onclick)		
plt.show()
																#Arranging the position of popup window to center of screen
master = Tk()
master.withdraw()
master.update_idletasks()  

x = (master.winfo_screenwidth() - master.winfo_reqwidth()) / 2
y = (master.winfo_screenheight() - master.winfo_reqheight()) / 2
master.geometry("+%d+%d" % (x, y))


																# After setting correct window position
master.deiconify()
#Action listener for buttons
def handler1():
    subprocess.call("./KPS.sh", shell=True)
    print('Run Output.py to visualise ouput')
    exit()

def handler2():
    subprocess.call("./Graham.sh", shell=True)
    print('Run Output.py to visualise ouput')
    exit()
    
  
def handler3():
    subprocess.call("./Jarvis.sh", shell=True)
    print('Run Output.py to visualise ouput')
    exit()

master.title("Choose the algorithm")
																#Creating buttons
button1= Button(master,text="KPS",width=10,command=handler1)
button1.grid(row=0,column=1)
button2= Button(master,text="Graham",width=10,command=handler2)
button2.grid(row=0,column=2)
button3= Button(master,text="Jarvis March",width=10,command=handler3)
button3.grid(row=0,column=3)
																#To keep displaying the buttons
mainloop()
