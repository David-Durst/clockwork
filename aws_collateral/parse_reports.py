#!/usr/bin/env python3

import json
import os
import sys 

import os

n = len(sys.argv) 
print("Total arguments passed:", n) 
assert(n == 2)

app = sys.argv[1]

print('app =', app)
import glob

os.system('rm -rf our_code')
os.system('rm -rf soda_code')
os.system('../aws_collateral/get_reports.sh {0}'.format(app))
directory = './'
for filename in glob.iglob(directory + '**/*', recursive=True):
  if filename.endswith("kernel_util_routed.rpt"):
    print('File:', filename)
    util = open(filename, 'r').read()
    latex_table = util.replace("%", "\\%")
    latex_table = latex_table.replace("|", "&")
    latex_table = latex_table.replace("[ ", "[")
    latex_table = latex_table.replace("_", "u")
    print(latex_table)
    # break

