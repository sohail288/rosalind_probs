#!bin/python

"""
    Instead of copy pasting the data from rosalind
    I want Makefile to automatically create the data file by using
    a python script to get the data from rosalind.info

    Requirements:
        Must use barebones python
"""


import sys
import os
import urllib
import urlparse
from HTMLParser import HTMLParser

ROSALIND_ROOT = 'http://rosalind.info/problems/'

DATA_DIRECTORY = 'data'
FILE_PATH = lambda f: 'rosalind_' + f + '.txt'

class InputError(Exception): pass

class PreTagParser(HTMLParser):
    
    def __init__(self, *args, **kwargs):
        HTMLParser.__init__(self, *args, **kwargs)
        self.handling_pre = False
        self.pres = []
    
    def handle_starttag(self, tag, attrs):
        if tag == 'pre':
            self.handling_pre = True
    
    def handle_endtag(self, tag):
        if tag == 'pre':
            self.handling_pre = False

    def handle_data(self, data):
        if self.handling_pre:
            self.pres.append(data)

    def write_out_sample_data(self, f):
        sample_data = self.pres[0]
        
        with open(os.path.join(DATA_DIRECTORY, f), 'w') as fh:
            fh.write(sample_data) 

            






if __name__ == '__main__':
    if len(sys.argv) < 2:
        raise InputError("Did not supply args")

    problem = sys.argv[1]

    url = urlparse.urljoin(ROSALIND_ROOT, problem)
    

    print("Opening url: {}".format(url))
    req = urllib.urlopen(url)
    content = req.read()

    parser = PreTagParser()

    print("Parsing url content")
    parser.feed(content)

    print("Writing the file")
    parser.write_out_sample_data(FILE_PATH(problem))


