__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "1.0"
__date__ = "2017-11-14"

import os, sys


def helper(semi_total, dump_path):
    print("\nReading file: " + dump_path)

    # Open a file from the path
    txt_file = open(dump_path, "r")

    linenum = 0
    for l in txt_file:
        linenum += 1
        if "bytes are allocated in total" not in l:
            continue
        else:
            temp = (l.lstrip()).split(" ", 1)
            semi_total += int(temp[0])
            print("Adding " + temp[0] + " bytes @ " + dump_path + ", line: " + str(linenum))

    return semi_total


def run():
    if len(sys.argv) < 2:
        print("[ERROR] PLEASE ADD FILES AS ARGUMENTS OR SIMPLY ADD *")
        exit()

    script = sys.argv[0]
    sys.argv[0] = 0
    if script in sys.argv:
        total_byte = 0
        files = [f for f in os.listdir('.') if os.path.isfile(f) and '~' not in f and script not in f]
        for num in range(0, len(files)):
            dump_path = files[num]
            total_byte += helper(total_byte, dump_path)

    else:
        total_byte = 0
        for num in range(1, len(sys.argv)):
            # Read the file path from the argument
            dump_path = sys.argv[num]
            total_byte += helper(total_byte, dump_path)

    total_byte = float(total_byte)
    print("\n\nTotal bytes used :\t" + str(total_byte) + " bytes" +
          "\nTotal kbytes used:\t" + str(total_byte / 1024) + " kb" +
          "\nTotal mbytes used:\t" + str(total_byte / 1024 / 1024) + " mb" +
          "\nTotal gbytes used:\t" + str(total_byte / 1024 / 1024 / 1024) + " gb")


run()
