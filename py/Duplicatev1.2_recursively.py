import os
import hashlib
hashdir = []
def get_hash(name):
    readsize = 64*1024
    try:
        with open(name, 'r') as f:
            if os.path.getsize(name) >readsize:
                data=f.read(readsize)
                f.seek(-readsize, os.SEEK_END)
                data += f.read(readsize)
                return hashlib.md5(data).hexdigest()
            else:
                return hashlib.md5(f.read()).hexdigest()
    except IOError as errcode:
        print str(errcode)
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
input_last=raw_input("Done!")