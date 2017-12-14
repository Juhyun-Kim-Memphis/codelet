__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "1.0"
__date__ = "2017-12-14"

from __future__ import print_function

# Libraries we need
import pyxhook
import time
from pykeyboard import PyKeyboard

# This function is called every time a key is presssed
def kbevent(event):
    global running
    # print key info
    #print(event)

    test.append(event.Ascii)
    if len(test) > 3:
        test.pop(0)


    if sorted(test) == sorted(commence):

        test.clear()
        print("starting the script")

        # Remove 111
        k.press_key(k.enter_key)
        k.release_key(k.enter_key)
        for num in range(0, 10000):
            #LOGIC COMES HERE
            memTrack()

        print("terminating the script")

def memTrack():
    k.type_string("ps -elf | grep tbcm >>.gdb_output")
    k.press_key(k.enter_key)
    k.release_key(k.enter_key)
    time.sleep(0.1)

    # Move to gdb tab
    k.press_keys([k.control_l_key, k.tab_key])
    time.sleep(0.1)

    k.press_key('n')
    k.release_key('n')
    time.sleep(0.1)
    k.press_key(k.enter_key)
    k.release_key(k.enter_key)
    time.sleep(0.1)

    # Go back to ps -ef tab
    k.press_keys([k.control_l_key, k.tab_key])
    time.sleep(0.1)

# Lists to track global keyboard input
commence = [49, 49, 49]
terminate = [57, 57, 57]
test = []

# Keyboard emulator
k = PyKeyboard()

# Create hookmanager
hookman = pyxhook.HookManager()
# Define our callback to fire when a key is pressed down
hookman.KeyDown = kbevent
# Hook the keyboard
hookman.HookKeyboard()
# Start our listener
hookman.start()

# Create a loop to keep the application running
running = True
while running:
    time.sleep(0.1)

# Close the listener when we are done
hookman.cancel()