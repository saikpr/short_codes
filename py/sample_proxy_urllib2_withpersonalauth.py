import urllib2
url='10.1.1.19:80'
username='068.1525'
password='passcode'
password_mgr = urllib2.HTTPPasswordMgrWithDefaultRealm()
# None, with the "WithDefaultRealm" password manager means
# that the user/pass will be used for any realm (where
# there isn't a more specific match).
password_mgr.add_password(None, url, username, password)
auth = urllib2.HTTPBasicAuthHandler(password_mgr)
opener = urllib2.build_opener(auth)
urllib2.install_opener(opener)
response = urllib2.urlopen('http://www.google.com')
datum = response.read()
response.close()
with open ("test1.html","wb") as save:
	save.write(datum)
