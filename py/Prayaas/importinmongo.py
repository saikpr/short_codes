from time import time
import os
filenumber=0
collection =0
tk=time()
trigger=False
while trigger==False:
	try:
		filename='contestdata_0_json_'+str(filenumber)+'.txt'
		fil=open('contestdata_0_json_'+str(filenumber)+'.txt','r')
		if filenumber%400==0:
			collection+=1
		fil.close()
		filenumber+=1
		print "mongoimport --db data_0 --collection random_"+str(collection)+" "+filename+" --jsonArray"
		os.system("mongoimport --db data_0 --collection random_"+str(collection)+" "+filename+" --jsonArray")
	except IOError:
		trigger=True

tk=time()-tk
print "time to import data "+str(filenumber)+' in '+str(tk)

filem=open("time.txt",'a')
filem.write("time to import data "+str(filenumber)+' in '+str(tk))