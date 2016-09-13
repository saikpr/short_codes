'''input
ThereAfterThemath AfterThem There math The he
'''
from pprint import pprint


def make_trie(str_list):
    root_trie = dict()
    root_trie["type"]="root"
    for each_str in str_list:
        list_el = list(each_str)
        ref_dict= root_trie
        for each_char in list_el[:-1]:
            try:
                ref_dict = ref_dict[each_char]
            except KeyError:
                ref_dict[each_char] = dict()
                ref_dict = ref_dict[each_char]

        try:
            ref_dict[list_el[-1]]['type'] = "leaf"
        except KeyError:
            ref_dict[list_el[-1]] = dict({'type':"leaf"})
    return root_trie

def check_substring(this_str,root_trie):
    list_el = list(this_str)
    for each_char in list_el:
        try:
            root_trie = root_trie[each_char]
        except KeyError:
            return False
    return True

def check_string(this_str,root_trie):
    list_el = list(this_str)
    for each_char in list_el:
        try:
            root_trie = root_trie[each_char]
        except KeyError:
            return False
    if "type" in root_trie:
        return True
    else:
        return False
def check_existing(check_val,root_trie):
    this_el = list(check_val)
    temp_trie = root_trie
    for ind_i in xrange(len(this_el)):
        this_char = this_el[ind_i]
        if this_char in  temp_trie:
            if "type" in temp_trie[this_char]:
                isPossible = check_existing(check_val[ind_i+1:],root_trie)
                if isPossible == True:
                    return True
            temp_trie = temp_trie[this_char]
        else:
            return False
    if "type" in temp_trie:
        return True
    else:
        return False
    





if __name__ == "__main__":
    input_str = raw_input().replace("\r","").split(" ")
    root_trie = make_trie(input_str)
    # pprint (root_trie)
    # print check_string("heya",root_trie)
    max_len = 0
    print max(len(s) for s in input_str if check_existing(s,root_trie))
    # for each_str in  input_str:
    #     max_len = max(max_len, len(each_str))
    #     print check_existing(each_str,root_trie)
    # print max_len