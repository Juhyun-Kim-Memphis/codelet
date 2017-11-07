#!/usr/bin/python

__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "1.0"
__date__ = "2017-11-07"

import os

#1. CHANGE THE PASSWORD WITH YOUR OWN PASSWORD
os.system('echo YOURPASSWORD | sudo -S false')
print('PAWA GRANTED!')

#2. SAVE THE FILE IN /usr/bin

#3. >chmod +x /usr/bin/pawa.py

#4. MAKE A SYMBOLIC LINK SO YOU DON'T HAVE TO TYPE THE FULL FILE NAME
#FOR EXAMPLE, 'PAWA' WOULD PROMPT THE FILE IN THE FOLLOWING COMMAND
#>sudo ln -s /usr/bin/pawa.py /usr/bin/PAWA