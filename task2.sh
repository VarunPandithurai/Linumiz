#! /bin/sh
#!/bin/bash
if [[ $# -eq 0 ]] ; then
    echo 'error : Please Provide Path'
    exit 0
fi
cd $1
ls -l -F | grep '*$'

