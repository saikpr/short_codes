import urllib2
url='10.1.1.19:80'
username='068.1525'
password='passcode'
proxy_str='http://'+username+':'+password+'@'+url
print proxy_str
proxy = urllib2.ProxyHandler({'http': proxy_str})
auth = urllib2.HTTPBasicAuthHandler()
opener = urllib2.build_opener(proxy, auth, urllib2.HTTPHandler)
urllib2.install_opener(opener)
req = urllib2.Request('http://google.com')
response = opener.open(req)
datum = response.read()
response.close()
with open ("test.html","wb") as save:
	save.write(datum)
