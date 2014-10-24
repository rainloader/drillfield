#!/bin/bash
JNILIB_PATH=/home/test/drill/drill_jni/
java -Djava.library.path=$JNILIB_PATH jni.JNIMain
