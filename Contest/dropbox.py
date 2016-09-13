'''input
redbluebluered
abba
'''
match_dict= dict()
def check_substr(str_g,pattern):
	# print "check ",str_g,pattern
	if pattern in str_g:
		return str_g.count(pattern)
	return False

def matcher(string,pattern):
	# print string,pattern
	# print "asd"
	if string == "" and pattern =="":
		return True
	if len(pattern)==1 :
		return True
	if len(pattern)==0:
		return False
	pattern_count = list(pattern)
	pattern_dict = dict()
	for each_char in pattern_count:
		if each_char in pattern_dict:
			pattern_dict[each_char] +=1
		else:
			pattern_dict[each_char] =1
	pattern_count = [(pattern_dict[a],a) for a in pattern_dict]

	# pattern_count = sorted (pattern_count,reverse=True)
	# print pattern_count
	# first_char  =pattern_count[0]
	# del pattern_count[0]
	first_char = (pattern_dict[pattern[0]],pattern[0])
	# print first_char,pattern
	if len(pattern_dict)==1:
		index_start = len(string)-2
		index_end=len(string)
		while(check_substr(string,string[index_start:index_end])>=first_char[0]):
			index_start-=1
		index_start+=1
		match_dict[first_char[1]] = string[index_start:index_end]
		if string[index_start:index_end] == "":
			return False
		# print "match",match_dict
		# new_string = pattern.replace(first_char[1],string[index_start:index_end])
		pattern = pattern.replace(first_char[1],"")
		string = string.replace(string[index_start:index_end],"")
		if string =="" and pattern== "":
			return True
		else:
			return False
	if pattern_dict[pattern[0]]==1:
		return matcher(string[1:], pattern[1:])
	else :
		index_start = 0
		index_end=1
		while(check_substr(string,string[index_start:index_end])>=first_char[0]):
			index_end+=1
		index_end-=1
		# print check_substr(string,string[index_start:index_end]), first_char
		
		match_dict[first_char[1]] = string[index_start:index_end]
		if string[index_start:index_end] == "":
			return False
		# print "match",match_dict
		# new_string = pattern.replace(first_char[1],string[index_start:index_end])
		pattern = pattern.replace(first_char[1],"")
		string = string.replace(string[index_start:index_end],"")
		return matcher(string,pattern)

if __name__ == "__main__":
	string = raw_input()
	pattern = raw_input()
	string = string.replace('\r',"")
	pattern = pattern.replace("\r","")
	# index_start = 0
	# index_end=1
	# while check_substr(string,string[index_start:index_end]) >= 2:
	# 	# print check_substr(string,string[index_start:index_end])
	# 	index_end+=1
	# index_end-=1
	# print string[index_start:index_end]
	print matcher(string,pattern)