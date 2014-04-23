import json
import bottle
from bottle import route, run, request, abort
import pymongo
 
connection_string="mongodb://127.0.0.1"
connection=pymongo.MongoClient(connection_string)
db = connection.names
@route('/new', method='POST')
def put_doc():
    data = request.body.readline()
    print data
    print type(data)
    if not data:
        abort(400, 'No data received')
    entity = json.loads(data)
    if not entity.has_key('_id'):
        abort(400, 'No _id specified')
    try:
        db['documents'].save(entity)
    except ValidationError as ve:
        abort(400, str(ve)) 
@route('/rm/:id1', method='GET')
def rm_doc(id1):
    k=db['documents'].remove({'_id':id1})
    return "Deleted"
@route('/documents/:id', method='GET')
def get_document(id):
    k="'"+id+"'"
    entity = db['documents'].find_one({'_id':id})
    if not entity:
        abort(404, 'No document with id %s' % id)
    return entity
 
run(host='localhost',port=8018)