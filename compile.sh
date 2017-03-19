#!/bin/bash
# Copyright © 2017 Martin Ueding <dev@martin-ueding.de>

# Compiles the LaTeX document with the fanciest wrapper available.

talk=talk.tex

if type latexrun &> /dev/null; then
    latexrun --latex-cmd lualatex "$talk"
elif type latexmk &> /dev/null; then
    latexmk -pdf -lualatex "$talk"
else
    lualatex --halt-on-error  "$talk"
fi
