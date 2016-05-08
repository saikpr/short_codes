import os
i=0
for filename in os.listdir("."):
    if filename.endswith("Online for Free - Viooz",0,-4):
    	print filename
        os.rename(filename, filename[0:-27]+filename[-4:])
for filename in os.listdir("."):
    if filename.startswith("Watch"):
    	print filename
        os.rename(filename, filename[6:])