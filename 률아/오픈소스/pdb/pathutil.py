import os
def get_path(fn):
    print('[(my ' + __name__ +' module)]'+ ' in '+ __file__) 
    breakpoint() # import pdb; pdb.set_trace()
    head, tail = os.path.split(fn)
    for char in head: 
        pass   # test          
    return tail
