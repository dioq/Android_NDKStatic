package com.my.ndkstatic.util;

public class MyUtil {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI2();

    public native String handleString(String str);

}
