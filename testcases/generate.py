import re
import random
import nltk
import json
from nltk.corpus import words
nltk.download('words')

name = input('filename: ')
wordnum = int(input('how many words: '))
lines = int(input('lines: '))
chunksize = int(input('chunk size: '))
nodes = int(input('nodes: '))
cpus = int(input('cpus: '))

# generate words, random pick 2000 words
allWords = words.words()
results = list()
for i in range(wordnum):
    results.append(allWords[random.randint(0, len(allWords)-1)].lower())

# generate .word
f = open(name+'.word', 'w')
for line in range(lines):
    randomInt = random.randint(100, 150)
    words = list()
    for i in range(randomInt):
        words.append(results[random.randint(0, len(results)-1)])
    words = (' ').join(words)
    f.write(words)
    f.write('\n')

f.close()

# generate .loc
f = open(name+'.loc', 'w')
datas = int(lines / chunksize)
for i in range(1, datas+1):
    f.write(f'{i} {random.randint(1, 8)}\n')

f.close()

#generate .json
f = open(name+'.json', 'w')
result = {
    "NODES": nodes,
    "CPUS": cpus,
    "JOB_NAME": f'TEST{name}',
    "NUM_REDUCER": random.randint(7, 12),
    "DELAY": random.randint(1, 5),
    "INPUT_FILE_NAME": f'{name}.word',
    "CHUNK_SIZE": chunksize,
    "LOCALITY_CONFIG_FILENAME": f'{name}.loc'
}
jsonDump = json.dumps(result, indent=4)
f.write(jsonDump)

f.close()
