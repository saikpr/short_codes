
text=raw_input("Enter the Text")
text=text.lower()

print "Your String :"+text
key=int(raw_input("Enter the key"))
new_text=''
assert(key>=0 and key<=25)

for i in xrange(len(text)):
	# print i
	if text[i]>="a" and text[i]<="z":
		new_text+=chr((ord(text[i])-97+key)%26+97)
	else:
		new_text+=text[i]

print "CIPHER TEXT :"+new_text

# print "Decrpyting"
plain_text=''
for i in xrange(len(new_text)):
	# print i
	if new_text[i]>="a" and new_text[i]<="z":
		plain_text+=chr((ord(new_text[i])-97-key+26)%26+97)
	else:
		plain_text+=new_text[i]



print "Clear Text is :" + plain_text