package com.my.ndkstaticdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.my.ndkstaticdemo.util.MyUtil;

public class MainActivity extends AppCompatActivity {

    private TextView tv;
    private MyUtil myUtil;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tv = findViewById(R.id.textViewId);
        myUtil = new MyUtil();
    }

    public void click2(View view) {
        String str = myUtil.stringFromJNI2();
        tv.setText(str);
    }

    public void click3(View view) {
        String str = myUtil.handleString("param string");
        tv.setText(str);
    }

}
