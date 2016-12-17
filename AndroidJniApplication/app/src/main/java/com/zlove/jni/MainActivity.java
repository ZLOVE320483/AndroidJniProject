package com.zlove.jni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import com.zlove.jni.ndk.JniUtils;
import com.zlove.jni.ndk.User;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    private TextView tvStringFromNative;
    private TextView tvIntSquareFromNative;
    private TextView tvFloatSquareFromNative;
    private TextView tvDoubleSquareFromNative;
    private TextView tvGreetings;
    private TextView tvTwoArrayFromNative;
    private TextView tvNativeSetName;
    private TextView tvNativeDoCallback;
    private TextView tvNativeGetUser;
    private TextView tvNativePrintUserInfo;
    private TextView tvNativeChangeUserInfo;
    private TextView tvNativeGetUserList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tvStringFromNative = (TextView) findViewById(R.id.string_from_native);
        tvIntSquareFromNative = (TextView) findViewById(R.id.int_square_from_native);
        tvFloatSquareFromNative = (TextView) findViewById(R.id.float_square_from_native);
        tvDoubleSquareFromNative = (TextView) findViewById(R.id.double_square_from_native);
        tvGreetings = (TextView) findViewById(R.id.greetings);
        tvTwoArrayFromNative = (TextView) findViewById(R.id.two_array_from_native);
        tvNativeSetName = (TextView) findViewById(R.id.native_set_name);
        tvNativeDoCallback = (TextView) findViewById(R.id.native_do_callback);
        tvNativeGetUser = (TextView) findViewById(R.id.native_get_user);
        tvNativePrintUserInfo = (TextView) findViewById(R.id.native_print_user_info);
        tvNativeChangeUserInfo = (TextView) findViewById(R.id.native_change_user_info);
        tvNativeGetUserList = (TextView) findViewById(R.id.native_get_user_list);

        JniUtils jniUtils = new JniUtils();

        tvStringFromNative.setText("String From Native --- " + jniUtils.getStringFromNative());

        tvIntSquareFromNative.setText("Int Square From Native --- " + jniUtils.square(3));
        tvFloatSquareFromNative.setText("Float Square From Native --- " + jniUtils.square(2.5f));
        tvDoubleSquareFromNative.setText("Double Square From Native --- " + jniUtils.square(5.25));

        tvGreetings.setText("native greetings --- " + jniUtils.greetings("ZLOVE"));

        StringBuilder builder = new StringBuilder();
        int[][] result = jniUtils.getTwoArray(5);
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                builder.append(result[i][j]);
                builder.append(",");
            }
            builder.append("\n");
        }
        tvTwoArrayFromNative.setText("Two Array From Native --- " + builder.toString());

        String source = "JniUtils source name:" + jniUtils.getName();
        jniUtils.nativeSetName();
        String res = ", JniUtils result name:" + jniUtils.getName();
        tvNativeSetName.setText("native set name --- " + source + res);

        jniUtils.doCallback();
        tvNativeDoCallback.setText("native do callback --- You can see it in log.");

        User user = jniUtils.nativeGetUser();
        tvNativeGetUser.setText("native get user --- age --- " + user.age + ", name --- " + user.name);

        User user1 = new User(27, "ZLOVE");
        jniUtils.printUserInfoAtNative(user1);
        tvNativePrintUserInfo.setText("native printUserInfoAtNative --- You can see it in log.");

        StringBuilder userBuilder = new StringBuilder("before native change---");
        User user2 = new User(27, "ZLOVE");
        userBuilder.append("age:");
        userBuilder.append(user2.age);
        userBuilder.append(",name:");
        userBuilder.append(user2.name);
        userBuilder.append("\n");
        User user3 = jniUtils.changeUserInfo(user2);
        userBuilder.append("after native change---");
        userBuilder.append(user3.age);
        userBuilder.append(",name:");
        userBuilder.append(user3.name);
        tvNativeChangeUserInfo.setText("native changeUserInfo:" + userBuilder.toString());

        StringBuilder builder1 = new StringBuilder("native get user list:");
        List<User> list = jniUtils.nativeGetUserList(5);
        for (int i = 0; i < list.size(); i++) {
            builder1.append(i);
            builder1.append("---age:");
            builder1.append(list.get(i).age);
            builder1.append(",name:");
            builder1.append(list.get(i).name);
            builder1.append("\n");
        }
        tvNativeGetUserList.setText("native getUserList:" + builder1.toString());

    }
}
