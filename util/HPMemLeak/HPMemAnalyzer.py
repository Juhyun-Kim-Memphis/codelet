__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "1.0"
__date__ = "2017-12-14"

dump_path = "./sss"
dump_file = open(dump_path, "r")
target_pid = '1411'
cur_mem = 0
cum_mem = 0
codelines = []
linenum = 0

for l in dump_file:



    # skip blank line
    if not l.strip():
        continue

    # code line
    if 'root' not in l:
        code = str(l.split()[2].split('/')[7]) + ": " + str(l.split()[0])
        codelines.append(code)

    # memory right now
    if l.startswith(target_pid) and 'tbcm_guard' not in l:
        cur_mem = l.strip().split()[9]
        cur_mem = int(cur_mem)
        if cur_mem > cum_mem and cum_mem != 0:
            mem_added = cur_mem - cum_mem
            print(codelines)
            print(" added " + str(mem_added) + " !!")

        elif cur_mem < cum_mem:
            mem_freed = cum_mem - cur_mem
            print(codelines)
            print(" freed " + str(mem_added) + " !!")

        codelines.clear()
        cum_mem = cur_mem



#line > then memory