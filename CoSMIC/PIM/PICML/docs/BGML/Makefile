# -*- Makefile -*-
#
# $Id$ 
#
LATEX = TEXINPUTS=$$TEXINPUTS:../../../tex:. pdflatex
BIBTEX = BIBINPUTS=$$BIBINPUTS:../../../bib:. bibtex

#LATEX = latex
#BIBTEX = bibtex

PAPER=BGML_Documentation_Guide

all:
	$(LATEX) $(PAPER)
	$(LATEX) $(PAPER)

clean:
	rm -rf $(PAPER).dvi $(PAPER).ps $(PAPER).pdf
	rm -rf *~ *.aux *.bbl *.blg *.dvi *.log
