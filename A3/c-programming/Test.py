#!/usr/bin/python

import sys

while(True):
	try:
	    read_in = raw_input()
	except:
	    print >> sys.stderr,"Exception, exiting..."
	    sys.exit()

	print >> sys.stdout, "Python read in at command line: " + read_in
	sys.stdout.flush()
