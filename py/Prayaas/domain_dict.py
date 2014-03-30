i=0
domain_dict={}
with open('DomainMapping.csv','rb') as  fil:
	for cont in fil:
		if(i>0):
			a1,a2=cont.split(',')
			domain_dict[int(a1)]=a2[0:-2]
		i=i+1
print domain_dict[1]