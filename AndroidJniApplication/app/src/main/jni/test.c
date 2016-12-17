//
// Created by 章磊 on 16/12/13.
//
#include "com_zlove_jni_ndk_JniUtils.h"
#include <stdio.h>

JNIEXPORT jstring JNICALL Java_com_zlove_jni_ndk_JniUtils_getStringFromNative
    (JNIEnv *env, jobject obj){
char *str="String from native C";
return (*env)->NewStringUTF(env, str);
}

JNIEXPORT jint JNICALL Java_com_zlove_jni_ndk_JniUtils_square__I
        (JNIEnv *env, jobject obj, jint num) {
    return num * num;
}

JNIEXPORT jfloat JNICALL Java_com_zlove_jni_ndk_JniUtils_square__F
        (JNIEnv *env, jobject obj, jfloat num) {
    return num * num;
}

JNIEXPORT jdouble JNICALL Java_com_zlove_jni_ndk_JniUtils_square__D
        (JNIEnv *env, jobject obj, jdouble num) {
    return num * num;
}

JNIEXPORT jstring JNICALL Java_com_zlove_jni_ndk_JniUtils_greetings
        (JNIEnv *env, jobject obj, jstring jstr) {
    const char *str = (*env)->GetStringUTFChars(env, jstr, NULL);
    if(str == NULL) {
        return NULL;
    }
    printf("%s\n", str);
    (*env)->ReleaseStringUTFChars(env, jstr, str);
    const char *tmpStr = "I am from Jni";
    jstring resStr = (*env)->NewStringUTF(env, tmpStr);
    return resStr;
}

JNIEXPORT jobjectArray JNICALL Java_com_zlove_jni_ndk_JniUtils_getTwoArray
        (JNIEnv *env, jobject obj, jint dimion) {
    if(dimion > 10) {
        return NULL;
    }
    jclass intArrayClass = (*env)->FindClass(env, "[I");
    jobjectArray objectIntArray = (*env)->NewObjectArray(env, dimion, intArrayClass, NULL);

    for (int i = 0; i < dimion; ++i) {
        jintArray intArray = (*env)->NewIntArray(env, dimion);
        jint temp[10];
        for (int j = 0; j < dimion; ++j) {
            temp[j] = i + j;
        }
        (*env)->SetIntArrayRegion(env, intArray, 0, dimion, temp);
        (*env)->SetObjectArrayElement(env, objectIntArray, i, intArray);
        (*env)->DeleteLocalRef(env, intArray);
    }

    return objectIntArray;
}

JNIEXPORT void JNICALL Java_com_zlove_jni_ndk_JniUtils_nativeSetName
        (JNIEnv *env, jobject obj) {
    jclass clazz = (*env)->GetObjectClass(env, obj);
    jfieldID nameFieldId = (*env)->GetFieldID(env, clazz, "name", "Ljava/lang/String;");
    if(nameFieldId == NULL) {
        printf("没有得到name的句柄Id \n");
    }

    jstring javaNameStr = (jstring) (*env)->GetObjectField(env, obj, nameFieldId);
    const char *c_javaName = (*env)->GetStringUTFChars(env, javaNameStr, NULL);
    printf("%s", c_javaName);
    printf("\n");
    (*env)->ReleaseStringUTFChars(env, javaNameStr, c_javaName);

    const char *c_ptr_name = "setByNative";
    jstring cName = (*env)->NewStringUTF(env, c_ptr_name);
    (*env)->SetObjectField(env, obj, nameFieldId, cName);
}

JNIEXPORT void JNICALL Java_com_zlove_jni_ndk_JniUtils_doCallback
        (JNIEnv *env, jobject obj) {
    jclass clazz = (*env)->GetObjectClass(env, obj);
    jmethodID callbackMethodID = (*env)->GetMethodID(env, clazz, "callbackForJni", "(Ljava/lang/String;)V");
    if(callbackMethodID == NULL) {
        printf("doCallback getMethodId is failed \n");
    }
    jstring navtive_desc = (*env)->NewStringUTF(env, "callback From Native");
    (*env)->CallVoidMethod(env, obj, callbackMethodID, navtive_desc);
}

JNIEXPORT jobject JNICALL Java_com_zlove_jni_ndk_JniUtils_nativeGetUser
        (JNIEnv *env, jobject obj) {
    jclass userClazz = (*env)->FindClass(env, "com/zlove/jni/ndk/User");
    jmethodID constructMID = (*env)->GetMethodID(env, userClazz, "<init>", "(ILjava/lang/String;)V");
    jstring name = (*env)->NewStringUTF(env, "ZLOVE From Native");
    jobject userObj = (*env)->NewObject(env, userClazz, constructMID, 11, name);
    return userObj;
}

JNIEXPORT void JNICALL Java_com_zlove_jni_ndk_JniUtils_printUserInfoAtNative
        (JNIEnv *env, jobject obj, jobject userObj) {
    jclass userClazz = (*env)->GetObjectClass(env, userObj);
    if(userClazz == NULL) {
        printf("GetObjectClass failed \n");
    }
    jfieldID ageFieldID = (*env)->GetFieldID(env, userClazz, "age", "I");
    jfieldID nameFileID = (*env)->GetFieldID(env, userClazz, "name", "Ljava/lang/String;");
    jint age = (*env)->GetIntField(env, userObj, ageFieldID);
    jstring name = (*env)->GetObjectField(env, userObj, nameFileID);
    const char *cname = (*env)->GetStringUTFChars(env, name, NULL);
    printf("user age --- %d, user name --- %s", age, cname);
    (*env)->ReleaseStringUTFChars(env, name, cname);
}

JNIEXPORT jobject JNICALL Java_com_zlove_jni_ndk_JniUtils_changeUserInfo
        (JNIEnv *env, jobject obj, jobject userObj) {
    jclass userClazz = (*env)->GetObjectClass(env, userObj);
    if(userClazz == NULL) {
        printf("GetObjectClass failed \n");
    }
    jfieldID ageFieldID = (*env)->GetFieldID(env, userClazz, "age", "I");
    jfieldID nameFileID = (*env)->GetFieldID(env, userClazz, "name", "Ljava/lang/String;");
    jint age = (*env)->GetIntField(env, userObj, ageFieldID);
    jstring name = (*env)->GetObjectField(env, userObj, nameFileID);
    const char *c_name = (*env)->GetStringUTFChars(env, name, NULL);
    printf("show user info age:%d name:%s", age, c_name);
    (*env)->ReleaseStringUTFChars(env, name, c_name);

    const char *c_ptr_name = "ZLiZH";
    jstring cName = (*env)->NewStringUTF(env, c_ptr_name);
    (*env)->SetObjectField(env, userObj, nameFileID, cName);
    (*env)->SetIntField(env, userObj, ageFieldID, 28);
    return userObj;
}

JNIEXPORT jobject JNICALL Java_com_zlove_jni_ndk_JniUtils_nativeGetUserList
        (JNIEnv *env, jobject obj, jint size) {
    jclass listClass = (*env)->FindClass(env, "java/util/ArrayList");
    if(listClass == NULL) {
        printf("listClass is NULL \n");
    }
    jmethodID  list_construct = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    jobject listObj = (*env)->NewObject(env, listClass, list_construct);
    jmethodID listAdd = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");
    jclass userClass = (*env)->FindClass(env, "com/zlove/jni/ndk/User");
    jmethodID constructMID = (*env)->GetMethodID(env, userClass, "<init>", "(ILjava/lang/String;)V");
    for (int i = 0; i < size; ++i) {
        jstring str = (*env)->NewStringUTF(env, "Native");
        jobject stu_obj = (*env)->NewObject(env, userClass, constructMID, i, str);
        (*env)->CallBooleanMethod(env, listObj, listAdd, stu_obj);
    }
    return listObj;
}

