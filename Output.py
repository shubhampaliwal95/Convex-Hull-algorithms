from matplotlib import pyplot as plt
import numpy as np 
print('Enter the method, 1->Graham, 2->Jarvis, 3->KPS')
method =int(input())
def display(method):										#Method for visualisation of data
	total = open('Preciseinput.txt')						#Getting points from input data
	if(method==1):
		res = open('Output_Graham.txt')						#Getting output file as per defined method
	elif(method==2):
		res = open('Output_Jarvis.txt')
	elif(method==3):
		res = open('Output_KPS.txt')
	points = []
	points1 = []
	for line in total:
		line=line.replace("\n","")
		points.append(line.split(" "))
		#print(line)
	for line in res:
		line=line.replace("\n","")
		points1.append(line.split(" "))
		#print(line)
	points1.append(points1[0])
	
	points=np.asarray(points)
	points1=np.asarray(points1)


	plt.title('Convex Hull Output')

	plt.plot(points[:,0],points[:,1],'.',color='r')
	if(method==3):
		plt.plot(points1[:,0],points1[:,1],'*',color='b')		#Displaying only points of HULL in case of KPS
		plt.show()
	elif(method==1 or method==2):
		for i in range(1,points1.shape[0]):						#Showing HULL as polygon in case of Jarvis and Graham scan
			print(points1[i-1,0])
			print(points1[i,0])
			plt.plot([points1[i-1,0],points1[i,0]],[points1[i-1,1],points1[i,1]],'-',color='b')
		plt.show()
display(method)												#Calling display function