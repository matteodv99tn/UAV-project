options = -t

metadata = --metadata-file config.yaml


all:beamer

clean:
	rm presentation.pdf
	rm presentation.pptx

beamer:
	pandoc $(metadata) --variable=header-includes:"\input{defs.tex}" presentation.rst -o output.pdf -t beamer
	open output.pdf

powerpoint:
	pandoc $(metadata) presentation.rst -o presentation.pptx -s

reveal:
	