import json,ast
import bottle
import pymongo
from time import time
from hashlib import sha1
import random, string
"""Some Basic Configuration"""
baseurl= "/and"
connection_string="mongodb://localhost"
connection=pymongo.MongoClient(connection_string)
db=connection.andr

@bottle.route(baseurl+'/auth/check/:userid/:password', method='GET')
def auth_new_key(userid,password):
    """Returns a New api Request Key after autheticating user_id and passhash
    """
    userid=str(userid)
    password=str(password)
    user_id=userid.encode('utf-8').lower()
    user_id_hash= sha1(user_id).hexdigest()
    password_hash=password.encode('utf-8').lower()
    user_entity=db['user'].find_one({'_id': user_id_hash})
    if user_entity is None:
        print "dsfdsfg  "+str(user_entity)+"   gfdgdfg"
        return json.dumps({'error':'User Not Found'},sort_keys=True)
    
    user_entity=eval(str(user_entity))
    password_hash=sha1(password_hash).hexdigest()
    userpass_hash=user_entity['passhash']
    user_id=str(user_id)
    user_id_hash=user_entity['_id']
    if userpass_hash !=password_hash:
        
        return json.dumps({'error':'Wrong Password'},sort_keys=True)
    
    return  "[{'userid':"+user_id_hash+"}]"


@bottle.route(baseurl+'/auth/new/:userid/:password', method='GET')
def create_new_user(userid,password):
    """Used to add new user to db
    """
    userid=str(userid)
    password=str(password)
    user_id=userid
    user_id_hash= sha1(user_id).hexdigest()
    user_entity=db['user'].find_one({'_id': user_id_hash})
    print user_entity
    if user_entity is not None:
        return json.dumps({'error':'User Exists'},sort_keys=True)
    password_hash=password    
    password_hash=sha1(password_hash).hexdigest()
    entitynew=dict()
    entitynew['_id']=user_id_hash
    entitynew['passhash']=password_hash
    db['user'].save(entitynew)
    print entitynew
    return  "[{'userid':"+user_id_hash+"}]"

@bottle.route(baseurl+'/quesdisp/:userid', method='GET')
def create_new_user(userid):
    """Used to display ques
    """
    userid=str(userid)
    user_id= sha1(userid).hexdigest()
    user_entity=db['ques'].find({'userid': user_id}).limit(8)
    i=0
    stpush="["
    for k in user_entity:
        stpush=stpush + str(ast.literal_eval(json.dumps(k)))+ " , "
        i+=1
    user_entity=db['ques'].find({'userid': {"$ne" :user_id}}).limit(8)
    for k in user_entity:
        if not i<8:
            break

        stpush=stpush + str(ast.literal_eval(json.dumps(k)))+ " , "
        i+=1

    stpush=stpush[:-1]+"]"

    print stpush
    return  stpush

@bottle.route(baseurl+'/quesnew/:userid', method='POST')
def put_doc(userid):
    userid=str(userid)
    user_id=userid
    data = bottle.request.body.readline().decode('utf-8')
    print data
    entity = json.loads(data)
    print entity
    entity['_id']=sha1(entity["ques"]).hexdigest()
    entity['userid']=user_id
    entity['upvote']=str(0)
    db['ques'].save(entity)
    return ""
@bottle.route(baseurl+'/ansnew/:userid/:quesid', method='POST')
def put_doc(userid,quesid):
    userid=str(userid)
    user_id=userid
    data = bottle.request.body.readline().decode('utf-8')
    print data
    entity = json.loads(data)
    print entity
    entity['_id']=sha1(entity['ans']).hexdigest()
    entity['userid']=user_id
    entity['upvote']=str(0)
    entity['quesid']=quesid
    db['ans'].save(entity)
    return ""

@bottle.route(baseurl+'/upvoteques/:quesid', method='GET')
def put_doc(quesid):
    quesid=str(quesid)
    user_entity=db['ques'].find_one({'_id': quesid})
    print entity
    upvote =int(user_entity['upvote'])+1
    user_entity['upvote']=str(upvote)
    db['ques'].save(user_entity)
    return ""
@bottle.route(baseurl+'/upvoteans/:userid/:ansid', method='GET')
def put_doc(userid,quesid):
    ansid=str(ansid)
    user_entity=db['ans'].find_one({'_id': ansid})
    print entity
    upvote =int(user_entity['upvote'])+1
    user_entity['upvote']=str(upvote)
    db['ans'].save(user_entity)
    return ""
@bottle.route(baseurl+'/getans/:quesid',method='GET')
def get_ans(quesid):
    user_entity=db['ans'].find({'quesid': quesid})
    stpush="["
    for k in user_entity:
        stpush=stpush + str(ast.literal_eval(json.dumps(k)))+ " , "
    stpush=stpush[:-2]+"]"
    print stpush
    try:
        return  stpush   
    except TypeError:
        return """[{'ans':'','upvote':''}]"""

bottle.run(host='android.skxdx.tk',port=80)