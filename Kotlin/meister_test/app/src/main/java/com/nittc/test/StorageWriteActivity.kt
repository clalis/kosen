package com.nittc.test

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_storage_write.*

internal const val FILENAME = "myFile.txt"

class StorageWriteActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_storage_write)
        buttonSave.setOnClickListener {
            openFileOutput(FILENAME, Context.MODE_APPEND).use {
                it.write("${editTextFile.text}\n".toByteArray())
            }
            textViewFileSucceeded.text=getString(R.string.files_saved)
        }
        buttonRead.setOnClickListener {
            val intent = Intent(this, StorageReadActivity::class.java)
            startActivity(intent)
        }
    }
}
