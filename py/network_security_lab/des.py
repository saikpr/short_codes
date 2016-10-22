from collections import deque
def get_key(pc1): 
    key = str(input('Enter key of length 8: '))
    binary_key64 = '' # Stores the binary of entered key
    for i in range(8):
        binary_key64+=('{0:08b}'.format(ord(key[i])))
    binary_key56=''
    for val in pc1:
        binary_key56+=binary_key64[val]
    return binary_key56
def cyclic_left_shift(subkey,shift):
    subk = [str(subkey[i]) for i in range(len(subkey))]
    subk = deque(subk)
    subk.rotate(-1*shift)
    return ''.join(val for val in subk)
def generate_subkeys(binary_key56,left_rotations,pc2): # Generate 16 subkeys
    c0 = binary_key56[:28]
    d0 = binary_key56[28:56]
    subkeys48 = [] 
    for shifts in left_rotations:
        c0 = cyclic_left_shift(c0,shifts)
        d0 = cyclic_left_shift(d0,shifts)
        subkey56 = str(c0+d0)
        subkey48 = ''
        for val in pc2: # Account for Permutation Choice 2
            subkey48+=subkey56[val]
        subkeys48.append(subkey48)
    return subkeys48 #return a list of 48 bit subkeys
   
def initial_permutation(message,ip):
    binary_message64=''
    for i in range(8):
        binary_message64+='{0:08b}'.format(ord(message[i]))
    
    permuted_message64=''
    for val in ip:
        permuted_message64+=binary_message64[val]
    return permuted_message64
def expansion32to48(right_half32, expansion_table): 
    right_half48=''
    for val in expansion_table:
        right_half48+=right_half32[val]
    
    return right_half48
    
def f_function(right_half48,subkey48,s_boxes,s_box_p):
    key = [int(subkey48[i]) for i in range(48)] 
    message = [int(right_half48[i]) for i in range(48)]
    xorred_output = [key[i] ^ message[i] for i in range(48)] 
    s_index = 0
    s_values = [] 
    for i in range(0,48,6):
        output = xorred_output[i:i+6]
        row = output[0]*2 + output[5] # Get row of s_box
        column = output[1]*8 + output[2]*4 + output[3]*2 + output[4] # Get column of s_box
        
        index = row*16+column
        s_box_value = s_boxes[s_index][index]
        s_values.append(s_box_value)
        s_index+=1
    right_half32 = ''
    for val in s_values:
        right_half32+='{0:04b}'.format(val)
    permuted_right_half32=''
    for val in s_box_p:
        permuted_right_half32+=right_half32[val]
    return permuted_right_half32
    
def string_xor(left_half32,permuted_right_half32):
    xorred_output=''.join(str(int(left_half32[i]) ^ int(permuted_right_half32[i])) for i in range(32))
    return xorred_output 

def encryption_rounds(permuted_message64,subkeys48,expansion_table,s_boxes,s_box_p,final_p):
    left_half32 = permuted_message64[0:32] 
    right_half32 = permuted_message64[32:64]
    for subkey48 in subkeys48:
        next_left_half32 = right_half32
        right_half48 = expansion32to48(right_half32,expansion_table)
        next_right_half32 = string_xor(left_half32,f_function(right_half48,subkey48,s_boxes,s_box_p))
        left_half32 = next_left_half32
        right_half32 = next_right_half32
    ct = right_half32+left_half32
    inverse_p_ct=''
    for val in final_p:
        inverse_p_ct+=ct[val]
    ct_list=[]
    for i in range(0,64,8):
        ct8 = inverse_p_ct[i:i+8]
        val = int(ct8[0])*128+int(ct8[1])*64+int(ct8[2])*32+int(ct8[3])*16+int(ct8[4])*8+int(ct8[5])*4+int(ct8[6])*2+int(ct8[7])*1
        ct_list.append(chr(val))
    return ''.join(str(val) for val in ct_list)

def decryption_rounds(ct64,subkeys48,expansion_table,s_boxes,s_box_p,final_p):
    subkeys48.reverse()
    pt = encryption_rounds(ct64,subkeys48,expansion_table,s_boxes,s_box_p,final_p)
    return pt
    
    
if __name__ == '__main__':
    
    # ######################    KEYS
    pc1 = [56, 48, 40, 32, 24, 16,  8,
		  0, 57, 49, 41, 33, 25, 17,
		  9,  1, 58, 50, 42, 34, 26,
		 18, 10,  2, 59, 51, 43, 35,
		 62, 54, 46, 38, 30, 22, 14,
		  6, 61, 53, 45, 37, 29, 21,
		 13,  5, 60, 52, 44, 36, 28,
		 20, 12,  4, 27, 19, 11,  3] # Permutation choice 1 of main key, generating 56 bit key from 64 bit key
    left_rotations = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1] # left rotations for generating 16 subkeys
     
    pc2 = [
		13, 16, 10, 23,  0,  4,
		 2, 27, 14,  5, 20,  9,
		22, 18, 11,  3, 25,  7,
		15,  6, 26, 19, 12,  1,
		40, 51, 30, 36, 46, 54,
		29, 39, 50, 44, 32, 47,
		43, 48, 38, 55, 33, 52,
		45, 41, 49, 35, 28, 31] # Permutation choice 2 for subkeys, 56 bit shubkey to 48 bit subkey
    # ######################    KEYS
    
    
    
    # ########################## MESSAGE 
    
    ip = [57, 49, 41, 33, 25, 17, 9,  1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7,
		56, 48, 40, 32, 24, 16, 8,  0,
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6] # Initial Permutation for message
  
    expansion_table = [
		31,  0,  1,  2,  3,  4,
		 3,  4,  5,  6,  7,  8,
		 7,  8,  9, 10, 11, 12,
		11, 12, 13, 14, 15, 16,
		15, 16, 17, 18, 19, 20,
		19, 20, 21, 22, 23, 24,
		23, 24, 25, 26, 27, 28,
		27, 28, 29, 30, 31,  0] # for expanding 32 bit half message to 48 bit message length
  
    s_boxes = [ # The s_boxes are designed to convert 48 bit xorred value to 32 bit value
		# S1
		[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
		 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
		 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
		 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],

		# S2
		[15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
		 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
		 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
		 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9],

		# S3
		[10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
		 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
		 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
		 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12],

		# S4
		[7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
		 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
		 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
		 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14],

		# S5
		[2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
		 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
		 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
		 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3],

		# S6
		[12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
		 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
		 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
		 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13],

		# S7
		[4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
		 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
		 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
		 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12],

		# S8
		[13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
		 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
		 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
		 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]
	]
 
    s_box_p = [
		15, 6, 19, 20, 28, 11,
		27, 16, 0, 14, 22, 25,
		4, 17, 30, 9, 1, 7,
		23,13, 31, 26, 2, 8,
		18, 12, 29, 5, 21, 10,
		3, 24
	] # Permutation used on the s_box output
 
    final_p = [
		39,  7, 47, 15, 55, 23, 63, 31,
		38,  6, 46, 14, 54, 22, 62, 30,
		37,  5, 45, 13, 53, 21, 61, 29,
		36,  4, 44, 12, 52, 20, 60, 28,
		35,  3, 43, 11, 51, 19, 59, 27,
		34,  2, 42, 10, 50, 18, 58, 26,
		33,  1, 41,  9, 49, 17, 57, 25,
		32,  0, 40,  8, 48, 16, 56, 24
	] # Does the inverse permutation on final output of encryption (right_half32+left_half32)
    
    
    ####################### GENERATING KEYS ###########################
    binary_key56 = get_key(pc1) # Accept the 64 bit key from user and apply permutation choice 1 to generate 56 bit key 
    subkeys48 = generate_subkeys(binary_key56, left_rotations,pc2) # Generate 16 48 bit subkeys from 56 bit binary key by applying permutation choice 2
    
    
    ###################### ENCRYPTION ROUTINE ###########################
    
    message = str(input('Enter message of length 8: ')) # Get the message from user
    # msg_len = len(message)
    # if msg_len % 8 != 0:
    # 	rem = msg_len % 8
    # 	for i in range(8 - rem)
    	
    permuted_message64 = initial_permutation(message,ip) # Permute the message by applying initial permutation
    
    ct = encryption_rounds(permuted_message64,subkeys48,expansion_table,s_boxes,s_box_p,final_p)
    print ('Cipher Text-: ',ct)
    
    ############################# DECRYPTION ROUTINE #########################    
    
    permuted_ct64 = initial_permutation(ct,ip)
    dect_pt = decryption_rounds(permuted_ct64,subkeys48,expansion_table,s_boxes,s_box_p,final_p)
    print ('Decrypted Plain Text-: ',dect_pt)
