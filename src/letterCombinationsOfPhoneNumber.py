import itertools



if __name__ == "__main__":
    digits = raw_input()
    kvmaps = {"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"
            }
    #for x in itertools.product(kvmaps[digits[i]] for i in range(len(digits))):
    #for x in itertools.product("abc","def"):
    #    print x
    pools = [kvmaps[digits[i]] for i in range(len(digits))]
    #pools = ["abc","def"]
    '''
    result = [[]]
    for pool in pools:
        result = [x + [y] for x in result for y in pool]
    for prod in result:
        print prod
    
   #for x in itertools.product(*pools):
   '''
    for x in itertools.product(*pools):
       print x
       
