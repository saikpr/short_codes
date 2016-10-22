import utils

def encrypt(message, matrix, encryption=True):
    """
    Hill encryption (decryption).
    """
    message = message.upper()
    if not utils.invertible(matrix):
        # The matrix should be invertible.
        return "Non invertible matrix"
    if len(message) % 2 != 0:
        message = message + 'X'
    couple = [list(message[i*2:(i*2)+2]) for i in range(0, len(message)/2)]
    result = [i[:] for i in couple]
    if not encryption:
        # To decrypt, just need to inverse the matrix.
        matrix = utils.inverse_matrix(matrix)
    for i, c in enumerate(couple):
        if c[0].isalpha() and c[1].isalpha():
            result[i][0] = chr(((ord(c[0])-65) * matrix[0][0] + \
                                    (ord(c[1])-65) * matrix[0][1]) % 26 + 65)
            result[i][1] = chr(((ord(c[0])-65) * matrix[1][0] + \
                                    (ord(c[1])-65) * matrix[1][1]) % 26 + 65)
    return "".join(["".join(i) for i in result])

def decrypt (cypher, matrix):
    """
    Hill decryption.
    """
    return encrypt(cypher, matrix, False)

if __name__ == '__main__':
    # Point of entry in execution mode
    print "Encrpted value :"
    print encrypt("""Hello world""", [[11, 3], [8, 7]])
    print "\n\n\nDecrypted value"
    print decrypt(encrypt("""Hello world""", [[11, 3], [8, 7]]), [[11, 3], [8, 7]])
