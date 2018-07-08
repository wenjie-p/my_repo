#open a file without knowing what encoding the file is taken
#
import codecs




encode = ["utf8", "gbk", "gb2312"]

filename = ""
content = ""
for code in encode:
    f = codecs.open(filename, "r", encoding = code)
    try:
        content = f.readlines()
    except:
        f.close()
        continue
    f.close()
    if content:
        break
    else:
        continue
