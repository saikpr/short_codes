
s=dict()
def intialise(key):
	global s
	for i in xrange(256):
		s[i]=i
	j=0
	for i in xrange(256):
		j= j + s[i]+ord(key[i%len(key)])
		j=j%256
		s[i],s[j]=s[j],s[i]

def encryption(text):
	i,j=0,0
	global s
	for i in xrange(len(text)):
		j = (j + s[i])%256
		s[i],s[j]=s[j],s[i]
		z = s[(s[i] + s[j])%256]
		print (chr(ord(text[i])^z),"")


if __name__ == "__main__":
	key=raw_input("Enter the key:")
	plaintext=raw_input("Enter the plaintext:")
	intialise(key)
	print "CipherText"
	encryption(plaintext)
	
