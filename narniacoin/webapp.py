from flask import Flask, jsonify, request
from narniacoin import *
from uuid import uuid4

webapp = Flask(__name__)
blockchain = Blockchain()

@webapp.route('/addNewBlock', methods=['GET'])
def addNewBlock():
    lastBlock = blockchain.getLastBlock()
    proof = blockchain.getProofOfWork(lastBlock['pow'])
    previous_hash = blockchain.getHash(lastBlock)
    block = blockchain.createNewBlock(proof, previous_hash)
    response = {
        'message':'There is a new block in the chain',
        'index' : block['index'],
        'timestamp' : block['timestamp'],
        'pow' : block['pow'],
        'previous_hash' : block['previous_hash'],
	'transactions' : block['transactions']
    }
    return jsonify(response), 200

@webapp.route('/getChain', methods=['GET'])
def getChain():
    response = {
        'chain':blockchain.chain,
        'length':len(blockchain.chain)
    }
    return jsonify(response), 200

@webapp.route('/validateChain', methods=['GET'])
def validateChain():
    response = {
        'isValid':blockchain.isChainValid()
    }
    return jsonify(response), 200
    
webapp.run(host = '0.0.0.0', port = 5001)