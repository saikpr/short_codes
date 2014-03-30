from time import time
i=0
domain_dict={}
with open('DomainMapping.csv','rb') as  fil:
	for cont in fil:
		if(i>0):
			a1,a2=cont.split(',')
			domain_dict[int(a1)]=a2[0:-2]
		i=i+1
data_done=0
contlist=[]
dplist=[]
tk=time()
lasttime=tk
filenumber=0
fil=open('contestdata_0_json_'+str(filenumber)+'.txt','w')
fil.write('[')
def json_creator(contlist,data_done): #can be optimised later by copying it instead of calling it every time
	stri= {}
	i=0
	while i<len(contlist):
		if contlist[i]!='' and contlist[i] != '0' and contlist[i] != '0\r\n' and i!=5 and i!=6:
			stri['id_'+str(i)]=contlist[i]
		elif i==5 and contlist[5]!='':
			dplist=contlist[5].split('|')
			for dp in dplist:
				dp1,dp2=dp.split(';')
				try:
					k=domain_dict[int(dp1)]
					stri[k]=str(dp2)
				except KeyError:
					stri[dp1]=str(dp2)

				
		elif i==6 and contlist[6]!='':
			dplist=contlist[6].split('|')
			for dp in dplist:
				dp1,dp2=dp.split(';')
				stri[dp1.encode('utf-8')]=str(dp2)
		i=i+1
	return stri
with open('contestdata_0.txt','rb') as f:
	for cont in f:
		if cont !='':
			contlist=cont.split('\t')
			if len(contlist)==9:
				stri=json_creator(contlist,data_done)
				if data_done==0:
					fil.write(str(stri)+'\n')
				elif cont != '':
					fil.write(','+str(stri)+'\n')
				data_done+=1
				if data_done%100000==0:
					fil.close()
					filenumber+=1
					fil=open('contestdata_0_json_'+str(filenumber)+'.txt','w')
					print "time taken to update :" +str(data_done)+" in "+str(time()-lasttime)
					lasttime=time()
fil.write(']')
tk=time()-tk
print "total time taken to update "+str(data_done)+' in '+str(tk)