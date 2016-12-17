package com.zlove.jni.ndk;

import android.util.Log;

import java.util.ArrayList;

/**
 * Created by ZLOVE on 16/12/13.
 */
public class JniUtils {
    private String name = "Java";

    public void callbackForJni(String fromNative) {
        Log.d("ZLiZH", "callbackForJni---jni string from native" + fromNative);
    }

    static {
        System.loadLibrary("hello");
    }

    public native String getStringFromNative();
    public native int square(int num);
    public native float square(float num);
    public native double square(double num);
    public native String greetings(String username);
    public native int[][] getTwoArray(int dimon);
    public native void nativeSetName();
    public native void doCallback();
    public native User nativeGetUser();
    public native void printUserInfoAtNative(User user);
    public native User changeUserInfo(User user);
    public native ArrayList<User> nativeGetUserList(int num);

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
