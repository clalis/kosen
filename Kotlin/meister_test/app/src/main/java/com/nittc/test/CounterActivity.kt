package com.nittc.test

import android.os.Bundle
import android.widget.RadioGroup
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_counter.*

class CounterActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_counter)

        val counter = Counter()
        updateCounterTextView(counter)

        val decimalGroup: RadioGroup = findViewById(R.id.decimalRadioGroup)
        decimalGroup.setOnCheckedChangeListener { _, checkedId: Int ->
            when (checkedId) {
                R.id.decRadioButton -> counter.setHex(false)
                R.id.hexRadioButton -> counter.setHex(true)
                else -> throw IllegalArgumentException("not supported")
            }
            updateCounterTextView(counter)
        }

        plusButton.setOnClickListener {
            counter.plus()
            updateCounterTextView(counter)
        }
        minusButton.setOnClickListener {
            counter.minus()
            updateCounterTextView(counter)
        }
        resetButton.setOnClickListener {
            counter.reset()
            updateCounterTextView(counter)
        }
    }

    private fun updateCounterTextView(counter: Counter) {
        counterTextView.text = counter.getCount()
    }
}
