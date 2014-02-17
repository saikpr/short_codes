import os
import hashlib
hashdir = []
def get_hash(name):
        readsize =  1024
        with open(name, 'rb') as f:
            data = f.read(readsize)
            
        return hashlib.md5(data).hexdigest()


for filename in os.listdir("."):
    hashed=get_hash(filename)
    if hashed in hashdir:
        os.remove(filename)
    else :
        hashdir.append(hashed)

