MAIN=main

all: $(MAIN).pdf

%.pdf: %.tex
	lualatex $<
	lualatex $<

clean:
	rm -f *.aux *.log *.toc
#	rm -f *.pdf

DIRS=datastructure dp flow geometry graph math misc other string
$(MAIN).pdf: $(DIRS:%=../%/*)
