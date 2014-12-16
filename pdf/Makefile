MAIN=main

all: $(MAIN).pdf

%.pdf: %.tex
	platex $*
	platex $*
	dvipdfmx $*

clean:
	rm -f *.aux *.log *.toc
#	rm -f *.dvi *.pdf

DIRS=datastructure dp flow geometry graph math misc string
$(MAIN).pdf: $(DIRS:%=../%/*)
