#coding:utf-8
from scrapy.selector import Selector
from scrapy.selector import HtmlXPathSelector
 

html =''
import sys
f=open(sys.argv[1], 'r',encoding= 'utf-8')
out=open("out","w",encoding= 'utf-8')
html=f.read()
def geth1():
    sel = Selector(text=html)
    rawCont = sel.xpath("//h1") 
    #out.write(str(rawCont))
    for cont in rawCont:
      for nn in cont.xpath('text()').extract():
        #
        yield nn
    return
def getcon():
    sel = Selector(text=html)
    rawCont = sel.xpath("//pre") 
    for cont in rawCont:
      for nn in cont.xpath('text()').extract():
        yield nn
    return

g=getcon()
f=0
for x in geth1():
    out.write ("\n**************************************\n")
    try:
        if f>0:
            out.write (x)
            out.write(g.send(None))
        else:
            out.write(x)
            f=1
    except Exception as e:
        pass
  
