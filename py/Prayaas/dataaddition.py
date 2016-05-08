import pymongo
from time import time
connection_string="mongodb://localhost"
connection=pymongo.MongoClient(connection_string)
i=0
k=str("data_"+str(i))
db=connection[k]
data_done=0
contlist=[]
tk=time()
lasttime=tk
with open('contestdata_0.txt','rb') as f:
	for cont in f:
		if data_done%100000==0:
			print "time taken to update :" +str(data_done)+" in "+str(time()-lasttime)
			lasttime=time()

		if cont != '':
			i=0
			contlist=cont.split('\t')
			stri= {}
			while i<9:
				if contlist[i]!='' and contlist[i] != '0' and contlist[i] != '0\r\n' :
					stri['id_'+str(i)]=contlist[i]
				i=i+1
			db['data1'].save(stri)
			data_done+=1
tk=time()-tk
print tk