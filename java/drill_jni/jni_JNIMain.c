#include "jni_JNIMain.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_jni_JNIMain_printJNIMessage(JNIEnv *env, jobject obj)
{
	printf("JNI Message\n");
}

JNIEXPORT void JNICALL Java_jni_JNIMain_printJNIString(JNIEnv *env, jobject obj, jstring string)
{
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	printf("JNI String : %s\n", str);
}




