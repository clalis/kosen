package com.nittc.test

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_contact_detail.*
import kotlinx.android.synthetic.main.contact_item.textViewName

class PresidentDetailActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_contact_detail)

        val contact = Contacts.list[intent.getIntExtra(EXTRA, 0)]
        textViewName.text = contact.name
        textViewStart.text = contact.start.toString()
        textViewEnd.text = contact.end.toString()
        textViewDetail.text = contact.detail
    }
}
