__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "3.0"
__date__ = "2017-11-15"

import os, sys, operator


# Helper method for run(): read & process the file
def helper(semi_total, dump_path, most):
    print("\nReading file: " + dump_path)

    # Open the file from the given path
    txt_file = open(dump_path, "r")

    # Declare and initialize (optional) a line number variable
    linenum = 0

    # Iteratring through the file in line by line
    for l in txt_file:
        linenum += 1
        if "bytes are allocated in total" in l:
            # Remove the leading white space, then split the string by the first space
            val = (l.lstrip()).split(" ", 1)

            # Add the value before the first space
            semi_total += int(val[0])
            print("Adding " + val[0] + " bytes @ " + dump_path + ", line: " + str(linenum))

        elif " (size " in l and "free" not in l:

            key = l.lstrip().split()[8]
            val = l.lstrip().split()[7]
            if key in most:
                most[key] = most.get(key) + int(val[0: len(val) - 1])
            else:
                most[key] = int(val[0: len(val) - 1])

        else:
            continue

    return semi_total


# main() function of the script
def run():
    # If no argument has been given
    if len(sys.argv) < 2:
        print("[ERROR] PLEASE TRY -h OR -help TO USE THIS SCRIPT")
        exit()

    if len(sys.argv) == 2 and (sys.argv[1] == '-h' or sys.argv[1] == '-help'):
        print("""
              ######################################################################################
              #  Recommend using python3 to run this script.                                       #
              #                                                                                    #          
              #$ python3 memsum.py *                                                               #
              #---> Adds up the total memory allocated in all of the dump files in this directory  #
              #---> Also prints out the code that held the most memory by default                  #
              #                                                                                    #
              #$ python3 memsum.py dump_file1 dump_file2 ...                                       #
              #---> Adds up the total memory allocated in the given dump files                     #
              #---> Also prints out the code that held the most memory by default                  #
              #                                                                                    #
              #$ python3 memsum.py * -top 10                                                       #
              #---> Adding a \"-top #\" keyword shows the top # codes that held the most memories    #
              #---> Available up to 10. If the desired number of codes is greater than             #
              #---> the number of codes found, the script simply prints out what it has            # 
              ######################################################################################
              """)
        sys.exit()

    top = 1
    if "-top" in sys.argv:
        try:
            top = int(sys.argv[sys.argv.index("-top") + 1])
        except ValueError:
            print("[ERROR]YOU MUST ENTER AN INTEGER (2~10) AFTER '-top' ARGUMENT")
            exit()
        if top < 2 or top > 10:
            print("[ERROR]YOU MUST ENTER AN INTEGER (2~10) AFTER '-top' ARGUMENT")

        #Removing the top argument and its value from the arguments
        del sys.argv[sys.argv.index("-top") + 1]
        del sys.argv[sys.argv.index("-top")]

    # Extract the first argument (this script) from the argument list
    this_script = sys.argv[0]

    # Remove this program from the given arguments
    sys.argv.pop(0);

    # Declare and initialize (optional) a total byte summed value
    total_byte = 0

    # If this script is still in the arguments, it means that the argument was given as '*'
    if this_script in sys.argv:
        # Get the list of files in the current directory, excluding this very script and other temp files denoted by '~'
        files = [f for f in os.listdir('.') if os.path.isfile(f) and '~' not in f and this_script not in f]
    # If files are given from the arguments
    else:
        files = [f for f in sys.argv]

    most = {}
    for num in range(0, len(files)):
        dump_path = files[num]
        # Add up all dat fat bytes yo
        total_byte += helper(total_byte, dump_path, most)

    # Making a sorted representaton of the dictionary
    sorted_most = sorted(most.items(), key=operator.itemgetter(1), reverse=True)
    print("\n---List of codes sorted by most memory usage---\n")
    for num in range(0, top):
        print(
            str(num + 1) + ": " + sorted_most[num][0] + " is using " + str(sorted_most[num][1]) + " bytes" + " (="
            + str(round((float(sorted_most[num][1])/1024), 2)) + "kb = "
            + str(round((float(sorted_most[num][1])/1024/1024), 2)) + "mb = "
            + str(round((float(sorted_most[num][1]) / 1024 / 1024 / 1024), 2)) + "gb)")

    # Casting int to float because fucking precision :^)
    total_byte = float(total_byte)
    print("\n\nTotal bytes used :\t" + str(total_byte) + " bytes" +
          "\nTotal kbytes used:\t" + str(total_byte / 1024) + " kb" +
          "\nTotal mbytes used:\t" + str(total_byte / 1024 / 1024) + " mb" +
          "\nTotal gbytes used:\t" + str(total_byte / 1024 / 1024 / 1024) + " gb")


# Running the damn script
run()
