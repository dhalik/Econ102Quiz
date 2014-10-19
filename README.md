Quizzer
===========

Quizzer

A small CLI program that asks multiple choice questions specified in a external XML file.

##Quick Start

Navigate to cloned directory and run:

    make questionrepo.h
    make

On a unix environment the program can be run by calling

    ./Quizzer


##Adding custom QuestionSet

To add a custom question set, use the following XML template to create your question file:

    <testrepo>
        <chapter num="1">
            <question>
                <q>Which of the following is a functional programming lanaguge?<q>
                <a>C++</a>
                <b>Java</b>
                <c>Scheme</c>
                <d>C</d>
                <ans>C</ans>
            </question>
            <question>
                <q>Which of the following is not a functional programming lanaguge?<q>
                <a>C++</a>
                <b>Haskell</b>
                <c>Scheme</c>
                <d>ML</d>
                <ans>C</ans>
            </question>
        </chapter>
    </testrepo>

Then, run:

    python encode.py QuestionBank/"customfile.xml"
    make

The compiled program will be a standalone that runs with the specified questionset.


##Requirements

g++, python
