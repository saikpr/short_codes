import os
for dirname, dirnames, filenames in os.walk('.'):
    #for subdirname in dirnames:
        
    for filename in filenames:
        print "FOUND FILE: ", os.path.join(dirname, filename)