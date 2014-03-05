import os
replace = ['Watch','Online for Free - Viooz','- YouTube','.HDTV.XviD-2HD'  ,'.HDTV.XviD-SYS','.HDTV.XviD-XII' ,'.HDTV.XviD-aAF','.x264-BoB'
,'Dvdrip-Topaz' ,' Free and reliable flash video hosting',' NovaMov' ,' online - -','YouTube',' HDTV XviD LOL',
'HDTV','x264', 'ASAP','LOL','Online']

for filename in os.listdir("."):
    filename1=filename
    for content in replace:
        filename1 = filename1.replace(content,"")

    os.rename(filename, filename1)
