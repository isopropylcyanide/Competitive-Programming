import re
from HTMLParser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print tag
        if attrs!=[]:
        	for att,val in attrs:
        		print '->',att,'>',val
   

N=input()

Parser=MyHTMLParser()
while N:
	Parser.feed(raw_input())
	N-=1

"""
13
#BED
{
    color: #FfFdF8; background-color:#aef;
    font-size: 123px;
    #######898989#9898s9676#ajkjk
    #,#ichbineinhash #unddu#1100011#110010
    background: -webkit-linear-gradient(top, #f9f9f9, #fff);
}
#Cab
{
    background-color: #ABC;
    border: 2px dashed #fff;
}
"""