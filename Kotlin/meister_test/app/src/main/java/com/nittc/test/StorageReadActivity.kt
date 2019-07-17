package com.nittc.test

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_storage_write.*
import kotlinx.android.synthetic.main.activity_storage_read.*

class StorageReadActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_storage_read)
        textViewBody.text=openFileInput(FILENAME)?.bufferedReader().use {
            it?.readText()?:getString(R.string.file_faild)
        }
        buttonWrite.setOnClickListener {
            val intent = Intent(this, StorageWriteActivity::class.java)
            startActivity(intent)
        }
    }
}
