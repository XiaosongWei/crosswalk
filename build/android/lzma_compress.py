#!/usr/bin/env python
#
# Copyright (c) 2015 Intel Corporation. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# pylint: disable=F0401

import optparse
import os
import shutil
import sys
import subprocess

def main(argv):
  option_parser = optparse.OptionParser()
  option_parser.add_option('-t', dest='target',
                           help='Target directory for compressed files',
                           type='string')
  option_parser.add_option('-f', dest='filename',
                           help='The filename to be comprossed from source to target',
                           type='string')

  options, _ = option_parser.parse_args(argv)

  if not os.path.exists(options.target):
    os.makedirs(options.target)

  print ('Copying file %s from %s' %(os.path.basename(options.filename), os.path.dirname(options.filename)))
  shutil.copy(options.filename, options.target)

  file_to_compress = os.path.join(options.target, os.path.basename(options.filename))
  print ('Compressing file %s to %s' %(os.path.basename(options.filename), options.target))
  subprocess.check_call(['lzma', '-f', file_to_compress])
  print ('Compress %s done' %(os.path.basename(options.filename)))

if __name__ == '__main__':
  sys.exit(main(sys.argv))
