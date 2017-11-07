__author__ = "HYUNSOO PARK"
__email__ = "hyunsoo_park2@tmax.co.kr"
__version__ = "1.0"
__date__ = "2017-11-07"

import sys

if (len(sys.argv) < 2):
    print("ENTER THE PATH FOR THE FILE TO READ")

else:
    # Read the file path from the argument
    path = sys.argv[1]

    # Open a file from the path
    txt_file = open(path, "r")

    # Create two lists, respectively for the first column values and the second column values
    firstColumn = []
    secondColumn = []

    # Read each line from the txt file
    for l in txt_file:
        # Split the line string by one tab
        firstColumn.append(l.split('\t', 1)[0])
        # Remove the residual tabs and nextline
        secondColumn.append(l.split('\t', 1)[1].strip('\t').strip('\n'))

    out = ""

    header = '''<?xml version="1.0" encoding="utf-8" standalone="no"?>
        <!DOCTYPE html
          PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
        <html xmlns="http://www.w3.org/1999/xhtml"><head><meta xmlns="" http-equiv="Content-Type" content="text/html; charset=utf-8"/><title>WLock Type</title><link rel="stylesheet" href="stylesheet.css" type="text/css"/>
    
        <div class="itemizedlist"><ul type="disc"><li>
                    <p>Lock Type Information</p>
    
                    <div class="informaltable">
                      <table border="1"><colgroup><col width="140" align="left"><col></colgroup><thead><tr><th align="left">Lock Type</th><th align="left">Description</th></tr></thead><tbody>'''

    out += header

    for i in range(0, len(firstColumn)):
        out += '''<tr><td align="left">''' + firstColumn[i] + '''</td><td><p>''' + secondColumn[i] + '''</p></td></tr>'''

    footer = '''</tbody></table>
                </div>
              </li></ul></div>'''

    out += footer

    path = "T6Manual_Lock_Type.htm"
    out_file = open(path, "w+")

    out_file.write(out)

    print("DONE")