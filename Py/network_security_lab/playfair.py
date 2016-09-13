from string import ascii_uppercase
from itertools import product
from re import findall
 
def uniq(seq):
    seen = {}
    return [seen.setdefault(x, x) for x in seq if x not in seen]
 
def partition(seq, n):
    return [seq[i : i + n] for i in xrange(0, len(seq), n)]

def playfair(key, from_ = 'J', to = None):
    if to is None:
        to = 'I' if from_ == 'J' else ''

    def canonicalize(s):
        return filter(str.isupper, s.upper()).replace(from_, to)
    m = partition(uniq(canonicalize(key + ascii_uppercase)), 5)
    print m
    enc = {}
    for row in m:
        for i, j in product(xrange(5), repeat=2):
            if i != j:
                enc[row[i] + row[j]] = row[(i + 1) % 5] + row[(j + 1) % 5]
    for c in zip(*m):
        for i, j in product(xrange(5), repeat=2):
            if i != j:
                enc[c[i] + c[j]] = c[(i + 1) % 5] + c[(j + 1) % 5]
    for i1, j1, i2, j2 in product(xrange(5), repeat=4):
        if i1 != i2 and j1 != j2:
            enc[m[i1][j1] + m[i2][j2]] = m[i1][j2] + m[i2][j1]
    dec = dict((v, k) for k, v in enc.iteritems())
 
    def sub_enc(txt):
        lst = findall(r"(.)(?:(?!\1)(.))?", canonicalize(txt))
        return " ".join(enc[a + (b if b else 'X')] for a, b in lst)
    def sub_dec(encoded):
        return " ".join(dec[p] for p in partition(canonicalize(encoded), 2))
 
    return sub_enc, sub_dec
 
 
(encode, decode) = playfair("yes")
orig = """Hello world"""
print "\n\n\nOriginal:", orig
enc = encode(orig)
print "\n\n\nEncoded:", enc
print "\n\n\nDecoded:", decode(enc)