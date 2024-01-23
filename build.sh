#! /usr/bin/env bash

function index()
{
    make -C ./bin/ -f ../makefile

    make -C ./bin/ -f ../makefile clean
}

index