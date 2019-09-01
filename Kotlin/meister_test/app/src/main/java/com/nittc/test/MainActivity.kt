package com.nittc.test

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

const val tag: String = "MY_APP"

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        btnGreet.setOnClickListener {
            Log.i(tag, "User pressed button $it")
            textHello.text = getString(R.string.goodbye)
            this.finish()
        }
        btnCounter.setOnClickListener {
            Log.i(getString(R.string.counter_view), "User pressed button $it")
            val intent = Intent(this, CounterActivity::class.java)
            startActivity(intent)
        }
        btnRecycleView.setOnClickListener {
            Log.i(getString(R.string.recycle_view), "User pressed button $it")
            val intent = Intent(this, RecyclerViewActivity::class.java)
            startActivity(intent)
        }
        btnFilesView.setOnClickListener {
            Log.i(getString(R.string.files_view), "User pressed button $it")
            val intent = Intent(this, StorageWriteActivity::class.java)
            startActivity(intent)
        }
    }
}
