import bottle
import os
import datetime

global i
i=1
@bottle.route('/new/<youtubeurl>', method='GET')
def add_down(youtubeurl):
	global i
	newyoutubeurl=youtubeurl.replace('**','?')
	newyoutubeurl=newyoutubeurl.replace('*','/')
	
	run_youtube_down="youtube-dl -cit " +newyoutubeurl
	l=youtubeurl.rfind('*')
	if 'user' in newyoutubeurl:
		k=youtubeurl[:l-1].rfind('*')
	else:
		k=l
		l=len(youtubeurl)
	direct='api_'+str(datetime.date.today())+"_"+str(i)
	i=i+1
	mkdir="cd /var/www/test/api && mkdir "+direct +" && "+ "cd " +direct +" && screen -d -m "+run_youtube_down
	os.system(mkdir)
	return direct
@bottle.route('/snew/<youtubeurl>', method='GET')
def add_down(youtubeurl):
	global i
	newyoutubeurl=youtubeurl.replace('**','?')
	newyoutubeurl=newyoutubeurl.replace('*','/')
	
	run_youtube_down="youtube-dl -cit " +newyoutubeurl
	l=youtubeurl.rfind('*')
	if 'user' in newyoutubeurl:
		k=youtubeurl[:l-1].rfind('*')
	else:
		k=l
		l=len(youtubeurl)
	direct='api_'+str(datetime.date.today())+"_"+str(i)
	i=i+1
	mkdir="cd /var/www/api && mkdir "+direct +" && "+ "cd " +direct +" && screen -d -m "+run_youtube_down
	os.system(mkdir)
	return "10.3.61.221/api/"+direct

@bottle.route('/dsnew/<youtubeurl>/<dirc>', method='GET')
def add_down(youtubeurl,dirc):
	global i
	newyoutubeurl=youtubeurl.replace('**','?')
	newyoutubeurl=newyoutubeurl.replace('*','/')
	
	run_youtube_down="youtube-dl http://" +newyoutubeurl
	l=youtubeurl.rfind('*')
	if 'user' in newyoutubeurl:
		k=youtubeurl[:l-1].rfind('*')
	else:
		k=l
		l=len(youtubeurl)
	direct=dirc
	i=i+1
	mkdir="cd /var/www/api && mkdir "+direct +" && "+ "cd " +direct +" && screen -d -m "+run_youtube_down
	os.system(mkdir)
	return "10.3.61.221/api/"+direct
@bottle.route('/renew/<youtubeurl>/<dirc>', method='GET')
def add_down(youtubeurl,dirc):
	global i
	newyoutubeurl=youtubeurl.replace('**','?')
	newyoutubeurl=newyoutubeurl.replace('*','/')
	
	run_youtube_down="youtube-dl http://" +newyoutubeurl
	l=youtubeurl.rfind('*')
	if 'user' in newyoutubeurl:
		k=youtubeurl[:l-1].rfind('*')
	else:
		k=l
		l=len(youtubeurl)
	direct=dirc
	i=i+1
	mkdir="cd /var/www/api/"+direct +" && screen -d -m "+run_youtube_down
	os.system(mkdir)
	return "10.3.61.221/api/"+direct
@bottle.route('/del/<id1>', method='GET')
def del_down(id1):
	
	os.system("rm -r /var/www/test/api/"+id1)

@bottle.route('/sdel/<id1>', method='GET')
def del_down(id1):
	
	os.system("rm -r /var/www/api/"+id1)
bottle.run(host='10.3.61.221',port=8080)
