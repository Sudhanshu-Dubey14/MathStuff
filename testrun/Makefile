
CPP_FILES = $(wildcard *.cpp)
C_FILES = $(wildcard *.c)
COBJ_FILES = $(patsubst %.c, %.o , $(C_FILES))
CPPOBJ_FILES = $(patsubst %.cpp, %.o , $(CPP_FILES))
MD_FILES = $(patsubst %.o, %.md, $(COBJ_FILES) $(CPPOBJ_FILES))
HTML_FILES = $(patsubst %.md, %.html, $(MD_FILES))
PDF_FILES = $(patsubst %.md, %.pdf, $(MD_FILES))

#traditional all

.PHONY : all
all : pdfs htmls
#pdf from md

.PHONY : pdfs
pdfs : $(PDF_FILES)

%.pdf : %.md
	pandoc -s -o $@ $<

#html from md

.PHONY : htmls
htmls : $(HTML_FILES)

%.html : %.md
	pandoc -s -o $@ $<

#md files from objects

.PHONY : mds
mds : $(MD_FILES)

%.md : %.o
	./$<

#building object files from program files

.PHONY : objects
objects : $(COBJ_FILES) $(CPPOBJ_FILES)

%.o : %.cpp
	g++ -o $@ $<

%.o : %.c
	gcc -o $@ $<

#clean : Destroy auto-generated files

.PHONY : clean
clean : 
	rm *.o *.md *.html *.pdf

