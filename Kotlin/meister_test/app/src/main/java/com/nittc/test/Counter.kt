package com.nittc.test

class Counter {
    companion object {
        private var count = 0
        var hex = false
    }

    fun plus() {
        count++
    }

    fun minus() {
        count--
    }

    fun reset() {
        count = 0
    }

    fun getCount(): String {
        return if (hex) Integer.toHexString(count) else count.toString()
    }

    fun setHex(b: Boolean) {
        hex = b
    }
}
