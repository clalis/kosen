package com.nittc.test

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

val tag = "MY_APP"

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        btnGreet.setOnClickListener {
            Log.i(tag, "User pressed button $it")
            textHello.text = getString(R.string.goodbye)
            this.finish()
        }
    }
}
