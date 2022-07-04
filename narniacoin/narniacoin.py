import datetime
import hashlib
import json
from urllib import urlparse
import requests

class Block:
    pass
class Blockchain:
    def __init__(self):
        self.chain = []
        self.transactions = []
        self.createNewBlock(proof=1, previous_hash='0')
        self.calculatePOW = lambda newProof, previousProof: hashlib.sha256(str(newProof**2 - previousProof**2).encode()).hexdigest()
        self.nodes = set()

    def createNewBlock(self, proof, previous_hash):
        block = {
            'index' : len(self.chain) + 1,
            'timestamp' : str(datetime.datetime.now()),
            'pow' : proof,
            'previous_hash' : previous_hash,
            'transactions': self.transactions
        }
        self.transactions = [] # the transaction has been added to the block
        self.chain.append(block)
        return block

    def getLastBlock(self):
        return self.chain[-1]

    def getProofOfWork(self, prevProof):
        proof = 0
        while True:
            proof += 1
            hashOperation = self.calculatePOW(proof, prevProof)
            if hashOperation[:4] == '0000':
                return proof

    def getHash(self, block):
        encodedBlock = json.dumps(block, sort_keys=True).encode()
        return hashlib.sha256(encodedBlock).hexdigest()

    def isChainValid(self):
        previous = self.chain[0]
        for node in self.chain[1:]:
            if node['previous_hash'] != self.getHash(previous):
                return False
            if self.calculatePOW(node['pow'], previous['pow'])[:4] != '0000':
                return False
            previous = node
        return True

    def addTransaction(self, sender, receiver, amount, fee):
        self.transactions.append({'sender':sender, 'receiver':receiver, 'amount':amount, 'fee':fee})
        lastBlock = self.getLastBlock()
        return lastBlock['index'] + 1 # the index of the next new block

    def addNode(self, address):
        parsed = urlparse(address)
        self.nodes.add(parsed.netloc)

    def updateChain(self):
        length = len(self.chain)
        for node in self.nodes:
            response = requests.get(f'http://{node}/getChain')
            if response.status_code != 200:
                print(f'Error while trying to retrieve the chain from {node}.')
            nodeLength = response.json()['length']
            nodeChain = response.json()['chain']
            if nodeLength > length:
                length = nodeLength
                self.chain = nodeChain #it's a quite naive implementation
        return False