from itertools import starmap, cycle                                                           
 
def encrypt(message, key):                                                                     
    message = filter(lambda _: _.isalpha(), message.upper())                                   
    def enc(c,k): return chr(((ord(k) + ord(c)) % 26) + ord('A'))                              
    return "".join(starmap(enc, zip(message, cycle(key))))                                     
 
def decrypt(message, key):                                                                     
    def dec(c,k): return chr(((ord(c) - ord(k)) % 26) + ord('A'))                              
    return "".join(starmap(dec, zip(message, cycle(key))))
text = """Hello world"""             
key = "yes"                                                                         
encr = encrypt(text, key)                                                                      
decr = decrypt(encr, key)                                                                      

print text       
print "\n\n\nEncrpted value :"                                                                              
print encr
print "\n\n\nDecrypted value"                                                                                     
print decr
 