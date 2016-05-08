from bottle import get, post, request, run, error
def check_login(username, password):
	if username =="sainyam":
		if password=="password":
			return True
		else:
			return False

@get('/login')
def login(): 
 		return  '''<form action="/login" method="post"> Username: <input name="username" type="text" /> <br>Password:  <input name="password" type="password" /> <input value="Login" type="submit" /> </form>'''
@post('/login')
def do_login(): 
		username = request.forms.get('username') 
		password = request.forms.get("password") 
		if check_login(username, password): 
			return "<p>Yourlogininformationwascorrect.</p>" 
		else: 
			return "<p>Loginfailed.</p>"
@error(404) 
def error404(error): 
	return "Nothinghere,sorry"

run(host='localhost',port=8080)