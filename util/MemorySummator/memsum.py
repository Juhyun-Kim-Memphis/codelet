__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "2.0"
__date__ = "2017-11-15"

import os, sys


# Helper method for run(): read & process the file
def helper(semi_total, dump_path):
    print("\nReading file: " + dump_path)

    # Open the file from the given path
    txt_file = open(dump_path, "r")

    # Declare and initialize (optional) a line number variable
    linenum = 0

    # Iteratring through the file in line by line
    for l in txt_file:
        linenum += 1
        if "bytes are allocated in total" not in l:
            continue
        else:
            # Remove the leading white space, then split the string by the first space
            val = (l.lstrip()).split(" ", 1)

            # Add the value before the first space
            semi_total += int(val[0])
            print("Adding " + val[0] + " bytes @ " + dump_path + ", line: " + str(linenum))

    return semi_total


# main() function of the script
def run():
    # If no argument has been given
    if len(sys.argv) < 2:
        print("[ERROR] PLEASE ADD FILES AS ARGUMENTS OR SIMPLY ADD *")
        exit()

    # Extract the first argument (this script) from the argument list
    this_script = sys.argv[0]

    # Remove this program from the given arguments
    sys.argv.pop(0);

    # Declare and initialize (optional) a total byte summed value
    total_byte = 0

    # If this script is still in the arguments, it means that the argument was given as '*'
    if this_script in sys.argv:
        # Get the list of files in the current directory, excluding this very script and other temp files denoted by '~'
        files = [f for f in os.listdir('.') if os.path.isfile(f) and '~' not in f and script not in f]
        for num in range(0, len(files)):
            dump_path = files[num]
            # Add up all dat fat bytes yo
            total_byte += helper(total_byte, dump_path)

    # If files are given from the arguments
    else:
        for num in range(0, len(sys.argv)):
            # Read the file path from the argument
            dump_path = sys.argv[num]
            # Add up all dat fat bytes yo
            total_byte += helper(total_byte, dump_path)

    # Casting int to float because fucking precision :^)
    total_byte = float(total_byte)
    print("\n\nTotal bytes used :\t" + str(total_byte) + " bytes" +
          "\nTotal kbytes used:\t" + str(total_byte / 1024) + " kb" +
          "\nTotal mbytes used:\t" + str(total_byte / 1024 / 1024) + " mb" +
          "\nTotal gbytes used:\t" + str(total_byte / 1024 / 1024 / 1024) + " gb")


# Running the damn script
run()
