import pathutil
def get_file_name(full_fname):
    fname = pathutil.get_path(full_fname)
    return fname
print('[(my ' + __name__ +' module)]'+ ' in '+ __file__)
fullname = __file__
filename = get_file_name(fullname)
print(f'my file name: {filename}')