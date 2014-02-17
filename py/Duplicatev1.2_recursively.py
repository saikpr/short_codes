import os

import hashlib
hashdir = []
def get_hash(name):
    readsize = 64*1024
    try:
        with open(name, 'r') as f:
            
            data = f.read(readsize)
            f.seek(-readsize, os.SEEK_END)
            data += f.read(readsize)
            return hashlib.md5(data).hexdigest()
    except IOError:
        print "Error at" + name
        return '-1'


for dirname, dirnames, filenames in os.walk('.'):
    for filename in filenames:
        address=os.path.join(dirname, filename)
        
        hashed=get_hash(address)
        if hashed == '-1':
            continue
        if hashed in hashdir:
            os.remove(address)
            print address
        else :
            hashdir.append(hashed)

