#!/usr/bin/python

__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "2.0"
__date__ = "2017-11-07"

import os, sys

#########################################################################
# HOW TO USE THIS SCRIPT
#
# 1. CHANGE THE "CHANGE_ME" WITH YOUR OWN PASSWORD
YOURPASSWORD = "CHANGE_ME"
#
# 2. SAVE THE FILE IN /usr/bin
#
# 3. >chmod +x /usr/bin/pawa.py
#
# 4. MAKE A SYMBOLIC LINK SO YOU DON'T HAVE TO TYPE THE FULL FILE NAME
# FOR EXAMPLE, 'PAWA' WOULD PROMPT THE FILE IN THE FOLLOWING COMMAND
# >sudo ln -s /usr/bin/pawa.py /usr/bin/PAWA

#########################################################################

# If no argument is given
if len(sys.argv) < 2:
    #
    os.system("sudo sed --in-place 's/env_reset/env_reset,timestamp_timeout=30/g' /etc/sudoers")
    commandString = "echo " + YOURPASSWORD + " | sudo -S false"
    os.system(commandString)
    print("PAWA GRANTED!")
    print("""
                 _..-...
              ,Y+  .:.:\_
             | |./'     ``-\.
             |,'`           `.   YOU NOW HAVE SUDO PAWA FOR 30 MINUTES
             |               `_   YOU NOW HAVE SUDO PAWA FOR 30 MINUTES
             |     ,-''-. ,-''':   YOU NOW HAVE SUDO PAWA FOR 30 MINUTES
             |    /      .'     :                                _
             | .\ |    o  |__o.,'                           _.-'  \`
            '|\|  \      /    `)                        ,..,'     ,'
             |`|  ' `..- .....<:                      ,'    `. ,-:
             ' ,-   _.-'        `.                 _,'       +'  |
              |`|  ,'            '.              ,'       - _/_,'-\`
               `.Y|   _,,.. ____./'           ,-'         /'|`'  _|
                 ||  | |  |  | |           _.-              `--+'
                 |-.  "|:.|..|-.    _,.. ,/'               ,..Y'
                 / `\.       ,-'  ,' /,,'               _,'
                .:_    -----'''|.:   |             _,Y''
               /  '`'';'.     /:  \  |        _,Y-'
               |      |  ' .  | `._| |     _,'
           _/-'';.. _ |     ` |   \   `.Y'i'
         ,'    ,'    '             |    i/'
      ,.'      /                   ..--'
      |       |                     \.
      : .     /                      ' .
     /'  `._ .'                         `.
     /     _''                            \.
    /     ./                               \.
   /      /                                 \.
  /      |                                   \.
 /     ,'|                                    |
    """)

elif str(argv[1]) == "-r":
    os.system("sudo sed --in-place 's/env_reset,timestamp_timeout=30/env_reset/g' /etc/sudoers")
    os.system("sudo -k")
    print('''
        _ _,---._ 
       ,-','       `-.___ 
      /-;'               `._ 
     /\/          ._   _,'o \ 
    ( /\       _,--'\,','"`. ) 
     |\      ,'o     \     //\ 
     |      \        /   ,--'""`-. 
     :       \_    _/ ,-'         `-._ 
      \        `--'  /                ) 
       `.  \`._    ,'     ________,',' 
         .--`     ,'  ,--` __\___,;' 
          \`.,-- ,' ,`_)--'  /`.,' 
           \( ;  | | )      (`-/ 
             `--'| |)       |-/     YOUR SUDO POWA HAS BEEN RESET
               | | |        | |      YOUR SUDO POWA HAS BEEN RESET
               | | |,.,-.   | |_      YOUR SUDO POWA HAS BEEN RESET
               | `./ /   )---`  ) 
              _|  /    ,',   ,-' 
             ,'|_(    /-<._,' |--, 
             |    `--'---.     \/ \ 
             |          / \    /\  \ 
           ,-^---._     |  \  /  \  \ 
        ,-'        \----'   \/    \--`. 
       /            \              \   \ 
       ''')

else:
    print("PLEASE ENTER A CORRECT ARGUMENT OR NO ARGUMENT AT ALL")




