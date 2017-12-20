

import operator

dump_path = "./tbsvr.out.7733646"
dump_file = open(dump_path, "r")
prev_line = ""
flag = False
most = {}
linenum = 0

for l in dump_file:
    #linenum = linenum + 1


    memory = 0

    if "Allocation size:" in l:
        flag = True


    if "Allocation size:" in l:
        # Remove the leading white space, then split the string by the first space
        #print(linenum)

        val = (l.lstrip()).split(" ")

        if len(val) < 3:
            flag = False
            continue

        val = val[2].rstrip()


        if len(val) > 4:
            flag = False
            continue
        if '\t' in val:
            flag = False
            continue
        if "ation" in val:
            flag = False
            continue
        if not val:
            flag = False
            continue
        if val == '\n' or val == ' ' or val == '\r':
            flag = False
            continue
        if not val.startswith('0x'):
            flag = False
            continue
        if len(val) == 2:
            flag = False
            continue


        val = int(val, 16)

        #val is the memory here
        memory = val
        flag = True
        #print(val)

    #print("flag: " + str(flag))

    if (not l.strip()) and (flag):
        address = prev_line.lstrip().split(" ", 1)[0]
        #print(address)
        flag = False

        if address in most:
            most[address] = most.get(address) + int(val)
        else:
            most[address] = 1 + int(val)

    prev_line = l



# Making a sorted representaton of the dictionary
sorted_most = sorted(most.items(), key=operator.itemgetter(1), reverse=True)

size = len(sorted_most)

for num in range(0, size):
    print(sorted_most[num])

