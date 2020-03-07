#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_my_ndkstatic_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_my_ndkstatic_MainActivity_stringFromJNI2(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI2()
    std::string newvalue = "这是我新建的方法";
    return env->NewStringUTF(newvalue.c_str());
}

std::string jstring2str(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    std::string stemp(rtn);
    free(rtn);
    return stemp;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_my_ndkstatic_MainActivity_handleString(JNIEnv *env, jobject thiz, jstring str) {
    // TODO: implement handleString()
    std::string str1 = "基础值:";

    //将 jstring 转换成C++ 的 string
    std::string strChange = jstring2str(env, str);

    str1.append(strChange);
    return env->NewStringUTF(str1.c_str());
}
